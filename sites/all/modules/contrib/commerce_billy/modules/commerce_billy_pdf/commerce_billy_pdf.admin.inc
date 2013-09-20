<?php

/**
 * @file
 * Settings for Commerce Billy PDF.
 */

/**
 * Admin settings form for invoice pdf.
 */
function commerce_billy_pdf_admin_form($form, &$form_state) {

  $settings = variable_get('commerce_billy_pdf_text_settings', array());

  $form['commerce_billy_pdf_settings'] = array(
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('PDF Text settings'),
  );

  $form['commerce_billy_pdf_settings']['invoice_header'] = array(
    '#type' => 'textarea',
    '#title' => t('Invoice header'),
    '#default_value' => isset($settings['invoice_header']) ? $settings['invoice_header'] : '',
  );
  $form['commerce_billy_pdf_settings']['invoice_location'] = array(
    '#type' => 'textfield',
    '#title' => t('Location'),
    '#default_value' => isset($settings['invoice_location']) ? $settings['invoice_location'] : '',
  );
  $form['commerce_billy_pdf_settings']['invoice_date_format'] = array(
    '#type' => 'textfield',
    '#title' => t('Date format'),
    '#default_value' => isset($settings['invoice_date_format']) ? $settings['invoice_date_format'] : 'Y-m-d',
  );
  $form['commerce_billy_pdf_settings']['invoice_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Invoice text'),
    '#default_value' => isset($settings['invoice_text']) ? $settings['invoice_text'] : '',
  );
  $form['commerce_billy_pdf_settings']['invoice_footer'] = array(
    '#type' => 'textarea',
    '#title' => t('Invoice footer'),
    '#default_value' => isset($settings['invoice_footer']) ? $settings['invoice_footer'] : '',
  );


  $form['commerce_billy_pdf_file_settings'] = array(
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('PDF file settings'),
  );

  $billy_filename_pattern = variable_get('billy_filename_pattern', array());

  $form['commerce_billy_pdf_file_settings']['billy_filename_pattern'] = array(
    '#type' => 'textfield',
    '#title' => t('File name'),
    '#default_value' => isset($billy_filename_pattern) ? $billy_filename_pattern : 'invoice_[commerce-order:order-id]',
  );

  if (module_exists('token')) {
    $form['commerce_billy_pdf_file_settings']['billy_filename_pattern']['#element_validate'][] = 'token_element_validate';
    $form['commerce_billy_pdf_file_settings']['billy_filename_pattern']['#token_type'] = array('commerce-order');
    $form['commerce_billy_pdf_file_settings']['billy_filename_pattern_tokens'] = array(
      '#type' => 'item',
      '#theme' => 'token_tree',
      '#token_types' => array('commerce-order'),
    );
  }
  else {
    $token_list = array();
    $tokens = token_info();
    $order_tokens = $tokens['tokens']['commerce-order'];

    foreach (array_keys($order_tokens) as $token) {
      $token_list[] = '<b>[commerce-order:' . check_plain($token) . ']</b> ' . filter_xss_admin($order_tokens[$token]['description']);
    }

    $form['commerce_billy_pdf_file_settings']['billy_filename_pattern_tokens'] = array(
      '#type' => 'markup',
      '#title' => 'Valid tokens:',
      '#theme' => 'item_list',
      '#items' => $token_list,
      '#description' => 'test',
    );
  }

  $form['commerce_billy_pdf_logo'] = array(
    '#type' => 'textfield',
    '#title' => t('Logo'),
    '#default_value' => variable_get('commerce_billy_pdf_logo', 'misc/druplicon.png'),
    '#required' => TRUE,
    '#description' => t('Path to invoice logo.'),
  );

  $css_files = variable_get('commerce_billy_pdf_css_files', array(drupal_get_path('module', 'commerce_billy_pdf') . '/css/pdf.css'));
  $default_value = "";
  foreach ($css_files as $file) {
    $default_value .= $file . "\n";
  }
  $form['commerce_billy_pdf_css_files'] = array(
    '#type' => 'textarea',
    '#title' => t('Inlince CSS files'),
    '#default_value' => $default_value,
    '#required' => TRUE,
    '#description' => t('One CSS file per line.'),
  );

  $form = system_settings_form($form);
  // Use custom submit handler.
  $form['#submit'] = array('commerce_billy_pdf_admin_form_submit');

  return $form;
}

/**
 * Submit handler for settings form.
 */
function commerce_billy_pdf_admin_form_submit($form, $form_state) {
  $settings = array();
  foreach ($form_state['values']['commerce_billy_pdf_settings'] as $key => $value) {
    $settings[$key] = $value;
  }
  variable_set('commerce_billy_pdf_text_settings', $settings);

  $css_files = array();
  foreach (explode("\n", $form_state['values']['commerce_billy_pdf_css_files']) as $file) {
    $file = trim($file);
    if (!empty($file)) {
      $css_files[] = $file;
    }
  }
  variable_set('commerce_billy_pdf_css_files', $css_files);
  variable_set('billy_filename_pattern', $form_state['values']['commerce_billy_pdf_file_settings']['billy_filename_pattern']);

  variable_set('commerce_billy_pdf_logo', $form_state['values']['commerce_billy_pdf_logo']);
  drupal_set_message(t('The configuration options have been saved.'));
}
