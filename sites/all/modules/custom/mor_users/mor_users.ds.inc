<?php
/**
 * @file
 * mor_users.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function mor_users_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|default';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'edit_profile' => array(
      'weight' => '12',
      'label' => 'above',
      'format' => 'default',
    ),
    'full_name' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'ds_user_picture' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_picture_thumbnail',
    ),
  );
  $export['user|user|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|profile';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'profile';
  $ds_fieldsetting->settings = array(
    'edit_profile' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'full_name' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'ds_user_picture' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_picture_mor_thumbnail',
    ),
  );
  $export['user|user|profile'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function mor_users_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'edit_profile';
  $ds_field->label = 'Edit Profile';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<p><a href="[user:edit-url]">Edit My Profile</a></p>
',
      'format' => 'full_html',
    ),
    'use_token' => 1,
  );
  $export['edit_profile'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'full_name';
  $ds_field->label = 'Full Name';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[user:field_first_name] [user:field_last_name]',
      'format' => 'plain_text',
    ),
    'use_token' => 1,
  );
  $export['full_name'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function mor_users_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|default';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_personal_info',
        1 => 'ds_user_picture',
        2 => 'full_name',
        3 => 'field_user_title',
        4 => 'field_client_affiliation',
        5 => 'field_user_position',
        6 => 'field_phone',
        7 => 'field_organization',
        8 => 'field_user_bio',
        9 => 'field_user_address',
        10 => 'field_goals',
        11 => 'field_360_raters_progress',
        12 => 'edit_profile',
      ),
    ),
    'fields' => array(
      'group_personal_info' => 'ds_content',
      'ds_user_picture' => 'ds_content',
      'full_name' => 'ds_content',
      'field_user_title' => 'ds_content',
      'field_client_affiliation' => 'ds_content',
      'field_user_position' => 'ds_content',
      'field_phone' => 'ds_content',
      'field_organization' => 'ds_content',
      'field_user_bio' => 'ds_content',
      'field_user_address' => 'ds_content',
      'field_goals' => 'ds_content',
      'field_360_raters_progress' => 'ds_content',
      'edit_profile' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['user|user|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|profile';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'profile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'edit_profile',
        1 => 'ds_user_picture',
        2 => 'group_personal_info',
        3 => 'group_contact_info',
        4 => 'full_name',
        5 => 'field_user_title',
        6 => 'group_bio_interests',
        7 => 'og_user_node',
        8 => 'field_user_bio',
        9 => 'field_user_position',
        10 => 'field_organization',
        11 => 'field_interests',
        12 => 'field_client_affiliation',
        13 => 'field_user_address',
        14 => 'field_phone',
      ),
    ),
    'fields' => array(
      'edit_profile' => 'ds_content',
      'ds_user_picture' => 'ds_content',
      'group_personal_info' => 'ds_content',
      'group_contact_info' => 'ds_content',
      'full_name' => 'ds_content',
      'field_user_title' => 'ds_content',
      'group_bio_interests' => 'ds_content',
      'og_user_node' => 'ds_content',
      'field_user_bio' => 'ds_content',
      'field_user_position' => 'ds_content',
      'field_organization' => 'ds_content',
      'field_interests' => 'ds_content',
      'field_client_affiliation' => 'ds_content',
      'field_user_address' => 'ds_content',
      'field_phone' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['user|user|profile'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|token';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'token';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_first_name',
        1 => 'field_last_name',
        2 => 'field_user_title',
        3 => 'field_phone',
        4 => 'field_user_position',
        5 => 'field_organization',
        6 => 'field_user_bio',
        7 => 'field_user_address',
      ),
    ),
    'fields' => array(
      'field_first_name' => 'ds_content',
      'field_last_name' => 'ds_content',
      'field_user_title' => 'ds_content',
      'field_phone' => 'ds_content',
      'field_user_position' => 'ds_content',
      'field_organization' => 'ds_content',
      'field_user_bio' => 'ds_content',
      'field_user_address' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['user|user|token'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function mor_users_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'profile';
  $ds_view_mode->label = 'Profile';
  $ds_view_mode->entities = array(
    'user' => 'user',
  );
  $export['profile'] = $ds_view_mode;

  return $export;
}