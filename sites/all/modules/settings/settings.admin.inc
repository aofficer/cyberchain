<?php

function settings_voting_settings($form) {
  $flags = flag_get_flags();
  $flag_options = array();
  foreach ($flags as $fid => $flag) {
    $flag_options[$fid] = $flag->name;
  }
  $form['settings_vote_up_flag'] = array(
    '#type' => 'select',
    '#title' => t('Vote up'),
    '#description' => t('Which flag should be designated the Vote Up flag?'),
    '#options' => $flag_options,
    '#default_value' => variable_get('settings_vote_up_flag', ''),
  );
  $form['settings_vote_up_points'] = array(
    '#type' => 'textfield',
    '#title' => t('Vote up points'),
    '#description' => t('How many points should be awarded to a user when their content gets voted up?'),
    '#default_value' => variable_get('settings_vote_up_points', ''),
    '#size' => 1,
  );
  $form['settings_vote_down_flag'] = array(
    '#type' => 'select',
    '#title' => t('Vote down'),
    '#description' => t('Which flag should be designated the Vote Down flag?'),
    '#options' => $flag_options,
    '#default_value' => variable_get('settings_vote_down_flag', ''),
  );
  $form['settings_vote_down_points'] = array(
    '#type' => 'textfield',
    '#title' => t('Vote down points'),
    '#description' => t('How many points should be taken away from a user when their content gets voted down?'),
    '#default_value' => variable_get('settings_vote_down_points', ''),
    '#size' => 1,
  );

  return system_settings_form($form);
}

function settings_misc_settings() {
  $form = array();
  
  $form['settings_initiative_entity'] = array(
    '#type' => 'select',
    '#title' => t('Group initiative entity'),
    '#description' => t('Which content type shoud we define as being the one used for initiatives?'),
    '#options' => node_type_get_names(),
    '#default_value' => variable_get('settings_initiative_entity', ''),
  );
  
  $form['webform_node_types_primary'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Primary webform node type'),
    '#description' => t('This content type will get a nice redirect when it is submitted.'),
    '#options' => node_type_get_names(),
    '#default_value' => webform_variable_get('webform_node_types_primary'),
  );
  
  return system_settings_form($form);
}

function settings_misc_settings_validate($form, &$form_state) {
  $primary_node_types = array();
  foreach ($form_state['values']['webform_node_types_primary'] as $type => $yesno) {
    if ($yesno) {
      $primary_node_types[$type] = $type;
    }
  }
  
  $form_state['values']['webform_node_types_primary'] = $primary_node_types;
}
