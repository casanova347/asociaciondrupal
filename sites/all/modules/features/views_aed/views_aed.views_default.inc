<?php
/**
 * @file
 * views_aed.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_aed_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'empresas_colaboradoras_por_anio';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Empresas colaboradoras por año';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'views-tab-empresas-colaboradoras';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    1 => '1',
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendente';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'tabs';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_anos_que_ha_participado',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['list'] = array(
    'type' => 'ul',
    'class' => '',
    'wrapper_class' => 'item-list',
    'theme' => 'views_view_list',
    'uses_fields' => 0,
  );
  $handler->display->display_options['style_options']['table'] = array(
    'columns' => array(
      'field_web_page' => 'field_web_page',
      'field_anos_que_ha_participado' => 'field_anos_que_ha_participado',
      'field_image' => 'field_image',
    ),
    'default' => '',
    'info' => array(
      'field_web_page' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_anos_que_ha_participado' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_image' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
    ),
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'summary' => '',
    'empty_table' => 0,
    'theme' => 'views_view_table',
    'uses_fields' => 0,
  );
  $handler->display->display_options['style_options']['grid'] = array(
    'columns' => '2',
    'alignment' => 'horizontal',
    'fill_single_line' => 1,
    'summary' => '',
    'theme' => 'views_view_grid',
    'uses_fields' => 0,
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Perfil: Página Web */
  $handler->display->display_options['fields']['field_web_page']['id'] = 'field_web_page';
  $handler->display->display_options['fields']['field_web_page']['table'] = 'field_data_field_web_page';
  $handler->display->display_options['fields']['field_web_page']['field'] = 'field_web_page';
  $handler->display->display_options['fields']['field_web_page']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_page']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_web_page']['type'] = 'link_plain';
  /* Campo: Perfil: Años patrocinados */
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['id'] = 'field_anos_que_ha_participado';
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['table'] = 'field_data_field_anos_que_ha_participado';
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['field'] = 'field_anos_que_ha_participado';
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['label'] = '';
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['alter']['path'] = '#content-of-[field_anos_que_ha_participado-tid]';
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['element_wrapper_class'] = 'tab';
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['multi_type'] = 'ul';
  /* Campo: Campo: Logo */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = '[field_web_page]';
  $handler->display->display_options['fields']['field_image']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Criterio de ordenación: Perfil: Años patrocinados (field_anos_que_ha_participado) */
  $handler->display->display_options['sorts']['field_anos_que_ha_participado_tid']['id'] = 'field_anos_que_ha_participado_tid';
  $handler->display->display_options['sorts']['field_anos_que_ha_participado_tid']['table'] = 'field_data_field_anos_que_ha_participado';
  $handler->display->display_options['sorts']['field_anos_que_ha_participado_tid']['field'] = 'field_anos_que_ha_participado_tid';
  $handler->display->display_options['sorts']['field_anos_que_ha_participado_tid']['order'] = 'DESC';
  /* Criterio de ordenación: Global: Aleatorio */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Criterios de filtrado: Perfil: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'partner_companies' => 'partner_companies',
  );
  /* Criterios de filtrado: Perfil: Años patrocinados (field_anos_que_ha_participado) */
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['id'] = 'field_anos_que_ha_participado_tid';
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['table'] = 'field_data_field_anos_que_ha_participado';
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['field'] = 'field_anos_que_ha_participado_tid';
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['vocabulary'] = 'anios';
  /* Criterios de filtrado: Campo: Logo (field_image:alt) */
  $handler->display->display_options['filters']['field_image_alt']['id'] = 'field_image_alt';
  $handler->display->display_options['filters']['field_image_alt']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['field_image_alt']['field'] = 'field_image_alt';
  $handler->display->display_options['filters']['field_image_alt']['operator'] = 'not empty';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'Paneles de vista';
  $translatables['empresas_colaboradoras_por_anio'] = array(
    t('Master'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Ascendente'),
    t('Desc'),
    t('Página Web'),
    t('Content pane'),
    t('Paneles de vista'),
  );
  $export['empresas_colaboradoras_por_anio'] = $view;

  $view = new view();
  $view->name = 'gestion_de_empresas';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Gestión de empresas';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Gestión de empresas';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filtrar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Encabezado: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Mostrando @start - @end de un total de @total';
  /* Campo: Perfil: Perfil ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Campo: Campo: Nombre */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  /* Campo: Perfil: Persona de contacto */
  $handler->display->display_options['fields']['field_persona_contacto']['id'] = 'field_persona_contacto';
  $handler->display->display_options['fields']['field_persona_contacto']['table'] = 'field_data_field_persona_contacto';
  $handler->display->display_options['fields']['field_persona_contacto']['field'] = 'field_persona_contacto';
  /* Campo: Campo: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = 'Correo';
  /* Campo: Perfil: Teléfono de contacto */
  $handler->display->display_options['fields']['field_telefono_de_contacto']['id'] = 'field_telefono_de_contacto';
  $handler->display->display_options['fields']['field_telefono_de_contacto']['table'] = 'field_data_field_telefono_de_contacto';
  $handler->display->display_options['fields']['field_telefono_de_contacto']['field'] = 'field_telefono_de_contacto';
  $handler->display->display_options['fields']['field_telefono_de_contacto']['label'] = 'Teléfonos';
  /* Campo: Perfil: Años patrocinados */
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['id'] = 'field_anos_que_ha_participado';
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['table'] = 'field_data_field_anos_que_ha_participado';
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['field'] = 'field_anos_que_ha_participado';
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['settings'] = array(
    'token_display_selected' => '',
    'token_display_unselected' => '',
  );
  $handler->display->display_options['fields']['field_anos_que_ha_participado']['delta_offset'] = '0';
  /* Campo: Perfil: Notas */
  $handler->display->display_options['fields']['field_notas']['id'] = 'field_notas';
  $handler->display->display_options['fields']['field_notas']['table'] = 'field_data_field_notas';
  $handler->display->display_options['fields']['field_notas']['field'] = 'field_notas';
  $handler->display->display_options['fields']['field_notas']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_notas']['settings'] = array(
    'trim_length' => '200',
  );
  /* Campo: Perfil: Usuario uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['label'] = 'User uid';
  $handler->display->display_options['fields']['user']['exclude'] = TRUE;
  /* Campo: Global: Texto personalizado */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Acciones';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/user/[user]" target="_blank">Ver</a>
