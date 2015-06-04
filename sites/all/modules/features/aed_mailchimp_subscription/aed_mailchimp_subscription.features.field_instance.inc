<?php
/**
 * @file
 * aed_mailchimp_subscription.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function aed_mailchimp_subscription_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_mailchimp_subscription'
  $field_instances['user-user-field_mailchimp_subscription'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'subscribe' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'mailchimp_lists',
        'settings' => array(
          'interest_groups' => array(),
          'show_interest_groups' => FALSE,
        ),
        'type' => 'mailchimp_lists_subscribe_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_mailchimp_subscription',
    'label' => 'Adhesión a la newsletter de socios',
    'required' => 0,
    'settings' => array(
      'interest_groups_title' => 'Interest Groups',
      'mergefields' => array(
        'EMAIL' => 'mail',
        'FNAME' => 'profile_socio:field_nombre',
        'LNAME' => 'profile_socio:field_apellidos',
      ),
      'options' => array(
        'interest_groups' => array(),
        'subscribe' => FALSE,
      ),
      'show_interest_groups' => 0,
      'unsubscribe_on_delete' => 1,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'mailchimp_lists',
      'settings' => array(),
      'type' => 'mailchimp_lists_select',
      'weight' => 12,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Adhesión a la newsletter de socios');

  return $field_instances;
}
