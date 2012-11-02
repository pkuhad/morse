<?php
// $Id$

/**
 * @file
 * Administrator page callbacks for the morse module.
 */

/**
 * Form builder. Configure Morse Settings
 *
 * @ingroup forms
 * @see system_settings_form().
 */

function morse_admin_settings() {

  $form['morse_max_level'] = array(
    '#type' => 'textfield',
    '#title' => t('Set Maximum Problem Level'),
    '#default_value' => variable_get('morse_max_level', 10),
    '#description' => t('A morse node cannot be associated with any problem level that is greater than this number'),
		'#size' => 3
  );
	
	$form['morse_max_tries'] = array(
    '#type' => 'textfield',
    '#title' => t('Set Maximum Attempts'),
    '#default_value' => variable_get('morse_max_tries', 40),
    '#description' => t('This is the default number of maximum attempts for a morse node'),
		'#size' => 3
  );
	
	$form['morse_status'] = array(
		'#type' => 'select',
		'#title' => t('Morse Status'),
		'#description' => t('Please specify Morse Status: Online/Offline'),
		'#options' => array(
			t('Online'),
			t('Offline'),
			),
			'#default_value' => variable_get('morse_status',0)
		);

  return system_settings_form($form);
}
  
/**
 * Validation of morse_admin_settings
 */
 
function morse_admin_settings_validate($form, $form_state) {
	$maxlevel =(int) $form_state['values']['morse_max_level'];
	variable_set('morse_max_level',$maxlevel);
	if(!is_int($maxlevel)) {
		form_set_error('morse_max_level', t('Maximum Level is a Number. Please enter a number.'));
	}
}
