<?php
/**
 * @file
 * aed_profile2_socio.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function aed_profile2_socio_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_profile2_type().
 */
function aed_profile2_socio_default_profile2_type() {
  $items = array();
  $items['socio'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "socio",
    "label" : "Personal data",
    "weight" : "0",
    "data" : {
      "registration" : 0,
      "use_one_page" : 1,
      "user_custom_visibility" : [
        "field_nombre",
        "field_apellidos",
        "field_perfil_en_drupal_org",
        "field_perfil_facebook",
        "field_perfil_linkedin",
        "field_perfil_twitter",
        "field_perfil_google_plus",
        "field_pagina_web",
        "field_foto",
        "field_que_haces_en_drupal"
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
