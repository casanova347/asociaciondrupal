<?php
/**
 * @file
 * aed_panels.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function aed_panels_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Socio',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Profile2 from user',
        'keyword' => 'profile2',
        'name' => 'profile2',
        'type' => 'socio',
        'context' => 'argument_entity_id:user_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'user_profile_view';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_main' => NULL,
      'foto' => NULL,
      'nombre' => NULL,
      'contenido-footer' => NULL,
      'contenido' => NULL,
      'contenido-header' => NULL,
    ),
    'nombre' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7f4274e0-cea8-488f-9d38-07687eecffd7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0bd595cc-e0db-4e08-be8b-1030290f98a2';
    $pane->panel = 'contenido';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_idiomas';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'list_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0bd595cc-e0db-4e08-be8b-1030290f98a2';
    $display->content['new-0bd595cc-e0db-4e08-be8b-1030290f98a2'] = $pane;
    $display->panels['contenido'][0] = 'new-0bd595cc-e0db-4e08-be8b-1030290f98a2';
    $pane = new stdClass();
    $pane->pid = 'new-5a2ba0ed-d7d2-415e-a3ab-b270aaf28c65';
    $pane->panel = 'contenido';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_pais';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5a2ba0ed-d7d2-415e-a3ab-b270aaf28c65';
    $display->content['new-5a2ba0ed-d7d2-415e-a3ab-b270aaf28c65'] = $pane;
    $display->panels['contenido'][1] = 'new-5a2ba0ed-d7d2-415e-a3ab-b270aaf28c65';
    $pane = new stdClass();
    $pane->pid = 'new-78fcd39c-e92e-4136-bc08-4365d274b028';
    $pane->panel = 'contenido';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_perfil_en_drupal_org';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '78fcd39c-e92e-4136-bc08-4365d274b028';
    $display->content['new-78fcd39c-e92e-4136-bc08-4365d274b028'] = $pane;
    $display->panels['contenido'][2] = 'new-78fcd39c-e92e-4136-bc08-4365d274b028';
    $pane = new stdClass();
    $pane->pid = 'new-1508995e-581f-4a0a-aba0-8d4ebbd1bb77';
    $pane->panel = 'contenido';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_perfil_facebook';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '1508995e-581f-4a0a-aba0-8d4ebbd1bb77';
    $display->content['new-1508995e-581f-4a0a-aba0-8d4ebbd1bb77'] = $pane;
    $display->panels['contenido'][3] = 'new-1508995e-581f-4a0a-aba0-8d4ebbd1bb77';
    $pane = new stdClass();
    $pane->pid = 'new-dfdfe331-b908-4d54-bcd5-e4a424d6b298';
    $pane->panel = 'contenido';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_perfil_google_plus';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'dfdfe331-b908-4d54-bcd5-e4a424d6b298';
    $display->content['new-dfdfe331-b908-4d54-bcd5-e4a424d6b298'] = $pane;
    $display->panels['contenido'][4] = 'new-dfdfe331-b908-4d54-bcd5-e4a424d6b298';
    $pane = new stdClass();
    $pane->pid = 'new-7ba9f4ef-274c-4e7e-9a45-626d8cd2cee6';
    $pane->panel = 'contenido';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_perfil_linkedin';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '7ba9f4ef-274c-4e7e-9a45-626d8cd2cee6';
    $display->content['new-7ba9f4ef-274c-4e7e-9a45-626d8cd2cee6'] = $pane;
    $display->panels['contenido'][5] = 'new-7ba9f4ef-274c-4e7e-9a45-626d8cd2cee6';
    $pane = new stdClass();
    $pane->pid = 'new-71645351-ae61-42f7-9e5d-e29840e9158c';
    $pane->panel = 'contenido';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_perfil_twitter';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '71645351-ae61-42f7-9e5d-e29840e9158c';
    $display->content['new-71645351-ae61-42f7-9e5d-e29840e9158c'] = $pane;
    $display->panels['contenido'][6] = 'new-71645351-ae61-42f7-9e5d-e29840e9158c';
    $pane = new stdClass();
    $pane->pid = 'new-2cdbd45d-177a-451a-a297-03292d82e648';
    $pane->panel = 'contenido';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_pagina_web';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '2cdbd45d-177a-451a-a297-03292d82e648';
    $display->content['new-2cdbd45d-177a-451a-a297-03292d82e648'] = $pane;
    $display->panels['contenido'][7] = 'new-2cdbd45d-177a-451a-a297-03292d82e648';
    $pane = new stdClass();
    $pane->pid = 'new-0e423358-b03b-42ee-89c4-984bc1543930';
    $pane->panel = 'contenido';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_que_haces_en_drupal';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '0e423358-b03b-42ee-89c4-984bc1543930';
    $display->content['new-0e423358-b03b-42ee-89c4-984bc1543930'] = $pane;
    $display->panels['contenido'][8] = 'new-0e423358-b03b-42ee-89c4-984bc1543930';
    $pane = new stdClass();
    $pane->pid = 'new-35c7f9ed-e747-4c39-b013-98028ec7244e';
    $pane->panel = 'foto';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_foto';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'thumbnail',
        'image_link' => '',
      ),
      'context' => 'relationship_profile2_1',
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
    $pane->uuid = '35c7f9ed-e747-4c39-b013-98028ec7244e';
    $display->content['new-35c7f9ed-e747-4c39-b013-98028ec7244e'] = $pane;
    $display->panels['foto'][0] = 'new-35c7f9ed-e747-4c39-b013-98028ec7244e';
    $pane = new stdClass();
    $pane->pid = 'new-eba0399a-d29e-4567-9081-b0358437accb';
    $pane->panel = 'nombre';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_nombre';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
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
    $pane->uuid = 'eba0399a-d29e-4567-9081-b0358437accb';
    $display->content['new-eba0399a-d29e-4567-9081-b0358437accb'] = $pane;
    $display->panels['nombre'][0] = 'new-eba0399a-d29e-4567-9081-b0358437accb';
    $pane = new stdClass();
    $pane->pid = 'new-e85ac87c-8cb7-4bd5-b431-587cc889ab40';
    $pane->panel = 'nombre';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_apellidos';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
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
    $pane->uuid = 'e85ac87c-8cb7-4bd5-b431-587cc889ab40';
    $display->content['new-e85ac87c-8cb7-4bd5-b431-587cc889ab40'] = $pane;
    $display->panels['nombre'][1] = 'new-e85ac87c-8cb7-4bd5-b431-587cc889ab40';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-e85ac87c-8cb7-4bd5-b431-587cc889ab40';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context'] = $handler;

  return $export;
}
