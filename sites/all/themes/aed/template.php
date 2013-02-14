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


/**
 * Process variables for the html template.
 */
/* -- Delete this line if you want to use this function
function aed_process_html(&$vars) {
}
// */


/**
 * Override or insert variables for the page templates.
 */

function aed_preprocess_page(&$vars) {

  //Odiamos que los theme invoquen menus directamente, eso es competencia del site builder.
//  if (isset($vars['primary_navigation'])) {
//    $vars['primary_navigation'] = FALSE;
//  }

//  if (isset($vars['secondary_navigation'])) {
//    $vars['secondary_navigation'] = FALSE;
//  }

}

function aed_process_page(&$vars) {
}


/**
 * Override or insert variables into the node templates.
 */
/* -- Delete this line if you want to use these functions
function aed_preprocess_node(&$vars) {
}
function aed_process_node(&$vars) {
}
// */


/**
 * Override or insert variables into the comment templates.
 */
/* -- Delete this line if you want to use these functions
function aed_preprocess_comment(&$vars) {
}
function aed_process_comment(&$vars) {
}
// */


/**
 * Override or insert variables into the block templates.
 */
/* -- Delete this line if you want to use these functions
function aed_preprocess_block(&$vars) {
}
function aed_process_block(&$vars) {
}
// */


//function aed_links($vars) {
//  return theme_links($vars);
//}

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