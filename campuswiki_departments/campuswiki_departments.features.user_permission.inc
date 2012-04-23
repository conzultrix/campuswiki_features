<?php
/**
 * @file
 * campuswiki_departments.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function campuswiki_departments_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete terms in 4.
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 4.
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
