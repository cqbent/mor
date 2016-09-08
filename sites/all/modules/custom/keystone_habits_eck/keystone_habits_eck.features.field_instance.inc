<?php
/**
 * @file
 * keystone_habits_eck.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function keystone_habits_eck_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'keystone_habit-daily-field_keystone_habit_category'.
  $field_instances['keystone_habit-daily-field_keystone_habit_category'] = array(
    'bundle' => 'daily',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'keystone_habit',
    'field_name' => 'field_keystone_habit_category',
    'label' => 'Keystone Habit Category',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'keystone_habit-weekly-field_keystone_habit_note'.
  $field_instances['keystone_habit-weekly-field_keystone_habit_note'] = array(
    'bundle' => 'weekly',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'keystone_habit',
    'field_name' => 'field_keystone_habit_note',
    'label' => 'Keystone Habit Note',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Keystone Habit Category');
  t('Keystone Habit Note');

  return $field_instances;
}
