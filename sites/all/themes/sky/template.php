<?php
// Sky by Adaptivethemes.com

/**
 * Override or insert variables into the html template.
 */
function sky_preprocess_html(&$vars) {
  global $theme_key;

  $theme_name = 'sky';

  // Load the media queries styles
  $media_queries_css = array(
    $theme_name . '.responsive.style.css',
    $theme_name . '.responsive.gpanels.css'
  );
  load_subtheme_media_queries($media_queries_css, $theme_name);

  // Add a class for the active color scheme
  if (module_exists('color')) {
    $class = check_plain(get_color_scheme_name($theme_key));
    $vars['classes_array'][] = 'color-scheme-' . drupal_html_class($class);
  }

  // Add class for the active theme
  $vars['classes_array'][] = drupal_html_class($theme_key);
  
  // Browser sniff and add a class, unreliable but quite useful
  $vars['classes_array'][] = css_browser_selector();

  // Add theme settings classes
  $settings_array = array(
    'font_size',
    'box_shadows',
    'body_background',
    'menu_bullets',
    'content_corner_radius',
    'tabs_corner_radius',
    'image_alignment',
  );
  foreach ($settings_array as $setting) {
    $vars['classes_array'][] = theme_get_setting($setting);
  }

  // Fonts
  $fonts = array(
    'bf'  => 'base_font',
    'snf' => 'site_name_font',
    'ssf' => 'site_slogan_font',
    'ptf' => 'page_title_font',
    'ntf' => 'node_title_font',
    'ctf' => 'comment_title_font',
    'btf' => 'block_title_font'
  );
  $families = get_font_families($fonts, $theme_key);
  if (!empty($families)) {
    foreach ($families as $family) {
      $vars['classes_array'][] = $family;
    }
  }

  // Headings styles
  if (theme_get_setting('headings_styles_caps') == 1) {
    $vars['classes_array'][] = 'hs-caps';
  }
  if (theme_get_setting('headings_styles_weight') == 1) {
    $vars['classes_array'][] = 'hs-fwn';
  }
  if (theme_get_setting('headings_styles_shadow') == 1) {
    $vars['classes_array'][] = 'hs-ts';
  }
}

/**
 * Hook into the color module.
 */
function sky_process_html(&$vars) {
  if (module_exists('color')) {
    _color_html_alter($vars);
  }
}
function sky_process_page(&$vars) {
  if (module_exists('color')) {
    _color_page_alter($vars);
  }
}

/**
 * Override or insert variables into the block template.
 */
function sky_preprocess_block(&$vars) {
  if ($vars['block']->module == 'superfish' || $vars['block']->module == 'nice_menu') {
    $vars['content_attributes_array']['class'][] = 'clearfix';
  }
  if (!$vars['block']->subject) {
    $vars['content_attributes_array']['class'][] = 'no-title';
  }
  if ($vars['block']->region == 'menu_bar' || $vars['block']->region == 'top_menu') {
    $vars['title_attributes_array']['class'][] = 'element-invisible';
  }
}

/**
 * Override or insert variables into the field template.
 */
function sky_preprocess_field(&$vars) {
  $element = $vars['element'];
  $vars['classes_array'][] = 'view-mode-' . $element['#view_mode'];
  $vars['image_caption_teaser'] = FALSE;
  $vars['image_caption_full'] = FALSE;
  if (theme_get_setting('image_caption_teaser') == 1) {
    $vars['image_caption_teaser'] = TRUE;
  }
  if (theme_get_setting('image_caption_full') == 1) {
    $vars['image_caption_full'] = TRUE;
  }
  $vars['field_view_mode'] = '';
  $vars['field_view_mode'] = $element['#view_mode'];
}

function sky_preprocess_initiative_header(&$vars) {
  $vars['node'] = node_load($vars['nid']);
  $vars['group'] = og_get_group('node', $vars['nid']);
  $vars['manager'] = user_load($vars['node']->uid);
  $vars['manager_name'] = theme('username', array('account' => $vars['manager']));
  $vars['established'] = format_date($vars['node']->created);
  $vars['member_count'] = helpers_og_count_members($vars['group']->gid);
  $vars['report_count'] = helpers_og_count_node_type($vars['group']->gid, 'report');
  if (isset($vars['node']->field_group_logo['und'][0]['uri'])) {
    $vars['logo'] = theme('image', array('path' => $vars['node']->field_group_logo['und'][0]['uri']));
  }
  else {
    $default_fid = helpers_get_field_default_value('node', 'field_group_logo', 'initiative');
    $file = file_load($default_fid);
    $vars['logo'] = theme('image', array('path' => $file->uri));
    //drupal_set_message(printr($default));
  }
  //drupal_set_message(printr($vars['node']));
}

function sky_preprocess_kewlogin_welcome(&$vars) {
  //drupal_set_message(printr($vars));
}

function sky_preprocess_node(&$vars) {
  $node = $vars['node'];
  //printr($vars);
  $bundles = helpers_get_initiative_audience_bundles();
  //printr($bundles);
  //if (in_array($node->type, array('report',)))
}

function sky_preprocess_webform_submission_page(&$vars) {
  if (arg(0) == 'user' && arg(2) == 'surveys' && is_numeric(arg(3))) {
    // we are probably viewing this submission on a Page module generated page
    // unfortunately there's no unified way of determining this so we're stuck
    // with this ugly ass code for now
    //print 'yes';
    $vars['theme_hook_suggestions'][] = 'webform_submission_page__profile';
  }
}

function sky_facetapi_title(&$vars) {
  return t('!title', array('!title' => $vars['title']));
}
