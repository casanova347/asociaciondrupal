<?php

/**
 * Implements hook_form_FORM_ID_alter() for the profile2 type form..
 */
function profiles2_one_page_form_profile2_type_form_alter(&$form, &$form_state) {
  $type = $form_state['profile2_type'];
  $form['data']['use_one_page'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show this profile as part of user account form'),
//    '#description' => t('Beware, you can not enable this option when "Provide a separate page for editing profiles." is enabled'),
    '#default_value' => !empty($type->is_new) || !empty($type->data['use_one_page']),
  );
  $form['data']['#tree'] = TRUE;
}

/**
 * Implements hook_profile2_type_insert().
 */
function profiles2_one_page_profile2_type_insert(ProfileType $type) {
  // Do not directly issue menu rebuilds here to avoid potentially multiple
  // rebuilds. Instead, let menu_get_item() issue the rebuild on the next page.
  if (!empty($type->data['use_one_page'])) {
    variable_set('menu_rebuild_needed', TRUE);
  }
}

/**
 * Implements hook_profile2_type_update().
 */
function profile2_one_page_profile2_type_update(ProfileType $type) {
  // Rebuild the menu if use_one_page or the type name has been changed.
  // @see profile2_page_profile2_type_insert()
  if (empty($type->data['use_one_page']) != empty($type->original->data['use_one_page']) || ($type->data['use_one_page'] && $type->type != $type->original->type)) {
    variable_set('menu_rebuild_needed', TRUE);
  }
}

/**
 * Implements hook_profile2_type_delete()
 */
function profile2_one_page_profile2_type_delete($type) {
  // Do not directly issue menu rebuilds here to avoid potentially multiple
  // rebuilds. Instead, let menu_get_item() issue the rebuild on the next page.
  if (!empty($type->data['use_one_page'])) {
    variable_set('menu_rebuild_needed', TRUE);
  }
}

/**
 * Implements hook_form_profile2_form_alter()
 * @param $form
 * @param $form_state
 */
function profiles2_one_page_form_profile2_form_alter(&$form, &$form_state) {
  if (variable_get('profiles2_one_page_wrap_account', FALSE)) {
    $form["account"]["#type"] = "fieldset";
    $form["account"]["#title"] = t(variable_get('profiles2_one_page_wrap_account_title', ""));
  }
}