<?php
/**
 * @file
 * keystone_habits_eck.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function keystone_habits_eck_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_keystone_habit_category'.
  $field_bases['field_keystone_habit_category'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_keystone_habit_category',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Presence' => 'Presence - what you generate when you show up',
        'Delegation' => 'Delegation - developing greater capacity in your workgroup',
        'Building Relationships' => 'Building Relationships - extending your network',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_keystone_habit_note'.
  $field_bases['field_keystone_habit_note'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_keystone_habit_note',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
