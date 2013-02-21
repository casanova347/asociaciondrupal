<?php

$plugin = array(
  'title' => t('User profile view'),
  'category' => 'Layouts personalizados',
  'icon' => 'icono.png',
  'theme' => 'layout_user_profile_view',
  'css' => 'user_profile_view.css',

  'admin theme' => 'admin_layout_user_profile_view',
  'admin css' => 'user_profile_view.admin.css',

  'regions' => array(
    'foto' => t('Foto'),
    'nombre' => t('Nombre'),
    'contenido-footer' => t('Contenido footer'),
    'contenido' => t('Contenido'),
    'contenido-header' => t('Contenido header'),
  ),
);
