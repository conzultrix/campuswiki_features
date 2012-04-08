<?php
/**
 * @file
 * campuswiki_departments.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function campuswiki_departments_taxonomy_default_vocabularies() {
  return array(
    'campus_audience' => array(
      'name' => 'Campus Audience',
      'machine_name' => 'campus_audience',
      'description' => 'Structure the campus into faculty and department',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '0',
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
