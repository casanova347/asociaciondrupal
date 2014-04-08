<?php
/**
 * @file
 * aed_company.features.inc
 */

/**
 * Implements hook_default_company_type().
 */
function aed_company_default_company_type() {
  $items = array();
  $items['partner'] = entity_import('company_type', '{
    "type" : "partner",
    "label" : "Empresa colaboradora",
    "weight" : 0,
    "description" : "",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function aed_company_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function aed_company_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
