<?php
/**
 * @file
 * mor_users.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mor_users_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_info|user|user|profile';
  $field_group->group_name = 'group_contact_info';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'profile';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Info',
    'weight' => '2',
    'children' => array(
      0 => 'field_phone',
      1 => 'field_user_address',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact Info',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-contact-info field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_contact_info|user|user|profile'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_goals_progress|user|user|profile';
  $field_group->group_name = 'group_goals_progress';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'profile';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Goals & Progress',
    'weight' => '3',
    'children' => array(
      0 => 'field_goals',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Goals & Progress',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-goals-progress field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_goals_progress|user|user|profile'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal_info|user|user|default';
  $field_group->group_name = 'group_personal_info';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_user_title',
      1 => 'field_user_position',
      2 => 'field_organization',
      3 => 'full_name',
      4 => 'ds_user_picture',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-personal-info field-group-div',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_personal_info|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal_info|user|user|profile';
  $field_group->group_name = 'group_personal_info';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'profile';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal Info',
    'weight' => '1',
    'children' => array(
      0 => 'field_user_title',
      1 => 'field_user_position',
      2 => 'field_organization',
      3 => 'field_client_affiliation',
      4 => 'full_name',
      5 => 'ds_user_picture',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Personal Info',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-personal-info field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_personal_info|user|user|profile'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_progress_workflow|user|user|form';
  $field_group->group_name = 'group_progress_workflow';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Progress Workflow',
    'weight' => '16',
    'children' => array(
      0 => 'field_360_raters_progress',
      1 => 'field_essay_progress',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-progress-workflow field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_progress_workflow|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact Info');
  t('Goals & Progress');
  t('Personal Info');
  t('Progress Workflow');

  return $field_groups;
}
