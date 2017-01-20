<?php

/** Define the form for the points administration settings **/
function og_userpoints_points_settings($form, $form_state, $node) {
  // first get roles
  $group = og_get_group('node', $node->nid);
  $roles = og_roles($group->gid);
  // remove anonymuser and authenticated user roles
  unset($roles[1]);
  unset($roles[2]);
  //print_r($roles);
  $form['#gid'] = $group->gid;
  $form['levelup'] = array(
    '#type' => 'fieldset',
    '#title' => t('Level up'),
    '#description' => t('Decide how many points are needed for members of this group to reach the following roles.
                         Currently members receive <strong>!vote_up_points</strong> points when their content is 
                         voted up and lose <strong>!vote_down_points</strong> points when their content is voted down.
                         Enter <strong>0</strong> to disable the ability to level up to this role.',
                         array('!vote_up_points' => variable_get('settings_vote_up_points', 0),
                               '!vote_down_points' => variable_get('settings_vote_down_points', 0))),
    '#tree' => TRUE,
  );
  foreach ($roles as $rid => $role) {
    $form['levelup'][$rid] = array(
      '#type' => 'textfield',
      '#title' => $role,
      '#size' => 2,
      '#default_value' => og_userpoints_get_points_needed($group->gid, $rid),
      '#weight' => '-' . og_userpoints_get_clout($group->gid, $rid),
    );
  }
  
  $form['clout'] = array(
    '#type' => 'fieldset',
    '#title' => t('Clout'),
    '#description' => t('Clout is a number between 0 and 100 which determines how much influence users of a certain
                         role should have. The higher the clout the more strongly weighted their actions will be in
                         the group.'),
    '#tree' => TRUE,
  );
  foreach ($roles as $rid => $role) {
    $form['clout'][$rid] = array(
      '#type' => 'textfield',
      '#title' => $role,
      '#size' => 2,
      '#default_value' => og_userpoints_get_clout($group->gid, $rid),
      '#weight' => '-' . og_userpoints_get_clout($group->gid, $rid),
    );
  }
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['roles'] = array(
    '#type' => 'value',
    '#value' => $roles,
  );
  
  return $form;
}

/********** Form validation functions **********/

function og_userpoints_points_settings_validate($form, &$form_state) {
  foreach ($form_state['values']['roles'] as $rid => $role) {
    if (!is_numeric($form_state['values']['levelup'][$rid])) {
      form_set_error('levelup][' . $rid, t('Must be an integer.'));
    }
    if (!is_numeric($form_state['values']['clout'][$rid])) {
      form_set_error('clout][' . $rid, t('Must be an integer.'));
    }
    if ($form_state['values']['clout'][$rid] < 0 || $form_state['values']['clout'][$rid] > 100) {
      form_set_error('clout][' . $rid, t('Clout must be between 0 and 100.'));
    }
  }
}

/********** Form submit functions **********/
function og_userpoints_points_settings_submit($form, &$form_state) {
  //printr($form_state['values']);
  foreach ($form_state['values']['roles'] as $rid => $role) {
    db_merge('og_userpoints_levelup')->key(array('gid' => $form['#gid'], 'rid' => $rid))
                                     ->fields(array('points_needed' => $form_state['values']['levelup'][$rid],
                                                    'clout' => $form_state['values']['clout'][$rid]))
                                     ->execute();
  }
  
  drupal_set_message(t('Settings saved.'));
}