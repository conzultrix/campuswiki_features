<?php
/**
 * @file
 * campuswiki_activity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function campuswiki_activity_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function campuswiki_activity_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function campuswiki_activity_default_message_type() {
  $items = array();
  $items['cw_activity_node_created'] = entity_import('message_type', '{
    "name" : "cw_activity_node_created",
    "description" : "CW activity node created",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "[message:user:picture]",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:picture]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E created \\u003Ca href=\\u0022[message:field-target-node:url]\\u0022\\u003E[message:field-target-node:title]\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E created \\u003Ca href=\\u0022[message:field-target-node:url]\\u0022\\u003E[message:field-target-node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
