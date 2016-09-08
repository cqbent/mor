<?php

/**
 * Get notes for referring_url/current url and
 * return as list including edit/delete etc...
 *
 * @param $variables -> contains:
 *             $variables['referring_url'] = url for notes
 *             $variables['notes'] = an array of all notes for referring url
 * @TODO: Customize include better themeing for listing.
 */

/* SYP: customized stickynote theme list */
function theme_mor_stickynote_list($variables) {
  $output = '';
  $notes = array();
  global $user;
  if (isset($variables['notes']) && intval($variables['notes']->rowCount())) {
    foreach ($variables['notes'] as $key => $stickynote) {
      if (_stickynote_view_access($stickynote)) {
        $note_class = 'note-' . $stickynote->snid;
        //$account = user_load($stickynote->uid);
        $updated = format_date($stickynote->updated, variable_get('stickynote_date_format', 'short'));
        $edit = l(t('edit'), 'mor-stickynote/' . $stickynote->snid . '/edit', array('attributes' => array('class' => array('use-ajax'))));
        $delete = l(t('delete'), 'mor-stickynote/' . $stickynote->snid . '/delete_confirm', array('attributes' => array('class' => array('use-ajax'))));
        $note = nl2br(filter_xss($stickynote->note));
        $data  =  '<div class="note-item '.$note_class.'"><div class="updated">' . $updated . '</div><div class="note">' . $note . '</div>';
        if ($stickynote->uid == $user->uid) {  // only logged in user can edit/delete their own notes
          $data .= '<div class="edit">' . $edit .'</div><div class="delete">' . $delete .'</div>';
        }
        $data .= '</div>';
        $notes[] = array(
            'data' => $data,
        );
      }
    }
    $variables = array(
        'items' => $notes,
        'type' => 'ul'
    );
    $output = theme('item_list', $variables);
  }
  return $output;
}


/**
 * Return confirmation links for deletion
 *
 * @param $variables
 */
function theme_mor_stickynote_confirm($variables) {
  $stickynote = $variables['stickynote'];
  $token = drupal_get_token($stickynote->snid);

  $output = '';
  $output .= '<td colspan="5" id="note-' . $stickynote->snid . '">';
  $output .= '<div id="confirm-delete-' . $stickynote->snid . '" style="text-align: center;">';
  $output .= 'Are you sure?</br>';
  $output .= l(t('Delete'), 'mor-stickynote/' . $stickynote->snid . '/delete', array(
    'attributes' => array('class' => array('use-ajax')),
    'query' => array('token' => $token),
  ));
  $output .= '&nbsp;&nbsp;&nbsp;&nbsp;';
  $output .= l(t('Cancel'), 'mor-stickynote/' . $stickynote->snid . '/cancel', array('attributes' => array('class' => array('use-ajax'))));
  $output .= '</div>';


  $output .= '</td>';


  return $output;
}
