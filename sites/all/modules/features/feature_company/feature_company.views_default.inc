<?php
/**
 * @file
 * feature_company.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_company_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'manage_partner';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'company';
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
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
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
  /* Campo: Empresa: Empresa ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'company';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  /* Campo: Empresa: Nombre */
  $handler->display->display_options['fields']['field_partner_name']['id'] = 'field_partner_name';
  $handler->display->display_options['fields']['field_partner_name']['table'] = 'field_data_field_partner_name';
  $handler->display->display_options['fields']['field_partner_name']['field'] = 'field_partner_name';
  /* Campo: Empresa: Persona de contacto */
  $handler->display->display_options['fields']['field_partner_contact']['id'] = 'field_partner_contact';
  $handler->display->display_options['fields']['field_partner_contact']['table'] = 'field_data_field_partner_contact';
  $handler->display->display_options['fields']['field_partner_contact']['field'] = 'field_partner_contact';
  /* Campo: Empresa: Mail de contacto */
  $handler->display->display_options['fields']['field_partner_mail']['id'] = 'field_partner_mail';
  $handler->display->display_options['fields']['field_partner_mail']['table'] = 'field_data_field_partner_mail';
  $handler->display->display_options['fields']['field_partner_mail']['field'] = 'field_partner_mail';
  $handler->display->display_options['fields']['field_partner_mail']['label'] = 'Correo';
  /* Campo: Empresa: Teléfono de contacto */
  $handler->display->display_options['fields']['field_partner_phone']['id'] = 'field_partner_phone';
  $handler->display->display_options['fields']['field_partner_phone']['table'] = 'field_data_field_partner_phone';
  $handler->display->display_options['fields']['field_partner_phone']['field'] = 'field_partner_phone';
  $handler->display->display_options['fields']['field_partner_phone']['label'] = 'Teléfonos';
  /* Campo: Empresa: Años patrocinados */
  $handler->display->display_options['fields']['field_partner_year_sponsor']['id'] = 'field_partner_year_sponsor';
  $handler->display->display_options['fields']['field_partner_year_sponsor']['table'] = 'field_data_field_partner_year_sponsor';
  $handler->display->display_options['fields']['field_partner_year_sponsor']['field'] = 'field_partner_year_sponsor';
  $handler->display->display_options['fields']['field_partner_year_sponsor']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_partner_year_sponsor']['delta_offset'] = '0';
  /* Campo: Empresa: Notas */
  $handler->display->display_options['fields']['field_partner_notes']['id'] = 'field_partner_notes';
  $handler->display->display_options['fields']['field_partner_notes']['table'] = 'field_data_field_partner_notes';
  $handler->display->display_options['fields']['field_partner_notes']['field'] = 'field_partner_notes';
  $handler->display->display_options['fields']['field_partner_notes']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_partner_notes']['settings'] = array(
    'trim_length' => '200',
  );
  /* Campo: Global: Texto personalizado */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Acciones';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/company/[cid]" target="_blank">Ver</a>
