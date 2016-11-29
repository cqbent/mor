<?php
/**
 * @file
 * client_portal_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function client_portal_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function client_portal_type_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function client_portal_type_node_info() {
  $items = array(
    'client_portal' => array(
      'name' => t('Client Portal'),
      'base' => 'node_content',
      'description' => t('Client only content'),
      'has_title' => '1',
      'title_label' => t('Program Title'),
      'help' => '',
    ),
    'portal_meetings' => array(
      'name' => t('Portal Meetings'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'portal_workshop' => array(
      'name' => t('Portal Workshop'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'program_reflections' => array(
      'name' => t('Program Reflections'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Reflection Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
