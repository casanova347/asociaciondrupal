<?php
/**
 * @file
 * aed_videos.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function aed_videos_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'videos';
  $page->task = 'page';
  $page->admin_title = 'videos';
  $page->admin_description = '';
  $page->path = 'videos';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_videos_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'videos';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'two_33_66';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'two_33_66_top' => NULL,
      'two_33_66_first' => NULL,
      'two_33_66_second' => NULL,
      'two_33_66_bottom' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6b5253cf-631f-4d7b-8b5c-77dc3b72596e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9caf0921-daea-4e4d-b1b0-b13e2eb6397d';
    $pane->panel = 'two_33_66_first';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-JU1CPZKcKFSvy3lLZX64kGgHkXFUbjc9';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Audiencia',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9caf0921-daea-4e4d-b1b0-b13e2eb6397d';
    $display->content['new-9caf0921-daea-4e4d-b1b0-b13e2eb6397d'] = $pane;
    $display->panels['two_33_66_first'][0] = 'new-9caf0921-daea-4e4d-b1b0-b13e2eb6397d';
    $pane = new stdClass();
    $pane->pid = 'new-9cb5617b-c2c6-462d-a805-c1a3962f3d0d';
    $pane->panel = 'two_33_66_first';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-gxlPQaUy1iH65ijR0Dk0ZewJRI8YO8zp';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Nivel',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9cb5617b-c2c6-462d-a805-c1a3962f3d0d';
    $display->content['new-9cb5617b-c2c6-462d-a805-c1a3962f3d0d'] = $pane;
    $display->panels['two_33_66_first'][1] = 'new-9cb5617b-c2c6-462d-a805-c1a3962f3d0d';
    $pane = new stdClass();
    $pane->pid = 'new-d7f11c6b-7a6e-487a-ad87-6df0069ac2d8';
    $pane->panel = 'two_33_66_first';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-QIWCxYs3r78RB3dTQHED5yKm0URzmgyg';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Idioma',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd7f11c6b-7a6e-487a-ad87-6df0069ac2d8';
    $display->content['new-d7f11c6b-7a6e-487a-ad87-6df0069ac2d8'] = $pane;
    $display->panels['two_33_66_first'][2] = 'new-d7f11c6b-7a6e-487a-ad87-6df0069ac2d8';
    $pane = new stdClass();
    $pane->pid = 'new-e50fffe6-df0d-4b97-ad57-0c6f1158279c';
    $pane->panel = 'two_33_66_first';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-GYrkEaRCgKvMqWrAUOaV000r83O71D7Y';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Versión',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e50fffe6-df0d-4b97-ad57-0c6f1158279c';
    $display->content['new-e50fffe6-df0d-4b97-ad57-0c6f1158279c'] = $pane;
    $display->panels['two_33_66_first'][3] = 'new-e50fffe6-df0d-4b97-ad57-0c6f1158279c';
    $pane = new stdClass();
    $pane->pid = 'new-5136b058-0979-4cb7-bc24-cafa23477a10';
    $pane->panel = 'two_33_66_first';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-0XpDMOYMz6QPcszJPXD2sRwMZ3K4hknC';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Año',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '5136b058-0979-4cb7-bc24-cafa23477a10';
    $display->content['new-5136b058-0979-4cb7-bc24-cafa23477a10'] = $pane;
    $display->panels['two_33_66_first'][4] = 'new-5136b058-0979-4cb7-bc24-cafa23477a10';
    $pane = new stdClass();
    $pane->pid = 'new-15480076-bf3d-45b3-ba00-6d3dcca992cf';
    $pane->panel = 'two_33_66_first';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-ZwBOjYiH0aLVCaYnfP0ByJRf8NbgqfUe';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Evento',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '15480076-bf3d-45b3-ba00-6d3dcca992cf';
    $display->content['new-15480076-bf3d-45b3-ba00-6d3dcca992cf'] = $pane;
    $display->panels['two_33_66_first'][5] = 'new-15480076-bf3d-45b3-ba00-6d3dcca992cf';
    $pane = new stdClass();
    $pane->pid = 'new-f4f124c1-b548-4573-aedb-352630659e13';
    $pane->panel = 'two_33_66_second';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-videos-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f4f124c1-b548-4573-aedb-352630659e13';
    $display->content['new-f4f124c1-b548-4573-aedb-352630659e13'] = $pane;
    $display->panels['two_33_66_second'][0] = 'new-f4f124c1-b548-4573-aedb-352630659e13';
    $pane = new stdClass();
    $pane->pid = 'new-bd97af2a-e5a7-4c66-bda7-01173deda9b6';
    $pane->panel = 'two_33_66_second';
    $pane->type = 'block';
    $pane->subtype = 'aed_videos-aed_videos__filter_flag';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bd97af2a-e5a7-4c66-bda7-01173deda9b6';
    $display->content['new-bd97af2a-e5a7-4c66-bda7-01173deda9b6'] = $pane;
    $display->panels['two_33_66_second'][1] = 'new-bd97af2a-e5a7-4c66-bda7-01173deda9b6';
    $pane = new stdClass();
    $pane->pid = 'new-68b8e883-c815-400e-b704-bdfe04e4deff';
    $pane->panel = 'two_33_66_second';
    $pane->type = 'block';
    $pane->subtype = 'search_api_sorts-search-sorts';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '68b8e883-c815-400e-b704-bdfe04e4deff';
    $display->content['new-68b8e883-c815-400e-b704-bdfe04e4deff'] = $pane;
    $display->panels['two_33_66_second'][2] = 'new-68b8e883-c815-400e-b704-bdfe04e4deff';
    $pane = new stdClass();
    $pane->pid = 'new-c4ae4751-6813-476c-85b0-9ad520adbfd8';
    $pane->panel = 'two_33_66_second';
    $pane->type = 'views_panes';
    $pane->subtype = 'videos-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'c4ae4751-6813-476c-85b0-9ad520adbfd8';
    $display->content['new-c4ae4751-6813-476c-85b0-9ad520adbfd8'] = $pane;
    $display->panels['two_33_66_second'][3] = 'new-c4ae4751-6813-476c-85b0-9ad520adbfd8';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-68b8e883-c815-400e-b704-bdfe04e4deff';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['videos'] = $page;

  return $pages;

}
