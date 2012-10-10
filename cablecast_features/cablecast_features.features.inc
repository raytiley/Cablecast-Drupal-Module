<?php
/**
 * @file
 * cablecast_features.features.inc
 */

/**
 * Implements hook_node_info().
 */
function cablecast_features_node_info() {
  $items = array(
    'cablecast_channel' => array(
      'name' => t('Cablecast Channel'),
      'base' => 'node_content',
      'description' => t('A tv channel at the cablecast server.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'cablecast_show' => array(
      'name' => t('Cablecast Show'),
      'base' => 'node_content',
      'description' => t('Represents a show from a cablecast server.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'schedule_event' => array(
      'name' => t('Schedule Event'),
      'base' => 'node_content',
      'description' => t('Defines a run of a show at a specific time. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
