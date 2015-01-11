<?php
/**
 * @file
 * aed_videos.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function aed_videos_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'videos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'Videos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'videos-search-list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Buscar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_videos_video' => 'field_videos_video',
    'title' => 'title',
    'body' => 'title',
    'video_visualizado' => 'field_videos_video',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_videos_video' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'video_visualizado' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<img src="/sites/default/files/no-results.jpg" />
<p>Estos no son los androides que buscas</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Indexed Node: Video */
  $handler->display->display_options['fields']['field_videos_video']['id'] = 'field_videos_video';
  $handler->display->display_options['fields']['field_videos_video']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_videos_video']['field'] = 'field_videos_video';
  $handler->display->display_options['fields']['field_videos_video']['label'] = '';
  $handler->display->display_options['fields']['field_videos_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_videos_video']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['field_videos_video']['type'] = 'video_embed_field_thumbnail';
  $handler->display->display_options['fields']['field_videos_video']['settings'] = array(
    'image_style' => '150x100',
    'image_link' => 'content',
  );
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_class'] = 'snippet';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: views_field_flag: Link para flag de Video visualizado */
  $handler->display->display_options['fields']['video_visualizado']['id'] = 'video_visualizado';
  $handler->display->display_options['fields']['video_visualizado']['table'] = 'views_field_flag';
  $handler->display->display_options['fields']['video_visualizado']['field'] = 'video_visualizado';
  $handler->display->display_options['fields']['video_visualizado']['label'] = '';
  $handler->display->display_options['fields']['video_visualizado']['element_label_colon'] = FALSE;
  /* Sort criterion: Indexed Node: Año */
  $handler->display->display_options['sorts']['field_videos_ano']['id'] = 'field_videos_ano';
  $handler->display->display_options['sorts']['field_videos_ano']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['field_videos_ano']['field'] = 'field_videos_ano';
  $handler->display->display_options['sorts']['field_videos_ano']['order'] = 'DESC';
  /* Sort criterion: Indexed Node: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 's';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    9 => 0,
    8 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'title' => 'title',
    'body:value' => 'body:value',
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );

  /* Display: Panel de contenido */
  $handler = $view->new_display('panel_pane', 'Panel de contenido', 'videos_search_list');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['pane_category']['name'] = 'Paneles de vista';
  $translatables['videos'] = array(
    t('Master'),
    t('más'),
    t('Buscar'),
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
    t('<img src="/sites/default/files/no-results.jpg" />
<p>Estos no son los androides que buscas</p>'),
    t('Panel de contenido'),
    t('more'),
    t('Paneles de vista'),
  );
  $export['videos'] = $view;

  return $export;
}
