<?php
/**
 * @file
 * kh_settings.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function kh_settings_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'keystone_habits-day-field_practice_days'.
  $field_instances['keystone_habits-day-field_practice_days'] = array(
    'bundle' => 'day',
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
    ),
    'entity_type' => 'keystone_habits',
    'field_name' => 'field_practice_days',
    'label' => 'Practice Days',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'keystone_habits-week-field_note'.
  $field_instances['keystone_habits-week-field_note'] = array(
    'bundle' => 'week',
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
    ),
    'entity_type' => 'keystone_habits',
    'field_name' => 'field_note',
    'label' => 'Note',
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

  // Exported field_instance: 'keystone_habits-week-field_practice_done'.
  $field_instances['keystone_habits-week-field_practice_done'] = array(
    'bundle' => 'week',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Was practice done',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'keystone_habits',
    'field_name' => 'field_practice_done',
    'label' => 'Practice Done',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Note');
  t('Practice Days');
  t('Practice Done');
  t('Was practice done');

  return $field_instances;
}
