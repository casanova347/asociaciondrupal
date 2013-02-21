<?php

$plugin = array(
  'title' => t('Views field user profile'),
  'category' => 'Layouts personalizados',
  'icon' => 'icono.png',
  'theme' => 'views_field_layout_user_profile_view',
  'css' => 'views_field_user_profile_view.css',
  'regions' => array(
    'foto' => t('Foto'),
    'nombre' => t('Nombre'),
    'fields' => t('Fields'),
  ),
);
