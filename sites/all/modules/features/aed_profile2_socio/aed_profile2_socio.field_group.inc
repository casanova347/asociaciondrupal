<?php
/**
 * @file
 * aed_profile2_socio.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function aed_profile2_socio_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal_data|profile2|socio|form';
  $field_group->group_name = 'group_personal_data';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'socio';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Datos personales',
    'weight' => '0',
    'children' => array(
      0 => 'field_nombre',
      1 => 'field_apellidos',
      2 => 'field_sexo',
      3 => 'field_idiomas',
      4 => 'field_pais',
      5 => 'field_perfil_en_drupal_org',
      6 => 'field_perfil_facebook',
      7 => 'field_perfil_linkedin',
      8 => 'field_perfil_twitter',
      9 => 'field_perfil_google_plus',
      10 => 'field_pagina_web',
      11 => 'field_foto',
      12 => 'field_exponer_mi_perfil',
      13 => 'field_que_haces_en_drupal',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Datos personales',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'profile2-form group-personal-data field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_personal_data|profile2|socio|form'] = $field_group;

  return $export;
}
