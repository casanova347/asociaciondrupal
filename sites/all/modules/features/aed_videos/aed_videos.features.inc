<?php
/**
 * @file
 * aed_videos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function aed_videos_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "video_embed_field" && $api == "default_video_embed_styles") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function aed_videos_node_info() {
  $items = array(
    'videos' => array(
      'name' => t('Videos'),
      'base' => 'node_content',
      'description' => t('AED Videos'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
