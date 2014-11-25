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
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function aed_company_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function aed_company_image_default_styles() {
  $styles = array();

  // Exported image style: partner_deployed.
  $styles['partner_deployed'] = array(
    'name' => 'partner_deployed',
    'label' => 'partner_deployed',
    'effects' => array(
      3 => array(
        'label' => 'Escala',
        'help' => 'El escalado mantiene la relación de proporciones de la imagen original. Si sólo se especifica una dimensión, la otra se calculará.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 415,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
