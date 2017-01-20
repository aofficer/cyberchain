<?php

$plugin = array(
  // the title in the admin
  'title' => t('File upload form'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('File Steezy Brolorn'), -9),
  //'edit form' => 'file_steez_upload_pane_content_type_edit_form',
  'render callback' => 'file_steez_upload_pane_content_type_render'
);

/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function file_steez_upload_pane_content_type_render($subtype, $conf, $context = NULL) {
  $block = new stdClass();
 
  $node_id = $context[0];
  $block->content = drupal_get_form('file_steez_file_upload_form', $node_id);
  
  return $block;
}
