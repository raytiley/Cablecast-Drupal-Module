<?php
/**
 * @file
 * Drush commands for the cablecast module.
 */

function cablecast_drush_command() {
  $items = array();

  $items['cablecast-get-channels'] = array(
    'description' => "Prints a list of channels on Cablecast server.",
    'arguments' => array(),
    'options' => array(),
    'examples' => array('drush ccgc' => '<Channels>'),
    'aliases' => array('ccgc'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap at all.
  );

  $items['cablecast-get-schedule'] = array(
    'description' => "Gets the future schedule for each channel.",
    'arguments' => array(),
    'options' => array(),
    'examples' => array('drush ccgs' => '<Channels>'),
    'aliases' => array('ccgs'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap at all.
  );

    $items['cablecast-get-updated-shows'] = array(
    'description' => "Gets shows modified in the last 24 hours",
    'arguments' => array(),
    'options' => array(),
    'examples' => array('drush ccus' => '<Channels>'),
    'aliases' => array('ccus'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap at all.
  );

  $items['cablecast-get-locations'] = array(
    'description' => "Gets cablecast locations",
    'arguments' => array(),
    'options' => array(),
    'examples' => array('drush ccgl' => '<Channels>'),
    'aliases' => array('ccgl'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap at all.
  );

  return $items;

}

function drush_cablecast_get_channels() {
  $controller = cablecast_api_get_controller('http://frontdoor.ctn5.org');
  $channels = $controller->getChannels();
  print_r($channels);
}

function drush_cablecast_get_schedule() {
  $controller = cablecast_api_get_controller('http://frontdoor.ctn5.org');
  $channels = $controller->getChannels();

  $scheduleItems = array();
  
  foreach ($channels as $channel) {
    $result = $controller->getSchedule(
      $channel->getID(), 
      new DateTime(), 
      new DateTime('@' . (time() + 60*60*24*14))
      );

    print_r($result);
  }
}

function drush_cablecast_get_updated_shows() {
  $searchDate = new DateTime('@' . (time() - 60*60*24*4));
  $controller = cablecast_api_get_controller('http://frontdoor.ctn5.org');
  $shows = $controller->getModifiedShows(22, $searchDate);

  print_r($shows);
}

function drush_cablecast_get_locations() {
  $controller = cablecast_api_get_controller('http://frontdoor.ctn5.org');
  $locations = $controller->getLocations();
  print_r($locations);
}