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
  $items['cw_activity_attending_event'] = entity_import('message_type', '{
    "name" : "cw_activity_attending_event",
    "description" : "CW activity attending event",
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
          "value" : "\\u003Cdiv class=\\u0022activity-message\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E is attending \\u003Ca href=\\u0022[message:field-target-node:field-rsvp-event:url]\\u0022\\u003E[message:field-target-node:field-rsvp-event]\\u003C\\/a\\u003E\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022activity-message\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E is attending \\u003Ca href=\\u0022[message:field-target-node:field-rsvp-event:url]\\u0022\\u003E[message:field-target-node:field-rsvp-event]\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
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
          "value" : "\\u003Cdiv class=\\u0022activity-message\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E created [message:field-target-node:content-type]: \\u003Ca href=\\u0022[message:field-target-node:url]\\u0022\\u003E[message:field-target-node:title]\\u003C\\/a\\u003E\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022activity-message\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E created [message:field-target-node:content-type]: \\u003Ca href=\\u0022[message:field-target-node:url]\\u0022\\u003E[message:field-target-node:title]\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['cw_activity_photo_posted'] = entity_import('message_type', '{
    "name" : "cw_activity_photo_posted",
    "description" : "CW activity photo posted",
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
          "value" : "\\u003Cdiv class=\\u0022activity-message\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E posted Photo: \\u003Ca href=\\u0022[message:field-target-node:url]\\u0022\\u003E[message:field-target-node:title]\\u003C\\/a\\u003E in \\u003Ca href=\\u0022[message:field-target-node:field-photo-gallery:url]\\u0022\\u003E[message:field-target-node:field-photo-gallery]\\u003C\\/a\\u003E\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022activity-message\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E posted Photo: \\u003Ca href=\\u0022[message:field-target-node:url]\\u0022\\u003E[message:field-target-node:title]\\u003C\\/a\\u003E in \\u003Ca href=\\u0022[message:field-target-node:field-photo-gallery:url]\\u0022\\u003E[message:field-target-node:field-photo-gallery]\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\n"
        },
        {
          "value" : "\\u003Cdiv class=\\u0022activity-photo\\u0022\\u003E[message:field-target-node:field_photo_photo]\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022activity-photo\\u0022\\u003E[message:field-target-node:field_photo_photo]\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['cw_activity_user_join_group'] = entity_import('message_type', '{
    "name" : "cw_activity_user_join_group",
    "description" : "CW activity user join group",
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
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:picture]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cdiv class=\\u0022activity-message\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E joined \\u003Ca href=\\u0022[message:field-node-target-group:0:url]\\u0022\\u003E[message:field-node-target-group:0:title]\\u003C\\/a\\u003E group.\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022activity-message\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E joined \\u003Ca href=\\u0022[message:field-node-target-group:0:url]\\u0022\\u003E[message:field-node-target-group:0:title]\\u003C\\/a\\u003E group.\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['cw_activity_user_profile_updated'] = entity_import('message_type', '{
    "name" : "cw_activity_user_profile_updated",
    "description" : "CW activity user profile updated",
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
          "value" : "\\u003Cdiv class=\\u0022activity-message\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E has an updated profile\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022activity-message\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E has an updated profile\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['cw_activity_wiki_edited'] = entity_import('message_type', '{
    "name" : "cw_activity_wiki_edited",
    "description" : "CW activity wiki edited",
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
          "value" : "\\u003Cdiv class=\\u0022activity-message\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E updated [message:field-target-node:content-type]: \\u003Ca href=\\u0022[message:field-target-node:url]\\u0022\\u003E[message:field-target-node:title]\\u003C\\/a\\u003E\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022activity-message\\u0022\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E updated [message:field-target-node:content-type]: \\u003Ca href=\\u0022[message:field-target-node:url]\\u0022\\u003E[message:field-target-node:title]\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
