<?php
/**
 * @file
 * aed_company.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function aed_company_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create company entities'.
  $permissions['create company entities'] = array(
    'name' => 'create company entities',
    'roles' => array(
      'Colaborador' => 'Colaborador',
      'administrator' => 'administrator',
    ),
    'module' => 'aed_company',
  );

  // Exported permission: 'edit any company entities'.
  $permissions['edit any company entities'] = array(
    'name' => 'edit any company entities',
    'roles' => array(
      'Colaborador' => 'Colaborador',
      'administrator' => 'administrator',
    ),
    'module' => 'aed_company',
  );

  // Exported permission: 'edit own company entities'.
  $permissions['edit own company entities'] = array(
    'name' => 'edit own company entities',
    'roles' => array(
      'Colaborador' => 'Colaborador',
      'administrator' => 'administrator',
    ),
    'module' => 'aed_company',
  );

  // Exported permission: 'view company entities'.
  $permissions['view company entities'] = array(
    'name' => 'view company entities',
    'roles' => array(
      'Colaborador' => 'Colaborador',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'aed_company',
  );

  return $permissions;
}
