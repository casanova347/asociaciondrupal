<?php
/**
 * @file
 * aed_company.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function aed_company_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'company-partner-field_partner_casos_de_exito'
  $field_instances['company-partner-field_partner_casos_de_exito'] = array(
    'bundle' => 'partner',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Descripción pormenorizada de los casos de éxito de la empresa. Campo público.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'company',
    'field_name' => 'field_partner_casos_de_exito',
    'label' => 'Casos de éxito',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'company-partner-field_partner_compact_logo'
  $field_instances['company-partner-field_partner_compact_logo'] = array(
    'bundle' => 'partner',
    'deleted' => 0,
    'description' => 'Si dispone de una versión compacta de su logo agréguela. Quedará mejor si la queremos colocar en un banner en el que nos veamos limitados por el espacio.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'company',
    'field_name' => 'field_partner_compact_logo',
    'label' => 'Logo compacto',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '500x500',
      'min_resolution' => '100x100',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'company-partner-field_partner_contact'
  $field_instances['company-partner-field_partner_contact'] = array(
    'bundle' => 'partner',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'company',
    'field_name' => 'field_partner_contact',
    'label' => 'Persona de contacto',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'company-partner-field_partner_descripcion'
  $field_instances['company-partner-field_partner_descripcion'] = array(
    'bundle' => 'partner',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Descripción pública de la empresa. Será visible si se muestra desplegada.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'company',
    'field_name' => 'field_partner_descripcion',
    'label' => 'Descripción',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'company-partner-field_partner_location'
  $field_instances['company-partner-field_partner_location'] = array(
    'bundle' => 'partner',
    'default_value' => array(
      0 => array(
        'tid' => 13,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'company',
    'field_name' => 'field_partner_location',
    'label' => 'Lugar de operaciones',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'term_reference_tree',
      'settings' => array(
        'cascading_selection' => 0,
        'filter_view' => '',
        'leaves_only' => 0,
        'max_depth' => '',
        'parent_term_id' => '',
        'select_parents' => 0,
        'start_minimized' => 1,
        'token_display' => '',
        'track_list' => 0,
      ),
      'type' => 'term_reference_tree',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'company-partner-field_partner_logo'
  $field_instances['company-partner-field_partner_logo'] = array(
    'bundle' => 'partner',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'partner_deployed',
        ),
        'type' => 'image',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'company',
    'field_name' => 'field_partner_logo',
    'label' => 'Logo',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'partner_companies',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '2000x2000',
      'min_resolution' => '100x100',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'company-partner-field_partner_mail'
  $field_instances['company-partner-field_partner_mail'] = array(
    'bundle' => 'partner',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'company',
    'field_name' => 'field_partner_mail',
    'label' => 'Mail de contacto',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'company-partner-field_partner_notes'
  $field_instances['company-partner-field_partner_notes'] = array(
    'bundle' => 'partner',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'company',
    'field_name' => 'field_partner_notes',
    'label' => 'Notas',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'company-partner-field_partner_oferta_de_empleo'
  $field_instances['company-partner-field_partner_oferta_de_empleo'] = array(
    'bundle' => 'partner',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Si la empresa dispone de ofertas de empleo, aquí se pueden detallar y poner enlaces externos hacia ella.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'company',
    'field_name' => 'field_partner_oferta_de_empleo',
    'label' => 'Oferta de empleo',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'company-partner-field_partner_phone'
  $field_instances['company-partner-field_partner_phone'] = array(
    'bundle' => 'partner',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'company',
    'field_name' => 'field_partner_phone',
    'label' => 'Teléfono de contacto',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'company-partner-field_partner_slogan'
  $field_instances['company-partner-field_partner_slogan'] = array(
    'bundle' => 'partner',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'company',
    'field_name' => 'field_partner_slogan',
    'label' => 'Eslogan',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'company-partner-field_partner_web'
  $field_instances['company-partner-field_partner_web'] = array(
    'bundle' => 'partner',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'company',
    'field_name' => 'field_partner_web',
    'label' => 'Página web',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'company-partner-field_partner_year_sponsor'
  $field_instances['company-partner-field_partner_year_sponsor'] = array(
    'bundle' => 'partner',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'company',
    'field_name' => 'field_partner_year_sponsor',
    'label' => 'Años patrocinados',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Años patrocinados');
  t('Casos de éxito');
  t('Descripción');
  t('Descripción pormenorizada de los casos de éxito de la empresa. Campo público.');
  t('Descripción pública de la empresa. Será visible si se muestra desplegada.');
  t('Eslogan');
  t('Logo');
  t('Logo compacto');
  t('Lugar de operaciones');
  t('Mail de contacto');
  t('Notas');
  t('Oferta de empleo');
  t('Persona de contacto');
  t('Página web');
  t('Si dispone de una versión compacta de su logo agréguela. Quedará mejor si la queremos colocar en un banner en el que nos veamos limitados por el espacio.');
  t('Si la empresa dispone de ofertas de empleo, aquí se pueden detallar y poner enlaces externos hacia ella.');
  t('Teléfono de contacto');

  return $field_instances;
}
