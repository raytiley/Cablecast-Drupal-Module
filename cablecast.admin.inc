<?php
//$ $Id: cablecast.admin.inc,v 1.1 2010/07/20 22:18:47 raytiley Exp $

/**
 * @file
 * Administration page callbacks for the cablecast module.
 */

/**
 * Form builder.  Configure Cablecast Server
 *
 * @ingroup forms
 * @see system_setings_from().
 */
function cablecast_admin_settings() {
	$form['cablecast_server_uri'] = array(
		'#type'	=>	'textfield',
		'#title'	=>	t('Server Address'),
		'#default_value'	=>	variable_get('cablecast_server_uri', 'http://demo.trms.com'),
		'#size'	=>	'60',
		'#description'	=>	t("Public address for your Cablecast Server"),
		'#maxlength'	=>	'65',
	);
	$form['cablecast_default_project_name'] = array(
    '#type'  =>  'textfield',
    '#title'  =>  t('Default Project Title'),
    '#default_value'  =>  variable_get('cablecast_default_project_name', 'misc'),
    '#size'  => '60',
    '#description'  =>  t("This is used as a project name for shows that do not belong to a Cablecast Project.  Useful for pathauto urls."),
    '#maxLength'  =>  '60',
	);
	$form['cablecast_project_shows_per_page'] = array(
	  '#type' => 'textfield',
	  '#title' => t('Shows per project page'),
	  '#default_value' => variable_get('cablecast_project_shows_per_page', 20),
	  '#size' => '3',
	  '#description' => t('This value will determine how many shows are displayed on a project page.'),
	  '#maxLength' => '3',
	);
	return system_settings_form($form);
}
