<?php

$plugin = array(
  // the title in the admin
  'title' => t('Capability maturity score'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Webform'), -9),
  //'edit form' => 'page_steez_page_pane_content_type_edit_form',
  'render callback' => 'capability_maturity_score_render',
);

function capability_maturity_score_render($subtype, $conf, $args) {
  global $user;
  
  $block = new stdClass();
  
  if (isset($args[0])) {
    $uid = $args[0];
  }
  else {
    $uid = $user->uid;
  }

  $scores = capability_maturity_get_implementation_tier_scores($uid);
  
  $maturity_levels = capability_maturity_get_levels($uid);
  //printr($maturity_levels);
  $components = capability_maturity_get_components();
  $block->content = theme('capability_maturity_levels', array('maturity_levels' => $maturity_levels, 'components' => $components, 'tier_scores' => $scores));
  //printr($block);
  return $block;
}