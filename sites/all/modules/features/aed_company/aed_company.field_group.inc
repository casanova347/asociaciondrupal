<?php
/**
 * @file
 * aed_company.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function aed_company_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|company|partner|default';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'company';
  $field_group->bundle = 'partner';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'info',
    'weight' => '0',
    'children' => array(
      0 => 'field_partner_slogan',
      1 => 'field_partner_web',
      2 => 'field_partner_descripcion',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'info',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-info',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_info|company|partner|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_partner|company|partner|form';
  $field_group->group_name = 'group_partner';
  $field_group->entity_type = 'company';
  $field_group->bundle = 'partner';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Datos de la empresa',
    'weight' => '0',
    'children' => array(
      0 => 'field_partner_compact_logo',
      1 => 'field_partner_contact',
      2 => 'field_partner_location',
      3 => 'field_partner_logo',
      4 => 'field_partner_mail',
      5 => 'field_partner_phone',
      6 => 'field_partner_slogan',
      7 => 'field_partner_web',
      8 => 'field_partner_year_sponsor',
      9 => 'field_partner_descripcion',
      10 => 'field_partner_casos_de_exito',
      11 => 'field_partner_oferta_de_empleo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Datos de la empresa',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-partner field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_partner|company|partner|form'] = $field_group;

  return $export;
}
