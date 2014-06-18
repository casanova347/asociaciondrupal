<?php
/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */
function views_filter_flag_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'views_filter_flag') . '/inc',
    ),
    'handlers' => array(
      // register our custom filter, with the class/file name and parent class
      'views_filter_flag_filter' => array(
        'parent' => 'views_handler_filter',
      )
    ),
  );
}

function views_filter_flag_views_data() {
  $data = array();

  // The flexible date filter.
  $data['node']['views_filter_flag'] = array(
    'group' => t('Custom'),
    'real field' => 'views_filter_flag',
    'title' => t('Custom Date/Term combined filter'),
    'help' => t('Filter any Views based on date and term'),
    'filter' => array(
      'handler' => 'views_filter_flag_filter'
    ),
  );

  return $data;
}