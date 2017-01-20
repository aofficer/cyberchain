<?php

$plugin = array(
  // the title in the admin
  'title' => t('Rate widgets'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Rate'), -9),
  'edit form' => 'rate_panels_rate_widget_pane_edit_form',
  'render callback' => 'rate_panels_rate_widget_pane_render'
);

function rate_panels_rate_widget_pane_render($subtype, $conf, $args) {
  $block = new stdClass();
  
  $block->content = '';
  //printr($args);
  $node_id = $args[0];
  //printr($conf);
  
  $widgets = array();
  foreach ($conf['widgets'] as $widget_id => $yesno) {
    if ($yesno) {
      $block->content .= rate_generate_widget($widget_id, 'node', $node_id);
      //$widgets[$widget_id] = rate_generate_widget($widget_id, 'node', $node_id);
    }
  }
  
  //$block->content = 'derp';
  
  return $block;
}

function rate_panels_rate_widget_pane_edit_form($form, &$form_state) {
  $widgets = variable_get(RATE_VAR_WIDGETS, array());
  //printr($widgets);
  $widget_options = array();
  foreach ($widgets as $widget_id => $widget) {
    $widget_options[$widget_id] = $widget->title;
  }
  $form['widgets'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Widget'),
    '#options' => $widget_options,
    '#default_value' => !empty($form_state['conf']['widgets']) ? $form_state['conf']['widgets'] : '',
  );
  
  return $form;
}

function rate_panels_rate_widget_pane_edit_form_submit($form, &$form_state) {
  $form_state['conf']['widgets'] = $form_state['values']['widgets'];
}
