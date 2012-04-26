<?php
/**
 * @file
 * campuswiki_groups.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function campuswiki_groups_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer group.
  $permissions['administer group'] = array(
    'name' => 'administer group',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'og',
  );

  // Exported permission: create group content.
  $permissions['create group content'] = array(
    'name' => 'create group content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any group content.
  $permissions['delete any group content'] = array(
    'name' => 'delete any group content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own group content.
  $permissions['delete own group content'] = array(
    'name' => 'delete own group content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any group content.
  $permissions['edit any group content'] = array(
    'name' => 'edit any group content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own group content.
  $permissions['edit own group content'] = array(
    'name' => 'edit own group content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: view users outside groups.
  $permissions['view users outside groups'] = array(
    'name' => 'view users outside groups',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'spaces_og',
  );

  return $permissions;
}
