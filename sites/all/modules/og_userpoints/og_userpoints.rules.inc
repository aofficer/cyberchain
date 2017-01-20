<?php

/** Implements hook_rules_action_info() **/
function og_userpoints_rules_action_info() {
  return array(
    'levelup' => array(
      'label' => t('Promote users if they have achieved enough points.'),
      'parameter' => array(
        //'group' => array('label' => t('Group'), 'type' => 'group'),
        'userpoints_transaction' => array('label' => t('Points transaction'), 'type' => 'userpoints_transaction'),
        //'points' => array('label' => t('Points')),
      ),
      'group' => t('Organic groups'),
      'base' => 'og_userpoints_levelup',
    ),
  );
}
