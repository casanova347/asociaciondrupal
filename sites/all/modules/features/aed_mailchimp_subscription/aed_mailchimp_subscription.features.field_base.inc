<?php
/**
 * @file
 * aed_mailchimp_subscription.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function aed_mailchimp_subscription_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_mailchimp_subscription'
  $field_bases['field_mailchimp_subscription'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_mailchimp_subscription',
    'field_permissions' => array(
      'type' => 1,
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'mailchimp_lists',
    'settings' => array(
      'double_opt_in' => 0,
      'mc_list_id' => variable_get('aed_mailchimp_subscription_mc_list_id'),
      'profile2_private' => FALSE,
      'send_welcome' => 0,
    ),
    'translatable' => 0,
    'type' => 'mailchimp_lists_subscription',
  );

  return $field_bases;
}
