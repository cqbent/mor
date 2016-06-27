<?php
/**
 * @file
 * client_portal_type.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function client_portal_type_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|client_portal|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'client_portal';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|client_portal|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|portal_meetings|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'portal_meetings';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
  );
  $export['node|portal_meetings|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|portal_workshop|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'portal_workshop';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'node_link' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|portal_workshop|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function client_portal_type_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'portal_client_logos';
  $ds_field->label = 'Portal Client Logos';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|portal_clients-block',
    'block_render' => '3',
  );
  $export['portal_client_logos'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function client_portal_type_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|client_portal|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'client_portal';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_portal_logo',
        2 => 'field_client_reference',
        3 => 'field_portal_email',
        4 => 'body',
        5 => 'field_reading_materials',
        6 => 'field_program_reflections',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_portal_logo' => 'ds_content',
      'field_client_reference' => 'ds_content',
      'field_portal_email' => 'ds_content',
      'body' => 'ds_content',
      'field_reading_materials' => 'ds_content',
      'field_program_reflections' => 'ds_content',
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
  $export['node|client_portal|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|portal_meetings|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'portal_meetings';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_meeting_date',
        2 => 'field_meeting_location',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_meeting_date' => 'ds_content',
      'field_meeting_location' => 'ds_content',
      'body' => 'ds_content',
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
  $export['node|portal_meetings|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|portal_workshop|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'portal_workshop';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_workshop_dates',
        2 => 'body',
        3 => 'node_link',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_workshop_dates' => 'ds_content',
      'body' => 'ds_content',
      'node_link' => 'ds_content',
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
  $export['node|portal_workshop|teaser'] = $ds_layout;

  return $export;
}
