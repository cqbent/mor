<?php
/**
 * @file
 * og_content_notification.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function og_content_notification_default_rules_configuration() {
  $items = array();
  $items['og_mor_og_new_content_notification'] = entity_import('rules_config', '{ "og_mor_og_new_content_notification" : {
      "LABEL" : "MOR OG new content notification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "og", "rules" ],
      "ON" : { "node_insert--portal_content" : { "bundle" : "portal_content" } },
      "IF" : [
        { "og_entity_is_group_content" : { "entity" : [ "node" ] } },
        { "AND" : [] },
        { "data_is" : { "data" : [ "node:field-email-members" ], "value" : 1 } }
      ],
      "DO" : [
        { "og_get_members" : {
            "USING" : { "group_content" : [ "node" ] },
            "PROVIDE" : { "group_members" : { "group_members" : "List of group members" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-members" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : [ "list-item:mail" ],
                  "subject" : "New post in portal [node:og-group-ref]",
                  "message" : "Hello [list-item:name],\\r\\n\\r\\nThere is a new post called [node:title] that belongs to the the portal you are subscribed to. \\r\\n\\r\\nView at [node:url]\\r\\n\\r\\n[site:name]",
                  "from" : [ "" ],
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_test_rule'] = entity_import('rules_config', '{ "rules_test_rule" : {
      "LABEL" : "Test Rule",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "og", "rules" ],
      "ON" : { "node_insert--portal_content" : { "bundle" : "portal_content" } },
      "IF" : [
        { "og_entity_is_group_content" : { "entity" : [ "node" ] } },
        { "AND" : [] },
        { "data_is" : { "data" : [ "node:field-email-members" ], "value" : 1 } }
      ],
      "DO" : [
        { "og_get_members" : {
            "USING" : { "group_content" : [ "node" ] },
            "PROVIDE" : { "group_members" : { "group_members" : "List of group members" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-members" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : [ "list-item:mail" ],
                  "subject" : "New post in portal",
                  "message" : "Hello [list-item:name],\\r\\n\\r\\nThere is a new post called [node:title] that belongs to the the portal you are subscribed to. \\r\\n\\r\\nView at [node:url]\\r\\n\\r\\n[site:name]",
                  "from" : [ "" ],
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
