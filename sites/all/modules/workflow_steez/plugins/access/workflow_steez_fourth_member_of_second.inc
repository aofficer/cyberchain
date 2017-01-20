<?php

/**
 * @file
 * Plugin to provide access control based on existence of a specified context.
 */

$plugin = array(
  'title' => t("Fourth member of second"),
  'description' => t('Check to see if fourth argument is member of second. Assume both are nodes.'),
  'callback' => 'workflow_steez_fourth_member_of_second',
  'summary' => 'workflow_steez_fourth_member_of_second_summary',
  'required context' => array(new ctools_context_required(t('Initiative node'), 'node'),
                              new ctools_context_required(t('Node'), 'node')),
);

/**
 * Check for access.
 */
function workflow_steez_fourth_member_of_second($conf, $context) {
  if (empty($context)) {
    return FALSE;
  }
  //printr($context);
  $initiative_node = $context[0]->data;
  $node = $context[1]->data;
  // get group audience
  //printr($node);
  $node_audience_gid = $node->group_audience['und'][0]['gid'];
  $node_audience = og_load_entity_from_group($node_audience_gid);
 // printr($node_audience);
  if ($node_audience->nid == $initiative_node->nid) {
    return TRUE;
  }

  return FALSE;
}

function workflow_steez_fourth_member_of_second_summary($conf, $context) {
  
}
