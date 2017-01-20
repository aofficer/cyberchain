<?php

$plugin = array(
  // the title in the admin
  'title' => t('Page content'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Page'), -9),
  'edit form' => 'page_steez_page_pane_content_type_edit_form',
  'render callback' => 'page_steez_page_pane_content_type_render'
);

/** Given a path, fill in the args and pull in the content. This code sucks, make it better **/
function page_steez_page_pane_content_type_render($subtype, $conf, $args) {
  $block = new stdClass();
  
  $router = menu_get_router();
  $item = $router[$conf['content_path']];
  //printr($item);
  $content_path_args = explode('/', $conf['content_path']);
  $filled_in_content_path_args = array();
  $counter = 0;
  foreach($content_path_args as $index => $arg) {
    if ($arg == '%') {
      $replacement = $args[$counter];
      $counter++;
    }
    else {
      $replacement = $arg;
    }
    $filled_in_content_path_args[$index] = $replacement;
  }
  
  $content_path = implode('/', $filled_in_content_path_args);
  $return = menu_execute_active_handler($content_path, FALSE);
  $block->content = render($return);
  return $block;
}

function page_steez_page_pane_content_type_edit_form($form, &$form_state) {
  $router = menu_get_router();
  $options = array();
  foreach ($router as $path => $item) {
    $options[$path] = $path;
  }
  asort($options);
  $form['content_path'] = array(
    '#type' => 'select',
    '#title' => t('Path of content'),
    '#options' => $options,
    '#default_value' => !empty($form_state['conf']['content_path']) ? $form_state['conf']['content_path'] : '',
  );
  
  /*$form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );*/
  
  return $form;
}

function page_steez_page_pane_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['content_path'] = $form_state['values']['content_path'];
}
