<?php
/**
 * @file
 * drush commands for stanford_pingdash.
 */

/**
 * Implements hook_drush_command().
 *
 * @return array List of drush commands.
 */

function tas_dash_drush_command() {
  $items = array();

  $items['tas-dash-version'] = array(
    'description' => 'Get TAS version information',
    'aliases' => array('tdv'),
  );

  $items['tas-dash-get-all-agents'] = array(
    'description' => 'Get all TAS agents',
    'aliases' => array('tdgaa'),
  );
  return $items;
}

function drush_tas_dash_version() {
  tas_dash_wsclient_version();
  drush_log(dt("Retrieved TAS version."), "ok");
}

function drush_tas_dash_get_all_agents() {
  tas_dash_wsclient_get_all_agents();
  drush_log(dt("Retrieved all TAS agents."), "ok");
}

