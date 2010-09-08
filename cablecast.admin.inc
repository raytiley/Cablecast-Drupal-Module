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
	$form['cablecast_default_location'] = array(
		'#type'	=>	'textfield',
		'#title'	=>	t('Location ID'),
		'#default_value'	=>	variable_get('cablecast_default_location_id', '22'),
		'#size'	=>	'3',
		'#description'	=>	t("Your Cablecast Location ID - Read Documentation for how to obtain"),
		'#maxlength'	=>	'3',
		);
	$form['cablecast_default_channel']  = array(
		'#type'  =>  'textfield',
		'#title'  =>  t('Default Channel ID'),
		'#default_value'  =>  variable_get('cablecast_default_channel', '1'),
		'#size'  =>  '3',
		'#description'  =>  t("A Cablecast Channel ID available at your location."),
		'#maxLength'  =>  '3',
		);
	return system_settings_form($form);
}