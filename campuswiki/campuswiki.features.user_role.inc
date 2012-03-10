<?php
/**
 * @file
 * campuswiki.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function campuswiki_user_default_roles() {
  $roles = array();

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '2',
  );

  // Exported role: manager
  $roles['manager'] = array(
    'name' => 'manager',
    'weight' => '3',
  );

  return $roles;
}
