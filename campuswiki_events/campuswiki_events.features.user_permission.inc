<?php
/**
 * @file
 * campuswiki_events.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function campuswiki_events_user_default_permissions() {
  $permissions = array();

  // Exported permission: create event content.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: create rsvp content.
  $permissions['create rsvp content'] = array(
    'name' => 'create rsvp content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any event content.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any rsvp content.
  $permissions['delete any rsvp content'] = array(
    'name' => 'delete any rsvp content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own event content.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own rsvp content.
  $permissions['delete own rsvp content'] = array(
    'name' => 'delete own rsvp content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any event content.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any rsvp content.
  $permissions['edit any rsvp content'] = array(
    'name' => 'edit any rsvp content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own event content.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own rsvp content.
  $permissions['edit own rsvp content'] = array(
    'name' => 'edit own rsvp content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
