<?php

/**
 * Implements hook_theme()
 */
function aed_theme() {

  return array(
    'aed_user_view_pane' => array(
      'variables' => array(
        'output' => array(),
        'pane' => array(),
        'display' => array()
      ),
      'path' => drupal_get_path('theme', 'aed') . '/layouts',
      'template' => 'aed-user-view-pane',
    )
  );

}

/**
 * Implements hook_process_page()
 */
function aed_process_page(&$vars) {
}


/**
 * Implements hook_form_alter()
 */
function aed_form_alter(&$form, &$form_state, $form_id) {

  //Replace labes by placeholder attribute (html5) in user_login & user_login_block forms
  if (in_array($form_id, array('user_login', 'user_login_block'))) {
    $form['name']['#attributes']['placeholder'] = t('Username');
    $form['pass']['#attributes']['placeholder'] = t('Password');
    $form['name']['#title_display'] = "invisible";
    $form['pass']['#title_display'] = "invisible";
  }
}

/**
 * Override field_textarea() to disable resizable
 */
function aed_textarea($element) {
  $element['element']['#resizable'] = FALSE;
  return theme_textarea($element);
}

/**
 * Implements hook_preprocess()
 */
function aed_preprocess(&$variables, $hook = "") {

  //When "/user" is rendered we print it into a simplified version of "panels-pane.tpl.php" to avoid extra markup
  if ($hook == "panels_pane" && $variables['display']->layout == "user_profile_view") {
    $variables['theme_hook_suggestions'][] = "aed_user_view_pane";
  }

}

/**
 * Implements hook_preprocess_field().
 */
function aed_preprocess_field(&$variables, $hook) {

  // @todo esto es una ñapa para poder ver los link del perfil de un usuario como links.
  // Convertir los field del perfil de usuario a campos tipo link y quitar este code.
  $fields_2_link = array(
    'field_perfil_en_drupal_org',
    'field_perfil_twitter',
    'field_perfil_facebook',
    'field_perfil_google_plus',
    'field_perfil_linkedin',
    'field_pagina_web',
  );

  if (
    $variables['field_view_mode'] == '_custom_display' &&
    in_array($variables['element']['#field_name'], $fields_2_link)
    && $variables['element']['#object'] instanceof Profile
  ) {

    if (TRUE || $variables['element'][0]['#markup']) {
      $variables['items'][0]['#markup'] = l(
        $variables['items'][0]['#markup'],
        $variables['items'][0]['#markup'],
        array(
          'attributes' => array('rel' => 'nofollow'),
          'absolute' => TRUE
        )
      );
    }
  }
}