<br />
<a href="/user/[user]/edit" target="_blank">editar</a>';
  /* Campo: Perfil: Lugar de operaciónes */
  $handler->display->display_options['fields']['field_lugar_de_operaciones']['id'] = 'field_lugar_de_operaciones';
  $handler->display->display_options['fields']['field_lugar_de_operaciones']['table'] = 'field_data_field_lugar_de_operaciones';
  $handler->display->display_options['fields']['field_lugar_de_operaciones']['field'] = 'field_lugar_de_operaciones';
  $handler->display->display_options['fields']['field_lugar_de_operaciones']['label'] = 'Localización';
  $handler->display->display_options['fields']['field_lugar_de_operaciones']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_lugar_de_operaciones']['delta_offset'] = '0';
  /* Criterios de filtrado: Perfil: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'partner_companies' => 'partner_companies',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Criterios de filtrado: Perfil: Usuario uid */
  $handler->display->display_options['filters']['user']['id'] = 'user';
  $handler->display->display_options['filters']['user']['table'] = 'profile';
  $handler->display->display_options['filters']['user']['field'] = 'user';
  $handler->display->display_options['filters']['user']['operator'] = '!=';
  $handler->display->display_options['filters']['user']['value']['value'] = '1';
  $handler->display->display_options['filters']['user']['group'] = 1;
  /* Criterios de filtrado: Campo: Nombre (field_name) */
  $handler->display->display_options['filters']['field_name_value']['id'] = 'field_name_value';
  $handler->display->display_options['filters']['field_name_value']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name_value']['field'] = 'field_name_value';
  $handler->display->display_options['filters']['field_name_value']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['field_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name_value']['expose']['operator_id'] = 'field_name_value_op';
  $handler->display->display_options['filters']['field_name_value']['expose']['label'] = 'Nombre de la empresa';
  $handler->display->display_options['filters']['field_name_value']['expose']['operator'] = 'field_name_value_op';
  $handler->display->display_options['filters']['field_name_value']['expose']['identifier'] = 'field_name_value';
  $handler->display->display_options['filters']['field_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Criterios de filtrado: Perfil: Años patrocinados (field_anos_que_ha_participado) */
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['id'] = 'field_anos_que_ha_participado_tid';
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['table'] = 'field_data_field_anos_que_ha_participado';
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['field'] = 'field_anos_que_ha_participado_tid';
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['expose']['operator_id'] = 'field_anos_que_ha_participado_tid_op';
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['expose']['label'] = 'Años patrocinados';
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['expose']['operator'] = 'field_anos_que_ha_participado_tid_op';
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['expose']['identifier'] = 'field_anos_que_ha_participado_tid';
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['vocabulary'] = 'anios';
  $handler->display->display_options['filters']['field_anos_que_ha_participado_tid']['hierarchy'] = 1;
  /* Criterios de filtrado: Perfil: Lugar de operaciónes (field_lugar_de_operaciones) */
  $handler->display->display_options['filters']['field_lugar_de_operaciones_tid']['id'] = 'field_lugar_de_operaciones_tid';
  $handler->display->display_options['filters']['field_lugar_de_operaciones_tid']['table'] = 'field_data_field_lugar_de_operaciones';
  $handler->display->display_options['filters']['field_lugar_de_operaciones_tid']['field'] = 'field_lugar_de_operaciones_tid';
  $handler->display->display_options['filters']['field_lugar_de_operaciones_tid']['value'] = '';
  $handler->display->display_options['filters']['field_lugar_de_operaciones_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_lugar_de_operaciones_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lugar_de_operaciones_tid']['expose']['operator_id'] = 'field_lugar_de_operaciones_tid_op';
  $handler->display->display_options['filters']['field_lugar_de_operaciones_tid']['expose']['label'] = 'Localización';
  $handler->display->display_options['filters']['field_lugar_de_operaciones_tid']['expose']['operator'] = 'field_lugar_de_operaciones_tid_op';
  $handler->display->display_options['filters']['field_lugar_de_operaciones_tid']['expose']['identifier'] = 'field_lugar_de_operaciones_tid';
  $handler->display->display_options['filters']['field_lugar_de_operaciones_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_lugar_de_operaciones_tid']['vocabulary'] = 'paises';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'gestion-de-empresas';
  $translatables['gestion_de_empresas'] = array(
    t('Master'),
    t('Gestión de empresas'),
    t('más'),
    t('Filtrar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Ascendente'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
    t('« primera'),
    t('‹ anterior'),
    t('siguiente ›'),
    t('última »'),
    t('Mostrando @start - @end de un total de @total'),
    t('.'),
    t(','),
    t('Nombre'),
    t('Persona de contacto'),
    t('Correo'),
    t('Teléfonos'),
    t('Años patrocinados'),
    t('Notas'),
    t('User uid'),
    t('Acciones'),
    t('<a href="/user/[user]" target="_blank">Ver</a>
<br />
<a href="/user/[user]/edit" target="_blank">editar</a>'),
    t('Localización'),
    t('Nombre de la empresa'),
    t('Page'),
  );
  $export['gestion_de_empresas'] = $view;

  $view = new view();
  $view->name = 'gestion_de_socios';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Gestión de socios';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Gestión de socios';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
    8 => '8',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filtrar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'user' => 'user',
    'field_foto' => 'field_foto',
    'name' => 'name',
    'field_nombre' => 'field_nombre',
    'field_apellidos' => 'field_apellidos',
    'created' => 'created',
    'nothing' => 'nothing',
    'edit_node' => 'edit_node',
    'view_user' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_nombre';
  $handler->display->display_options['style_options']['info'] = array(
    'user' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_foto' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_nombre' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_apellidos' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'view_user' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Encabezado: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Mostrando @start - @end de un total de @total';
  /* Relación: Perfil: Usuario uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Campo: Perfil: Usuario uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['label'] = 'User uid';
  $handler->display->display_options['fields']['user']['exclude'] = TRUE;
  /* Campo: Perfil: Foto */
  $handler->display->display_options['fields']['field_foto']['id'] = 'field_foto';
  $handler->display->display_options['fields']['field_foto']['table'] = 'field_data_field_foto';
  $handler->display->display_options['fields']['field_foto']['field'] = 'field_foto';
  $handler->display->display_options['fields']['field_foto']['label'] = '';
  $handler->display->display_options['fields']['field_foto']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_foto']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_foto']['settings'] = array(
    'image_style' => '50x50',
    'image_link' => '',
  );
  /* Campo: Usuario: Nombre */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'Nombre de usuario';
  /* Campo: Perfil: Nombre */
  $handler->display->display_options['fields']['field_nombre']['id'] = 'field_nombre';
  $handler->display->display_options['fields']['field_nombre']['table'] = 'field_data_field_nombre';
  $handler->display->display_options['fields']['field_nombre']['field'] = 'field_nombre';
  /* Campo: Perfil: Apellidos */
  $handler->display->display_options['fields']['field_apellidos']['id'] = 'field_apellidos';
  $handler->display->display_options['fields']['field_apellidos']['table'] = 'field_data_field_apellidos';
  $handler->display->display_options['fields']['field_apellidos']['field'] = 'field_apellidos';
  /* Campo: Usuario: Fecha de creación */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'user';
  $handler->display->display_options['fields']['created']['label'] = 'Alta';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Campo: Usuario: Enlace */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['relationship'] = 'user';
  $handler->display->display_options['fields']['view_user']['text'] = 'Ver';
  /* Campo: Usuario: Enlace de edición */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'user';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Criterios de filtrado: Perfil: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'socio' => 'socio',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Criterios de filtrado: Perfil: Usuario uid */
  $handler->display->display_options['filters']['user']['id'] = 'user';
  $handler->display->display_options['filters']['user']['table'] = 'profile';
  $handler->display->display_options['filters']['user']['field'] = 'user';
  $handler->display->display_options['filters']['user']['operator'] = '!=';
  $handler->display->display_options['filters']['user']['value']['value'] = '1';
  $handler->display->display_options['filters']['user']['group'] = 1;
  /* Criterios de filtrado: Usuario: Nombre */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'user';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'nick';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Criterios de filtrado: Perfil: Nombre (field_nombre) */
  $handler->display->display_options['filters']['field_nombre_value']['id'] = 'field_nombre_value';
  $handler->display->display_options['filters']['field_nombre_value']['table'] = 'field_data_field_nombre';
  $handler->display->display_options['filters']['field_nombre_value']['field'] = 'field_nombre_value';
  $handler->display->display_options['filters']['field_nombre_value']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['field_nombre_value']['group'] = 1;
  $handler->display->display_options['filters']['field_nombre_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_nombre_value']['expose']['operator_id'] = 'field_nombre_value_op';
  $handler->display->display_options['filters']['field_nombre_value']['expose']['label'] = 'Nombre';
  $handler->display->display_options['filters']['field_nombre_value']['expose']['operator'] = 'field_nombre_value_op';
  $handler->display->display_options['filters']['field_nombre_value']['expose']['identifier'] = 'field_nombre_value';
  $handler->display->display_options['filters']['field_nombre_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Criterios de filtrado: Perfil: Apellidos (field_apellidos) */
  $handler->display->display_options['filters']['field_apellidos_value']['id'] = 'field_apellidos_value';
  $handler->display->display_options['filters']['field_apellidos_value']['table'] = 'field_data_field_apellidos';
  $handler->display->display_options['filters']['field_apellidos_value']['field'] = 'field_apellidos_value';
  $handler->display->display_options['filters']['field_apellidos_value']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['field_apellidos_value']['group'] = 1;
  $handler->display->display_options['filters']['field_apellidos_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_apellidos_value']['expose']['operator_id'] = 'field_apellidos_value_op';
  $handler->display->display_options['filters']['field_apellidos_value']['expose']['label'] = 'Apellidos';
  $handler->display->display_options['filters']['field_apellidos_value']['expose']['operator'] = 'field_apellidos_value_op';
  $handler->display->display_options['filters']['field_apellidos_value']['expose']['identifier'] = 'field_apellidos_value';
  $handler->display->display_options['filters']['field_apellidos_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Criterios de filtrado: Usuario: Correo electrónico */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['relationship'] = 'user';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'Correo electrónico';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Criterios de filtrado: Usuario: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    'all' => 'all',
    7 => '7',
  );
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Roles';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['rid']['expose']['reduce'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'gestion-de-socios';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Perfil: Usuario uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['label'] = 'User uid';
  $handler->display->display_options['fields']['user']['exclude'] = TRUE;
  /* Campo: Usuario: Nombre */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'Nombre de usuario';
  /* Campo: Perfil: Nombre */
  $handler->display->display_options['fields']['field_nombre']['id'] = 'field_nombre';
  $handler->display->display_options['fields']['field_nombre']['table'] = 'field_data_field_nombre';
  $handler->display->display_options['fields']['field_nombre']['field'] = 'field_nombre';
  /* Campo: Perfil: Apellidos */
  $handler->display->display_options['fields']['field_apellidos']['id'] = 'field_apellidos';
  $handler->display->display_options['fields']['field_apellidos']['table'] = 'field_data_field_apellidos';
  $handler->display->display_options['fields']['field_apellidos']['field'] = 'field_apellidos';
  /* Campo: Usuario: Fecha de creación */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'user';
  $handler->display->display_options['fields']['created']['label'] = 'Alta';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Campo: Usuario: Enlace */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['relationship'] = 'user';
  $handler->display->display_options['fields']['view_user']['text'] = 'Ver';
  /* Campo: Usuario: Enlace de edición */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'user';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Criterios de filtrado: Perfil: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'socio' => 'socio',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Criterios de filtrado: Perfil: Usuario uid */
  $handler->display->display_options['filters']['user']['id'] = 'user';
  $handler->display->display_options['filters']['user']['table'] = 'profile';
  $handler->display->display_options['filters']['user']['field'] = 'user';
  $handler->display->display_options['filters']['user']['operator'] = '!=';
  $handler->display->display_options['filters']['user']['value']['value'] = '1';
  $handler->display->display_options['filters']['user']['group'] = 1;
  /* Criterios de filtrado: Usuario: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    7 => '7',
  );
  $handler->display->display_options['path'] = 'gestion-de-socios-bis';
  $translatables['gestion_de_socios'] = array(
    t('Master'),
    t('Gestión de socios'),
    t('más'),
    t('Filtrar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Ascendente'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
    t('« primera'),
    t('‹ anterior'),
    t('siguiente ›'),
    t('última »'),
    t('Mostrando @start - @end de un total de @total'),
    t('Usuario'),
    t('User uid'),
    t('.'),
    t(','),
    t('Nombre de usuario'),
    t('Nombre'),
    t('Apellidos'),
    t('Alta'),
    t('Enlace'),
    t('Ver'),
    t('nick'),
    t('Correo electrónico'),
    t('Roles'),
    t('Page'),
  );
  $export['gestion_de_socios'] = $view;

  $view = new view();
  $view->name = 'socios';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Socios';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Socios de la AED';
  $handler->display->display_options['css_class'] = 'listado-socios';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'panels_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_foto' => 'field_foto',
    'field_nombre' => 'field_nombre',
    'field_apellidos' => 'field_apellidos',
  );
  $handler->display->display_options['row_options']['separator'] = ' ';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['layout'] = 'views_field_user_profile_view';
  $handler->display->display_options['row_options']['regions'] = array(
    'field_foto' => 'foto',
    'field_nombre' => 'nombre',
    'field_apellidos' => 'nombre',
    'field_idiomas' => 'fields',
    'field_pais' => 'fields',
    'field_perfil_en_drupal_org' => 'fields',
    'field_perfil_facebook' => 'fields',
    'field_perfil_google_plus' => 'fields',
    'field_perfil_linkedin' => 'fields',
    'field_perfil_twitter' => 'fields',
    'field_pagina_web' => 'fields',
    'field_sexo' => 'fields',
  );
  /* Encabezado: Global: Área de texto */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>Si queres ser parte de la asociación puede hacerte socio <a href="/suscripcion-anual-la-asociacion-espanola-de-drupal">aquí</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* Campo: Perfil: Foto */
  $handler->display->display_options['fields']['field_foto']['id'] = 'field_foto';
  $handler->display->display_options['fields']['field_foto']['table'] = 'field_data_field_foto';
  $handler->display->display_options['fields']['field_foto']['field'] = 'field_foto';
  $handler->display->display_options['fields']['field_foto']['label'] = '';
  $handler->display->display_options['fields']['field_foto']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_foto']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_foto']['settings'] = array(
    'image_style' => '50x50',
    'image_link' => 'content',
  );
  /* Campo: Perfil: Nombre */
  $handler->display->display_options['fields']['field_nombre']['id'] = 'field_nombre';
  $handler->display->display_options['fields']['field_nombre']['table'] = 'field_data_field_nombre';
  $handler->display->display_options['fields']['field_nombre']['field'] = 'field_nombre';
  $handler->display->display_options['fields']['field_nombre']['label'] = '';
  $handler->display->display_options['fields']['field_nombre']['element_label_colon'] = FALSE;
  /* Campo: Perfil: Apellidos */
  $handler->display->display_options['fields']['field_apellidos']['id'] = 'field_apellidos';
  $handler->display->display_options['fields']['field_apellidos']['table'] = 'field_data_field_apellidos';
  $handler->display->display_options['fields']['field_apellidos']['field'] = 'field_apellidos';
  $handler->display->display_options['fields']['field_apellidos']['label'] = '';
  $handler->display->display_options['fields']['field_apellidos']['element_label_colon'] = FALSE;
  /* Campo: Perfil: Perfil en Drupal.org */
  $handler->display->display_options['fields']['field_perfil_en_drupal_org']['id'] = 'field_perfil_en_drupal_org';
  $handler->display->display_options['fields']['field_perfil_en_drupal_org']['table'] = 'field_data_field_perfil_en_drupal_org';
  $handler->display->display_options['fields']['field_perfil_en_drupal_org']['field'] = 'field_perfil_en_drupal_org';
  $handler->display->display_options['fields']['field_perfil_en_drupal_org']['label'] = '';
  $handler->display->display_options['fields']['field_perfil_en_drupal_org']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_en_drupal_org']['alter']['text'] = 'Drupal.org';
  $handler->display->display_options['fields']['field_perfil_en_drupal_org']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_en_drupal_org']['alter']['path'] = '[field_perfil_en_drupal_org]';
  $handler->display->display_options['fields']['field_perfil_en_drupal_org']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_en_drupal_org']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_en_drupal_org']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_perfil_en_drupal_org']['element_label_colon'] = FALSE;
  /* Campo: Perfil: Perfil Facebook */
  $handler->display->display_options['fields']['field_perfil_facebook']['id'] = 'field_perfil_facebook';
  $handler->display->display_options['fields']['field_perfil_facebook']['table'] = 'field_data_field_perfil_facebook';
  $handler->display->display_options['fields']['field_perfil_facebook']['field'] = 'field_perfil_facebook';
  $handler->display->display_options['fields']['field_perfil_facebook']['label'] = '';
  $handler->display->display_options['fields']['field_perfil_facebook']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_facebook']['alter']['text'] = 'Facebook';
  $handler->display->display_options['fields']['field_perfil_facebook']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_facebook']['alter']['path'] = '[field_perfil_facebook]';
  $handler->display->display_options['fields']['field_perfil_facebook']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_facebook']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_facebook']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_perfil_facebook']['element_label_colon'] = FALSE;
  /* Campo: Perfil: Perfil G+ */
  $handler->display->display_options['fields']['field_perfil_google_plus']['id'] = 'field_perfil_google_plus';
  $handler->display->display_options['fields']['field_perfil_google_plus']['table'] = 'field_data_field_perfil_google_plus';
  $handler->display->display_options['fields']['field_perfil_google_plus']['field'] = 'field_perfil_google_plus';
  $handler->display->display_options['fields']['field_perfil_google_plus']['label'] = '';
  $handler->display->display_options['fields']['field_perfil_google_plus']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_google_plus']['alter']['text'] = 'Google plus';
  $handler->display->display_options['fields']['field_perfil_google_plus']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_google_plus']['alter']['path'] = '[field_perfil_google_plus]';
  $handler->display->display_options['fields']['field_perfil_google_plus']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_google_plus']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_google_plus']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_perfil_google_plus']['element_label_colon'] = FALSE;
  /* Campo: Perfil: Perfil Linkedin */
  $handler->display->display_options['fields']['field_perfil_linkedin']['id'] = 'field_perfil_linkedin';
  $handler->display->display_options['fields']['field_perfil_linkedin']['table'] = 'field_data_field_perfil_linkedin';
  $handler->display->display_options['fields']['field_perfil_linkedin']['field'] = 'field_perfil_linkedin';
  $handler->display->display_options['fields']['field_perfil_linkedin']['label'] = '';
  $handler->display->display_options['fields']['field_perfil_linkedin']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_linkedin']['alter']['text'] = 'Linkedin';
  $handler->display->display_options['fields']['field_perfil_linkedin']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_linkedin']['alter']['path'] = '[field_perfil_linkedin]';
  $handler->display->display_options['fields']['field_perfil_linkedin']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_linkedin']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_linkedin']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_perfil_linkedin']['element_label_colon'] = FALSE;
  /* Campo: Perfil: Perfil Twitter */
  $handler->display->display_options['fields']['field_perfil_twitter']['id'] = 'field_perfil_twitter';
  $handler->display->display_options['fields']['field_perfil_twitter']['table'] = 'field_data_field_perfil_twitter';
  $handler->display->display_options['fields']['field_perfil_twitter']['field'] = 'field_perfil_twitter';
  $handler->display->display_options['fields']['field_perfil_twitter']['label'] = '';
  $handler->display->display_options['fields']['field_perfil_twitter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_twitter']['alter']['text'] = 'Twitter';
  $handler->display->display_options['fields']['field_perfil_twitter']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_twitter']['alter']['path'] = '[field_perfil_twitter-value]';
  $handler->display->display_options['fields']['field_perfil_twitter']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_twitter']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_perfil_twitter']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_perfil_twitter']['element_label_colon'] = FALSE;
  /* Campo: Perfil: Página Web */
  $handler->display->display_options['fields']['field_pagina_web']['id'] = 'field_pagina_web';
  $handler->display->display_options['fields']['field_pagina_web']['table'] = 'field_data_field_pagina_web';
  $handler->display->display_options['fields']['field_pagina_web']['field'] = 'field_pagina_web';
  $handler->display->display_options['fields']['field_pagina_web']['label'] = '';
  $handler->display->display_options['fields']['field_pagina_web']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pagina_web']['alter']['text'] = 'Página Web';
  $handler->display->display_options['fields']['field_pagina_web']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_pagina_web']['alter']['path'] = '[field_pagina_web]';
  $handler->display->display_options['fields']['field_pagina_web']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_pagina_web']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_pagina_web']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_pagina_web']['element_label_colon'] = FALSE;
  /* Criterio de ordenación: Perfil: Nombre (field_nombre) */
  $handler->display->display_options['sorts']['field_nombre_value']['id'] = 'field_nombre_value';
  $handler->display->display_options['sorts']['field_nombre_value']['table'] = 'field_data_field_nombre';
  $handler->display->display_options['sorts']['field_nombre_value']['field'] = 'field_nombre_value';
  /* Criterios de filtrado: Perfil: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'socio' => 'socio',
  );
  /* Criterios de filtrado: Perfil: Exponer mi perfil en la sección &quot;Socios&quot; (field_exponer_mi_perfil) */
  $handler->display->display_options['filters']['field_exponer_mi_perfil_value']['id'] = 'field_exponer_mi_perfil_value';
  $handler->display->display_options['filters']['field_exponer_mi_perfil_value']['table'] = 'field_data_field_exponer_mi_perfil';
  $handler->display->display_options['filters']['field_exponer_mi_perfil_value']['field'] = 'field_exponer_mi_perfil_value';
  $handler->display->display_options['filters']['field_exponer_mi_perfil_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_exponer_mi_perfil_value']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'socios';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Socios';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $translatables['socios'] = array(
    t('Master'),
    t('Socios de la AED'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Ascendente'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
    t('« primera'),
    t('‹ anterior'),
    t('siguiente ›'),
    t('última »'),
    t('<p>Si queres ser parte de la asociación puede hacerte socio <a href="/suscripcion-anual-la-asociacion-espanola-de-drupal">aquí</a></p>'),
    t('Drupal.org'),
    t('Facebook'),
    t('Google plus'),
    t('Linkedin'),
    t('Twitter'),
    t('Página Web'),
    t('Page'),
  );
  $export['socios'] = $view;

  return $export;
}
