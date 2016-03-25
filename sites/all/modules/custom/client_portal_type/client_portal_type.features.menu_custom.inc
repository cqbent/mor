<?php
/**
 * @file
 * client_portal_type.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function client_portal_type_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-portal-menu.
  $menus['menu-portal-menu'] = array(
    'menu_name' => 'menu-portal-menu',
    'title' => 'Portal Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Portal Menu');

  return $menus;
}
