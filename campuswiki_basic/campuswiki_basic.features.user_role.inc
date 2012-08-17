<?php
/**
 * @file
 * campuswiki_basic.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function campuswiki_basic_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '3',
  );

  // Exported role: manager.
  $roles['manager'] = array(
    'name' => 'manager',
    'weight' => '2',
  );

  return $roles;
}
