<?php
/**
 * @file
 * aed_company.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function aed_company_taxonomy_default_vocabularies() {
  return array(
    'paises' => array(
      'name' => 'Países y regiones',
      'machine_name' => 'paises',
      'description' => 'Estructura todos los países, comunidades, provincias',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
