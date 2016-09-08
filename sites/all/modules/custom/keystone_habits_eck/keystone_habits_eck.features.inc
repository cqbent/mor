<?php
/**
 * @file
 * keystone_habits_eck.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function keystone_habits_eck_eck_bundle_info() {
  $items = array(
    'keystone_habit_daily' => array(
      'machine_name' => 'keystone_habit_daily',
      'entity_type' => 'keystone_habit',
      'name' => 'daily',
      'label' => 'daily',
      'config' => array(),
    ),
    'keystone_habit_weekly' => array(
      'machine_name' => 'keystone_habit_weekly',
      'entity_type' => 'keystone_habit',
      'name' => 'weekly',
      'label' => 'weekly',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function keystone_habits_eck_eck_entity_type_info() {
  $items = array(
    'keystone_habit' => array(
      'name' => 'keystone_habit',
      'label' => 'Keystone Habit',
      'properties' => array(
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
      ),
    ),
  );
  return $items;
}