<br />
<a href="/company/[cid]/edit" target="_blank">Editar</a>';
  /* Criterios de filtrado: Empresa: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'company';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'partner' => 'partner',
  );
  /* Criterios de filtrado: Empresa: Nombre (field_partner_name) */
  $handler->display->display_options['filters']['field_partner_name_value']['id'] = 'field_partner_name_value';
  $handler->display->display_options['filters']['field_partner_name_value']['table'] = 'field_data_field_partner_name';
  $handler->display->display_options['filters']['field_partner_name_value']['field'] = 'field_partner_name_value';
  $handler->display->display_options['filters']['field_partner_name_value']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['field_partner_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_partner_name_value']['expose']['operator_id'] = 'field_partner_name_value_op';
  $handler->display->display_options['filters']['field_partner_name_value']['expose']['label'] = 'Nombre de la empresa';
  $handler->display->display_options['filters']['field_partner_name_value']['expose']['operator'] = 'field_partner_name_value_op';
  $handler->display->display_options['filters']['field_partner_name_value']['expose']['identifier'] = 'nombre';
  $handler->display->display_options['filters']['field_partner_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Criterios de filtrado: Empresa: Años patrocinados (field_partner_year_sponsor) */
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['id'] = 'field_partner_year_sponsor_tid';
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['table'] = 'field_data_field_partner_year_sponsor';
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['field'] = 'field_partner_year_sponsor_tid';
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['value'] = '';
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['expose']['operator_id'] = 'field_partner_year_sponsor_tid_op';
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['expose']['label'] = 'Años patrocinados';
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['expose']['operator'] = 'field_partner_year_sponsor_tid_op';
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['expose']['identifier'] = 'anyos';
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['vocabulary'] = 'anios';
  /* Criterios de filtrado: Empresa: Lugar de operaciones (field_partner_location) */
  $handler->display->display_options['filters']['field_partner_location_tid']['id'] = 'field_partner_location_tid';
  $handler->display->display_options['filters']['field_partner_location_tid']['table'] = 'field_data_field_partner_location';
  $handler->display->display_options['filters']['field_partner_location_tid']['field'] = 'field_partner_location_tid';
  $handler->display->display_options['filters']['field_partner_location_tid']['value'] = '';
  $handler->display->display_options['filters']['field_partner_location_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_partner_location_tid']['expose']['operator_id'] = 'field_partner_location_tid_op';
  $handler->display->display_options['filters']['field_partner_location_tid']['expose']['label'] = 'Localización';
  $handler->display->display_options['filters']['field_partner_location_tid']['expose']['operator'] = 'field_partner_location_tid_op';
  $handler->display->display_options['filters']['field_partner_location_tid']['expose']['identifier'] = 'localizacion';
  $handler->display->display_options['filters']['field_partner_location_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_partner_location_tid']['vocabulary'] = 'paises';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'gestion-de-empresas2';
  $translatables['manage_partner'] = array(
    t('Master'),
    t('Gestión de empresas'),
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
    t('Empresa ID'),
    t('.'),
    t(','),
    t('Nombre'),
    t('Persona de contacto'),
    t('Correo'),
    t('Teléfonos'),
    t('Años patrocinados'),
    t('Notas'),
    t('Acciones'),
    t('<a href="/company/[cid]" target="_blank">Ver</a>
<br />
<a href="/company/[cid]/edit" target="_blank">Editar</a>'),
    t('Nombre de la empresa'),
    t('Localización'),
    t('Page'),
  );
  $export['manage_partner'] = $view;

  $view = new view();
  $view->name = 'partners_by_year';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'company';
  $view->human_name = 'Empresas colaboradores por año';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
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
      'field' => 'field_partner_year_sponsor',
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
      'field_partner_web' => 'field_partner_web',
      'field_partner_year_sponsor' => 'field_partner_year_sponsor',
      'field_partner_logo' => 'field_partner_logo',
    ),
    'default' => '',
    'info' => array(
      'field_partner_web' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_partner_year_sponsor' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_partner_logo' => array(
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
    'caption' => '',
  );
  $handler->display->display_options['style_options']['grid'] = array(
    'columns' => '2',
    'alignment' => 'horizontal',
    'fill_single_line' => 1,
    'summary' => '',
    'theme' => 'views_view_grid',
    'uses_fields' => 0,
    'caption' => '',
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Empresa: Página web */
  $handler->display->display_options['fields']['field_partner_web']['id'] = 'field_partner_web';
  $handler->display->display_options['fields']['field_partner_web']['table'] = 'field_data_field_partner_web';
  $handler->display->display_options['fields']['field_partner_web']['field'] = 'field_partner_web';
  $handler->display->display_options['fields']['field_partner_web']['label'] = '';
  $handler->display->display_options['fields']['field_partner_web']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_partner_web']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_web']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_partner_web']['type'] = 'link_plain';
  /* Campo: Empresa: Años patrocinados */
  $handler->display->display_options['fields']['field_partner_year_sponsor']['id'] = 'field_partner_year_sponsor';
  $handler->display->display_options['fields']['field_partner_year_sponsor']['table'] = 'field_data_field_partner_year_sponsor';
  $handler->display->display_options['fields']['field_partner_year_sponsor']['field'] = 'field_partner_year_sponsor';
  $handler->display->display_options['fields']['field_partner_year_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_partner_year_sponsor']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_partner_year_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_year_sponsor']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_partner_year_sponsor']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_partner_year_sponsor']['delta_offset'] = '0';
  /* Campo: Empresa: Logo */
  $handler->display->display_options['fields']['field_partner_logo']['id'] = 'field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['table'] = 'field_data_field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['field'] = 'field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['label'] = '';
  $handler->display->display_options['fields']['field_partner_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_partner_logo']['alter']['path'] = '[field_partner_web]';
  $handler->display->display_options['fields']['field_partner_logo']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_partner_logo']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_partner_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partner_logo']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Criterio de ordenación: Empresa: Años patrocinados (field_partner_year_sponsor) */
  $handler->display->display_options['sorts']['field_partner_year_sponsor_tid']['id'] = 'field_partner_year_sponsor_tid';
  $handler->display->display_options['sorts']['field_partner_year_sponsor_tid']['table'] = 'field_data_field_partner_year_sponsor';
  $handler->display->display_options['sorts']['field_partner_year_sponsor_tid']['field'] = 'field_partner_year_sponsor_tid';
  $handler->display->display_options['sorts']['field_partner_year_sponsor_tid']['order'] = 'DESC';
  /* Criterio de ordenación: Global: Aleatorio */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Criterios de filtrado: Empresa: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'company';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'partner' => 'partner',
  );
  /* Criterios de filtrado: Empresa: Años patrocinados (field_partner_year_sponsor) */
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['id'] = 'field_partner_year_sponsor_tid';
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['table'] = 'field_data_field_partner_year_sponsor';
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['field'] = 'field_partner_year_sponsor_tid';
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['value'] = '';
  $handler->display->display_options['filters']['field_partner_year_sponsor_tid']['vocabulary'] = 'anios';
  /* Criterios de filtrado: Empresa: Logo (field_partner_logo:alt) */
  $handler->display->display_options['filters']['field_partner_logo_alt']['id'] = 'field_partner_logo_alt';
  $handler->display->display_options['filters']['field_partner_logo_alt']['table'] = 'field_data_field_partner_logo';
  $handler->display->display_options['filters']['field_partner_logo_alt']['field'] = 'field_partner_logo_alt';
  $handler->display->display_options['filters']['field_partner_logo_alt']['operator'] = 'not empty';

  /* Display: Panel de contenido */
  $handler = $view->new_display('panel_pane', 'Panel de contenido', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'Paneles de vista';
  $translatables['partners_by_year'] = array(
    t('Master'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Ascendente'),
    t('Desc'),
    t('Panel de contenido'),
    t('Paneles de vista'),
  );
  $export['partners_by_year'] = $view;

  return $export;
}
