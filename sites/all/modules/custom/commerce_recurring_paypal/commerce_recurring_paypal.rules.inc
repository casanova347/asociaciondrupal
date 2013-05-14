<?php

/**
 * @file
 * Provides Rules integration
 */

/**
 * Implements hook_rules_action_info().
 */
function commerce_recurring_paypal_rules_action_info() {
  $actions = array();

  // Stores billing agreement.
  $actions['commerce_recurring_paypal_process_billing_agrement'] = array(
    'label' => t('Process PayPal billing agrement'),
    'group' => t('Commerce recurring payment gateways'),
    'parameter' => array(
      'order' => array(
        'type' => 'commerce_order',
        'label' => t('Order'),
      ),
      'commerce_recurring' => array(
        'type' => 'commerce_recurring',
        'label' => t('Commerce recurring entity'),
      ),
      'number_of_orders' => array(
        'type' => 'decimal',
        'label' => t('Number of orders'),
        'description' => t('Number of orders associated to the recurring entity so reacting to the first or nth one is easier.'),
        'default value' => 0,
      ),
    ),
    'callbacks' => array(
      'execute' => 'commerce_recurring_paypal_process_billing_agrement',
    ),
  );

  // Charges the order.
  $actions['commerce_recurring_paypal_charge'] = array(
    'label' => t('Charge the order with a paypal subscription'),
    'group' => t('Commerce recurring payment gateways'),
    'parameter' => array(
      'order' => array(
        'type' => 'commerce_order',
        'label' => t('Order'),
      ),
      'commerce_recurring' => array(
        'type' => 'commerce_recurring',
        'label' => t('Commerce recurring entity'),
      ),
    ),
    'callbacks' => array(
      'execute' => 'commerce_recurring_paypal_rules_action_order_charge',
    ),
  );

  return $actions;
}

/**
 * Rules action callback for commerce_recurring_paypal_process_billing_agrement.
 */
function commerce_recurring_paypal_process_billing_agrement($order, $commerce_recurring, $number_of_orders) {
  $bill_agr = @$order->data['commerce_recurring_paypal_billing_agreement'];
  $billing_agreement = isset($bill_agr) ? $bill_agr : FALSE;

  if ($billing_agreement) {
    $recurring_wrapper = entity_metadata_wrapper('commerce_recurring', $commerce_recurring);
    $recurring_wrapper->commerce_recurring_paypal_auth_id->set($billing_agreement);
  }
}

/**
 * Rules action callback for commerce_recurring_paypal_charge.
 */
function commerce_recurring_paypal_rules_action_order_charge($order, $commerce_recurring) {

  $payment_method = commerce_payment_method_instance_load('commerce_recurring_paypal|commerce_payment_commerce_recurring_paypal');
  $recurring_wrapper = entity_metadata_wrapper('commerce_recurring', $commerce_recurring);
  $billing_agreement = $recurring_wrapper->commerce_recurring_paypal_auth_id->value();

  $feedback = commerce_recurring_paypal_response_to_ipn(commerce_recurring_paypal_charge($order, $billing_agreement, $payment_method));

  if ($feedback["payment_status"] == "Success" || $feedback["payment_status"] == "Completed") {
    commerce_recurring_paypal_do_transaction($order, $payment_method, $feedback, $billing_agreement);
    commerce_order_status_update($order, "completed");
  }
}
