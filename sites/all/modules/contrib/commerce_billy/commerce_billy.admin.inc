<?php

/**
 * @file
 * Settings for Commerce Billy.
 */

/**
 * Admin settings form for invoice generation.
 */
function commerce_billy_admin_form($form, &$form_state) {
  $invoice_nr_options = array(
    COMMERCE_BILLY_INVOICE_METHOD_INFINITE => t('Infinite (one single number, that is never reset, and incremented at each invoice generation)'),
    COMMERCE_BILLY_INVOICE_METHOD_YEARLY => t('Reset every year, with an id incremented at each invoice generation (@invoice_number)', array('@invoice_number' => date('Y') . '-[id]')),
    COMMERCE_BILLY_INVOICE_METHOD_MONTHLY => t('Reset every month, with an id incremented at each invoice generation (@invoice_number)', array('@invoice_number' => date('Y-m') . '-[id]')),
  );
  $form['commerce_billy_invoice_nr_method'] = array(
    '#type' => 'radios',
    '#title' => t('Invoice number generation method'),
    '#default_value' => variable_get('commerce_billy_invoice_nr_method', COMMERCE_BILLY_INVOICE_METHOD_YEARLY),
    '#options' => $invoice_nr_options,
  );
  $form['commerce_billy_invoice_nr_pattern'] = array(
    '#type' => 'textfield',
    '#title' => t('Pattern for invoice number'),
    '#default_value' => variable_get('commerce_billy_invoice_nr_pattern', '[invoice_nr]'),
    '#description' => t('In addition to the generation method, a pattern for the invoice number can be set, e.g. to pre- or suffix the calculated number. The token "[invoice_nr]" is replaced with the generated number and *must* be included in the pattern.'),
  );
  $form['commerce_billy_auto_invoice'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatically invoice orders on checkout completion.'),
    '#default_value' => variable_get('commerce_billy_auto_invoice', FALSE),
    '#description' => t('If set, the order state is set to \'invoiced\' on order completion and an invoice number is generated. Otherwise an order has to be manually moved to the state "invoiced" to generated the invoice number. Changing this value requires a cache-clear.'),
  );

  return system_settings_form($form);
}
