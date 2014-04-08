<?php

/**
 * Generates the company type editing form.
 */
function company_type_form($form, &$form_state, $company_type, $op = 'edit') {

  if ($op == 'clone') {
    $company_type->label .= ' (cloned)';
    $company_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $company_type->label,
    '#description' => t('The human-readable name of this company type.'),
    '#required' => TRUE,
    '#size' => 30,
  );

  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($company_type->type) ? $company_type->type : '',
    '#maxlength' => 32,
    '#disabled' => $company_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'company_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this company type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#default_value' => isset($company_type->description) ? $company_type->description : '',
    '#description' => t('Description about the company type.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save company type'),
    '#weight' => 40,
  );

  if (!$company_type->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete company type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('company_type_form_submit_delete')
    );
  }
  return $form;
}

/**
 * Submit handler for creating/editing company_type.
 */
function company_type_form_submit(&$form, &$form_state) {
  $company_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  company_type_save($company_type);

  // Redirect user back to list of company types.
  $form_state['redirect'] = 'admin/structure/company-types';
}

function company_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/company-types/' . $form_state['company_type']->type . '/delete';
}

/**
 * Company type delete form.
 */
function company_type_form_delete_confirm($form, &$form_state, $company_type) {
  $form_state['company'] = $company_type;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['company_id'] = array('#type' => 'value', '#value' => entity_id('company_type', $company_type));
  return confirm_form($form,
    t('Are you sure you want to delete company type %title?', array('%title' => entity_label('company_type', $company_type))),
    'company/' . entity_id('company_type', $company_type),
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Company type delete form submit handler.
 */
function company_type_form_delete_confirm_submit($form, &$form_state) {
  $company_type = $form_state['company'];
  company_type_delete($company_type);

  watchdog('company_type', '@type: deleted %title.', array('@type' => $company_type->type, '%title' => $company_type->label));
  drupal_set_message(t('@type %title has been deleted.', array('@type' => $company_type->type, '%title' => $company_type->label)));

  $form_state['redirect'] = 'admin/structure/company-types';
}

/**
 * Page to select company Type to add new company.
 */
function company_admin_add_page() {
  $items = array();
  foreach (company_types() as $company_type_key => $company_type) {
    $items[] = l(entity_label('company_type', $company_type), 'company/add/' . $company_type_key);
  }
  return array('list' => array('#theme' => 'item_list', '#items' => $items, '#title' => t('Select type of company to create.')));
}

/**
 * Add new company page callback.
 */
function company_add($type) {
  $company_type = company_types($type);

  $company = entity_create('company', array('type' => $type));
  drupal_set_title(t('Create @name', array('@name' => entity_label('company_type', $company_type))));

  $output = drupal_get_form('company_form', $company);

  return $output;
}

/**
 * Company Form.
 */
function company_form($form, &$form_state, $company) {
  $form_state['company'] = $company;

  $form['title'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Name'),
    '#default_value' => $company->title,
  );

  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $company->uid,
  );

  field_attach_form('company', $company, $form, $form_state);

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save company'),
    '#submit' => $submit + array('company_form_submit'),
  );

  // Show Delete button if we edit company.
  $company_id = entity_id('company', $company);
  if (!empty($company_id) && company_access('edit', $company)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('company_form_submit_delete'),
    );
  }

  $form['#validate'][] = 'company_form_validate';

  return $form;
}

function company_form_validate($form, &$form_state) {

}

/**
 * Company submit handler.
 */
function company_form_submit($form, &$form_state) {
  $company = $form_state['company'];

  entity_form_submit_build_entity('company', $company, $form, $form_state);

  company_save($company);

  $company_uri = entity_uri('company', $company);

  $form_state['redirect'] = $company_uri['path'];

  drupal_set_message(t('Company %title saved.', array('%title' => entity_label('company', $company))));
}

function company_form_submit_delete($form, &$form_state) {
  $company = $form_state['company'];
  $company_uri = entity_uri('company', $company);
  $form_state['redirect'] = $company_uri['path'] . '/delete';
}

/**
 * Delete confirmation form.
 */
function company_delete_form($form, &$form_state, $company) {
  $form_state['company'] = $company;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['company_id'] = array('#type' => 'value', '#value' => entity_id('company', $company));
  $company_uri = entity_uri('company', $company);
  return confirm_form($form,
    t('Are you sure you want to delete company %title?', array('%title' => entity_label('company', $company))),
    $company_uri['path'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Delete form submit handler.
 */
function company_delete_form_submit($form, &$form_state) {
  $company = $form_state['company'];
  company_delete($company);

  drupal_set_message(t('Company %title deleted.', array('%title' => entity_label('company', $company))));

  $form_state['redirect'] = '<front>';
}
