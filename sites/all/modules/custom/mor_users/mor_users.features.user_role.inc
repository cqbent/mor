<?php
/**
 * @file
 * mor_users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function mor_users_user_default_roles() {
  $roles = array();

  // Exported role: Alumni.
  $roles['Alumni'] = array(
    'name' => 'Alumni',
    'weight' => 6,
  );

  // Exported role: Coach.
  $roles['Coach'] = array(
    'name' => 'Coach',
    'weight' => 7,
  );

  // Exported role: Participant.
  $roles['Participant'] = array(
    'name' => 'Participant',
    'weight' => 5,
  );

  // Exported role: Team Member.
  $roles['Team Member'] = array(
    'name' => 'Team Member',
    'weight' => 4,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 3,
  );

  return $roles;
}
