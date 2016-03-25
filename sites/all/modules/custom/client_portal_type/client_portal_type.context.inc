<?php
/**
 * @file
 * client_portal_type.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function client_portal_type_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'my_portal_page';
  $context->description = '';
  $context->tag = 'portal';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'portal/my-leadership-portal*' => 'portal/my-leadership-portal*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-mor_member_detail-block_2' => array(
          'module' => 'views',
          'delta' => 'mor_member_detail-block_2',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-my_readings-block' => array(
          'module' => 'views',
          'delta' => 'my_readings-block',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-my_readings-block_1' => array(
          'module' => 'views',
          'delta' => 'my_readings-block_1',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-my_interests_readings-block' => array(
          'module' => 'views',
          'delta' => 'my_interests_readings-block',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-group_coaches-block' => array(
          'module' => 'views',
          'delta' => 'group_coaches-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-mor_member_detail-block_1' => array(
          'module' => 'views',
          'delta' => 'mor_member_detail-block_1',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-mor_member_detail-block_3' => array(
          'module' => 'views',
          'delta' => 'mor_member_detail-block_3',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'stickynote-stickynote_block' => array(
          'module' => 'stickynote',
          'delta' => 'stickynote_block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('portal');
  $export['my_portal_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'my_profile';
  $context->description = '';
  $context->tag = 'portal';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'portal/my-profile' => 'portal/my-profile',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-group_coaches-block' => array(
          'module' => 'views',
          'delta' => 'group_coaches-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-portal_people-block_3' => array(
          'module' => 'views',
          'delta' => 'portal_people-block_3',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-mor_member_detail-block_3' => array(
          'module' => 'views',
          'delta' => 'mor_member_detail-block_3',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('portal');
  $export['my_profile'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'my_program';
  $context->description = '';
  $context->tag = 'portal';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'portal/my-program' => 'portal/my-program',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-personal_portal-block_1' => array(
          'module' => 'views',
          'delta' => 'personal_portal-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-personal_portal-block_2' => array(
          'module' => 'views',
          'delta' => 'personal_portal-block_2',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-portal_people-block_4' => array(
          'module' => 'views',
          'delta' => 'portal_people-block_4',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-portal_people-block_3' => array(
          'module' => 'views',
          'delta' => 'portal_people-block_3',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-portal_calendar-block_2' => array(
          'module' => 'views',
          'delta' => 'portal_calendar-block_2',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('portal');
  $export['my_program'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'people_page';
  $context->description = '';
  $context->tag = 'portal';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'portal/people' => 'portal/people',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-portal_people-block_1' => array(
          'module' => 'views',
          'delta' => 'portal_people-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-portal_people-block_2' => array(
          'module' => 'views',
          'delta' => 'portal_people-block_2',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('portal');
  $export['people_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'portal_pages';
  $context->description = '';
  $context->tag = 'portal';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'portal/*' => 'portal/*',
        '~portal/my-leadership-portal' => '~portal/my-leadership-portal',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-group_coaches-block' => array(
          'module' => 'views',
          'delta' => 'group_coaches-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-mor_member_detail-block_1' => array(
          'module' => 'views',
          'delta' => 'mor_member_detail-block_1',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-mor_og_members-block_2' => array(
          'module' => 'views',
          'delta' => 'mor_og_members-block_2',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'views-portal_calendar-block_2' => array(
          'module' => 'views',
          'delta' => 'portal_calendar-block_2',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'stickynote-stickynote_block' => array(
          'module' => 'stickynote',
          'delta' => 'stickynote_block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('portal');
  $export['portal_pages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'workshop_page';
  $context->description = '';
  $context->tag = 'portal';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'portal_workshop' => 'portal_workshop',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-workshop_info-block_1' => array(
          'module' => 'views',
          'delta' => 'workshop_info-block_1',
          'region' => 'sidebar_second',
          'weight' => '-45',
        ),
        'views-workshop_info-block_2' => array(
          'module' => 'views',
          'delta' => 'workshop_info-block_2',
          'region' => 'sidebar_second',
          'weight' => '-44',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('portal');
  $export['workshop_page'] = $context;

  return $export;
}
