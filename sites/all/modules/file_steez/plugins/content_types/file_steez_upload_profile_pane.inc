<?php

$plugin = array(
  // the title in the admin
  'title' => t('Profile file upload form'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('File Steezy Brolorn'), -9),
  //'edit form' => 'file_steez_upload_pane_content_type_edit_form',
  'render callback' => 'file_steez_upload_profile_pane_content_type_render'
);

function file_steez_upload_profile_pane_content_type_render($subtype, $conf, $context = NULL) {
  $block = new stdClass();
 
  $user_id = $context[0];
  //printr('wut');
  $block->content = drupal_get_form('file_steez_file_profile_upload_form', $user_id);
  
  return $block;
}