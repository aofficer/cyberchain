<?php

$plugin = array(
  // the title in the admin
  'title' => t('Group header'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Initiatives'), -9),
  //'edit form' => 'file_steez_upload_pane_content_type_edit_form',
  'render callback' => 'ui_steez_group_header_pane_content_type_render'
);

function ui_steez_group_header_pane_content_type_render($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  //drupal_set_message(printr($context));
  $block->content = theme('initiative_header', array('nid' => $context[0]));
  
  return $block;
}
