<?php

/**
 * @file
 * Process theme data.
 *
 * Use this file to run your theme specific implimentations of theme functions,
 * such preprocess, process, alters, and theme function overrides.
 *
 * Preprocess and process functions are used to modify or create variables for
 * templates and theme functions. They are a common theming tool in Drupal, often
 * used as an alternative to directly editing or adding code to templates. Its
 * worth spending some time to learn more about these functions - they are a
 * powerful way to easily modify the output of any template variable.
 *
 * Preprocess and Process Functions SEE: http://drupal.org/node/254940#variables-processor
 * 1. Rename each function and instance of "aed" to match
 *    your subthemes name, e.g. if your theme name is "footheme" then the function
 *    name will be "footheme_preprocess_hook". Tip - you can search/replace
 *    on "aed".
 * 2. Uncomment the required function to use.
 */


/**
 * Preprocess variables for the html template.
 */
/* -- Delete this line to enable.
function aed_preprocess_html(&$vars) {
  global $theme_key;

  // Two examples of adding custom classes to the body.
  
  // Add a body class for the active theme name.
  // $vars['classes_array'][] = drupal_html_class($theme_key);

  // Browser/platform sniff - adds body classes such as ipad, webkit, chrome etc.
  // $vars['classes_array'][] = css_browser_selector();

}
// */


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

function aed_process_page(&$vars) {
}


function aed_form_alter(&$form, &$form_state, $form_id) {
  if (in_array($form_id, array('user_login', 'user_login_block'))) {
    $form['name']['#attributes']['placeholder'] = t('Username');
    $form['pass']['#attributes']['placeholder'] = t('Password');
    $form['name']['#title_display'] = "invisible";
    $form['pass']['#title_display'] = "invisible";
  }
}


function aed_textarea($element) {
  $element['element']['#resizable'] = FALSE;
  return theme_textarea($element);
}


function aed_preprocess(&$variables, $hook = "") {

  if ($hook == "panels_pane" && $variables['display']->layout == "user_profile_view") {
    $variables['theme_hook_suggestions'][] = "aed_user_view_pane";
  }

}
