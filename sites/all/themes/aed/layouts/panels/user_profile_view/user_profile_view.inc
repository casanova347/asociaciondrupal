<?php

$plugin = array(
  'title' => t('User profile view'),
  'category' => 'Layouts personalizados',
  'icon' => 'icono.png',
  'theme' => 'layout_user_profile_view',
  'css' => 'user_profile_view.css',
  'regions' => array(
    'foto' => t('foto'),
    'nombre' => t('nombre'),
    'contenido-footer' => t('Contenido footer'),
    'contenido' => t('contenido'),
    'contenido-header' => t('Contenido header'),
  ),
);
