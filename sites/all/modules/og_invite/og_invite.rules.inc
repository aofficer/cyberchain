<?php

/** Implements hook_rules_event_info() **/
function og_invite_rules_event_info() {
  return array(
    'og_invite_non_member_invited' => array(
      'label' => t('Non-site-member is invited to join a group.'),
      'group' => t('OG Invite'),
      'variables' => array(
        'group' => array(
          'type' => 'node',
          'label' => t('Initiative'),
        ),
        'invitee_email' => array(
          'type' => 'text',
          'label' => t('Invitee email'),
        ),
        'inviter' => array(
          'type' => 'user',
          'label' => t('Inviter'),
        ),
        'hash' => array(
          'type' => 'text',
          'label' => t('Hash'),
        ),
      ),
    ),
    'og_invite_member_invited' => array(
      'label' => t('Site member is invited to join a group.'),
      'group' => t('OG Invite'),
      'variables' => array(
        'group' => array(
          'type' => 'node',
          'label' => t('Initiative'),
        ),
        'invitee' => array(
          'type' => 'user',
          'label' => t('Invitee'),
        ),
        'inviter' => array(
          'type' => 'user',
          'label' => t('Inviter'),
        ),
        'hash' => array(
          'type' => 'text',
          'label' => t('Hash'),
        ),
      ),
    ),
  );
}
