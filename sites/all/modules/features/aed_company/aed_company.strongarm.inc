<?php
/**
 * @file
 * aed_company.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function aed_company_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_company_partner_pattern';
  $strongarm->value = 'empresa/[company:title]';
  $export['pathauto_company_partner_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_company_pattern';
  $strongarm->value = 'empresa/[company:title]';
  $export['pathauto_company_pattern'] = $strongarm;

  return $export;
}
