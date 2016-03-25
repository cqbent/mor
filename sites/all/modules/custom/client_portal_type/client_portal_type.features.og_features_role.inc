<?php
/**
 * @file
 * client_portal_type.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function client_portal_type_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:client_portal:coach'.
  $roles['node:client_portal:coach'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'client_portal',
    'name' => 'coach',
  );

  // Exported OG Role: 'node:client_portal:participant'.
  $roles['node:client_portal:participant'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'client_portal',
    'name' => 'participant',
  );

  return $roles;
}
