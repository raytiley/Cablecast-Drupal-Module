<?php
/**
 * @file
 * Drush commands for the cablecast module.
 */

function cablecast_drush_command() {
  $items = array();

  $items['cablecast-cron'] = array(
    'description' => "Runs the Cablecast Cron",
    'examples' => array('drush ccron' => ''),
    'aliases' => array('ccron'),
  );

  return $items;

}

function drush_cablecast_cron() {
  cablecast_cron();
}