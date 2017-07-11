<?php

function bulk_comment_delete_drush_command() {
  $items  = array();
  $items['bulk-comment-delete'] = array(
    'callback'    => 'bulk_comment_delete_setup_batch',
    'description' => 'perform bulk comment delete process',
    'aliases' => array('bcd'),
    'arguments' => array(
      'number' => "number",
    ),
  );
  return $items;
}