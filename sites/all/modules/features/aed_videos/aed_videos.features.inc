<?php
/**
 * @file
 * aed_videos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function aed_videos_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  if ($module == "video_embed_field" && $api == "default_video_embed_styles") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function aed_videos_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function aed_videos_flag_default_flags() {
  $flags = array();
  // Exported flag: "Video visualizado".
  $flags['video_visualizado'] = array(
    'entity_type' => 'node',
    'title' => 'Video visualizado',
    'global' => 0,
    'types' => array(
      0 => 'videos',
    ),
    'flag_short' => 'Marcar como visto',
    'flag_long' => 'Marcar este vídeo como visto',
    'flag_message' => '',
    'unflag_short' => 'Desmarcar como visto',
    'unflag_long' => 'Quitar la marca de video visto',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'aed_videos',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

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
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function aed_videos_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Videos",
    "machine_name" : "default_node_index",
    "description" : "Videos sobre DrupalCamps, DrupalDays y eventos patrocinados o apoyados por la AED. ",
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_ranges_alter" : { "status" : 0, "weight" : "-50", "settings" : [] },
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "videos" : "videos" } }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_video_ponente:parents_all" : "field_video_ponente:parents_all",
              "field_videos_audiencia:parents_all" : "field_videos_audiencia:parents_all",
              "field_videos_evento:parents_all" : "field_videos_evento:parents_all",
              "field_videos_idioma:parents_all" : "field_videos_idioma:parents_all",
              "field_videos_nivel:parents_all" : "field_videos_nivel:parents_all",
              "field_videos_version:parents_all" : "field_videos_version:parents_all",
              "field_category:parents_all" : "field_category:parents_all"
            }
          }
        },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 1,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "comment_count" : { "type" : "integer" },
        "created" : { "type" : "date" },
        "field_category" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_video_ponente" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_videos_ano" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_videos_audiencia" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_videos_evento" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_videos_idioma" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_videos_nivel" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_videos_version" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "flag_video_visualizado_user" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "user" },
        "nid" : { "type" : "integer" },
        "promote" : { "type" : "boolean" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_sort().
 */
function aed_videos_default_search_api_sort() {
  $items = array();
  $items['default_node_index__created'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "created",
    "name" : "Fecha de creaci\\u00f3n",
    "enabled" : "0",
    "weight" : "0",
    "identifier" : "default_node_index__created",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Date created" },
    "rdf_mapping" : []
  }');
  $items['default_node_index__search_api_relevance'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "search_api_relevance",
    "name" : "Relevance",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "default_node_index__search_api_relevance",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "search_api_relevance" },
    "rdf_mapping" : []
  }');
  return $items;
}
