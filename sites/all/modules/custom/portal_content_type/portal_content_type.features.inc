<?php
/**
 * @file
 * portal_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function portal_content_type_node_info() {
  $items = array(
    'portal_content' => array(
      'name' => t('Portal Content'),
      'base' => 'node_content',
      'description' => t('Portal content associated with a portal group'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
