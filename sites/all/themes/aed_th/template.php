<?php

function frontid_th_preprocess(&$variables, $hook) {
  if (isset($variables['elements']['#entity_type'])) {
    $functions = array();
    $functions[] = __FUNCTION__ . '_' . $variables['elements']['#entity_type'];
    $functions[] = __FUNCTION__ . '_' . $variables['elements']['#entity_type'] . '_' . $variables['elements']['#bundle'];

    foreach ($functions as $function) {
      if (function_exists($function)) {
        $function($variables, $hook);
      }
    }
  }
}


function frontid_th_preprocess_bean_parallax(&$vars) {
  $vars ['image_info'] = image_get_info($vars['field_prallax_image'][0]['uri']);
  $vars ['image_src'] = file_create_url($vars['field_prallax_image'][0]['uri']);
  $vars ['speed'] = $vars['field_parallax_speed'][0]['value'];
  $vars ['cover_ratio'] = $vars['field_parallax_cover_ratio'][0]['value'];

  hide($vars['content']['field_prallax_image']);
  hide($vars['content']['field_parallax_cover_ratio']);
  hide($vars['content']['field_parallax_speed']);
}