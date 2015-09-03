<?php

/**
 * Implements hook_preprocess_page().
 */
function frontid_th_preprocess_block(&$variables) {
  if (in_array('block__system__main_menu', $variables['theme_hook_suggestions'])) {
    unset($variables['theme_hook_suggestions'][3]);
  }
}
