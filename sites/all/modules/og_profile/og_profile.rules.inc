<?php

/** Implements hook_rules_action_info() **/
function og_profile_rules_action_info() {
  $actions = array();
  
  $actions['mail_to_users_with_group_preference'] = array(
    'label' => t('Send mail to all users of a group with a certain preference.'),
    'group' => t('Organic groups'),
    'parameter' => array(
      'group' => array(
        'type' => 'group',
        'label' => t('Group'),
        'description' => t('The group which members of a certain role will get email.')
      ),
      'prefs' => array(
        'type' => 'list<integer>',
        'label' => t('Preferences'),
        'options list' => 'og_profile_prefs_list',
        'description' => t('Select the preferences that users should have to receive the mail.'),
      ),
      'subject' => array(
        'type' => 'text',
        'label' => t('Subject'),
        'description' => t("The mail's subject."),
      ),
      'message' => array(
        'type' => 'text',
        'label' => t('Message'),
        'description' => t("The mail's message body."),
      ),
      'from' => array(
        'type' => 'text',
        'label' => t('From'),
        'description' => t("The mail's from address. Leave it empty to use the site-wide configured address."),
        'optional' => TRUE,
      ),
    ),
    'base' => 'og_profile_action_mail_to_users_with_group_preference',
  );
  
  return $actions;
}