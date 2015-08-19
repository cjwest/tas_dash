<?php
/**
 * @file
 * tas_dash.features.inc
 */

/**
 * Implements hook_default_wsclient_service().
 */
function tas_dash_default_wsclient_service() {
  $items = array();
  $items['tas'] = entity_import('wsclient_service', '{
    "settings" : [],
    "operations" : {
      "tas_version" : {
        "url" : "api.php",
        "label" : "Get TAS Pandora Version",
        "parameter" : { "info" : { "type" : "text", "default value" : "version" } },
        "result" : { "type" : "text", "label" : "TAS Pandora Version" },
        "name" : "tas_version"
      },
      "tas_get_all_agents" : {
        "url" : "api.php",
        "label" : "Get All TAS Agents",
        "parameter" : {
          "op" : { "type" : "text", "default value" : "get" },
          "op2" : { "type" : "text", "default value" : "all_agents" },
          "other_mode" : { "type" : "text", "default value" : "url_encode_separator_|" },
          "apipass" : { "type" : "text"},
          "user" : { "type" : "text" },
          "pass" : { "type" : "text" }
        },
        "name" : "tas_get_all_agents",
        "result" : { "type" : "text", "label" : "" }
      }
    },
    "datatypes" : [],
    "global_parameters" : [],
    "name" : "tas",
    "label" : "TAS",
    "url" : "https:\\/\\/demo.theftalertsystem.com:8443\\/tas_console\\/include\\/",
    "type" : "rest",
    "authentication" : null,
    "rdf_mapping" : []
  }');
  $items['tas_version_only'] = entity_import('wsclient_service', '{
    "settings" : [],
    "operations" : { "get_version" : { "url" : "", "label" : "Get Version", "parameter" : [] } },
    "datatypes" : [],
    "global_parameters" : [],
    "name" : "tas_version_only",
    "label" : "TAS version only",
    "url" : "https:\\/\\/demo.theftalertsystem.com:8443\\/pandora_console\\/include\\/api.php?info=version",
    "type" : "rest",
    "authentication" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
