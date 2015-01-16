<?php
/**
 * @file
 * User membership data plugin definition.
 */

$plugin = array(
  'title' => t('AED user membership data'),
  'description' => t('Render the membership data for a user in AED'),
  'required context' => new ctools_context_required(t('User'), 'user'),
  'category' => t('AED'),
  'render callback' => 'user_membership_data_content_type_render',
  'edit form' => 'user_membership_data_content_type_config_form'
);

function user_membership_data_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  // Get $user object from $context and other neccessary data:
  $user_roles = $context->data->roles;
  $member_roles = isset($conf['member_roles']) ? $conf['member_roles'] : array();
  $user_member_roles = array_intersect(array_keys($user_roles), $member_roles);

  // Get the most recent user role that match with $conf member_roles:
  if (!empty($user_member_roles)) {
    $user_membership_data = isset($user_roles[max($user_member_roles)]) ?
      $user_roles[max($user_member_roles)] : '';
  }

  // Render the content
  $block->content = array(
    '#theme' => 'aed_user_membership_data',
    '#current_member_status' => isset($user_membership_data) ?
      $user_membership_data : t('No member'),
  );

  return $block;
}

function user_membership_data_content_type_config_form($form, &$form_state) {
  // Members subscription roles.
  $default_member_roles = isset($form_state['conf']['member_roles']) ?
    $form_state['conf']['member_roles'] : array();
  $form['member_roles'] = array(
    '#type' => 'select',
    '#title' => t('Select which roles are available for members'),
    '#description' => t('Select which roles are used for category members AED subscription'),
    '#multiple' => TRUE,
    '#options' => user_roles(TRUE),
    '#default_value' => $default_member_roles,
  );

  return $form;
}

function user_membership_data_content_type_config_form_submit($form, &$form_state) {
  // Store the selected member roles.
  $form_state['conf']['member_roles'] = $form_state['values']['member_roles'];
}