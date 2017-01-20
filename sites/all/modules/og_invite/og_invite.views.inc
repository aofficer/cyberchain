<?php

function og_invite_views_data() {
  $data = array();
  
  $data['og_invite']['table']['group'] = t('OG Invite');
  $data['og_invite']['table']['base'] = array(
    'field' => 'invite_id',
    'title' => t('OG Invitations'),
    'help' => t('Invitations to join groups.'),
  );
  $data['og_invite']['table']['join'] = array(
    'og' => array(
      'field' => 'gid',
      'left_field' => 'gid',
    ),
  );
  $data['og_invite']['invite_id'] = array(
    'title' => t('Invitation ID'),
    'help' => t('Unique ID for the invitation'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['og_invite']['gid'] = array(
    'title' => t('Group ID'),
    'help' => t('The group which this invitation was sent for.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'relationship' => array(
      'title' => t('OG group'),
      'help' => t('The group that the invitee was invited to.'),
      'handler' => 'views_handler_relationship',
      'base' => 'og',
      'field' => 'gid',
      'label' => t('group id'),
    ),
  );
  $data['og_invite']['invitee'] = array(
    'title' => t('Invitee'),
    'help' => t('The user who was invited.'),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'relationship' => array(
      'title' => t('Invitee'),
      'help' => t('User who was invited to the group.'),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'invitee',
      'label' => t('invitee'),
    ),
  );
  $data['og_invite']['inviter'] = array(
    'title' => t('Inviter'),
    'help' => t('The user who sent the invitation'),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'relationship' => array(
      'title' => t('Inviter'),
      'help' => t('User who did the inviting.'),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'inviter',
      'label' => t('inviter'),
    ),
  );
  $data['og_invite']['email'] = array(
    'title' => t('Email'),
    'help' => t('Email of the invitee. Only stored when the user is not already a member of the site.'),
    'field' => array(
      'handler' => 'views_handler_field_user_mail',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['og_invite']['status'] = array(
    'title' => t('Status'),
    'help' => t('Status of the invitation.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['og_invite']['extended'] = array(
    'title' => t('Extended date'),
    'help' => t('The date the invite was extended.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['og_invite']['responded'] = array(
    'title' => t('Responded date'),
    'help' => t('The date the invite was responded to.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['og_invite']['accept_link'] = array(
    'title' => t('Accept'),
    'real field' => 'hash',
    'field' => array(
      'title' => t('Accept link'),
      'help' => t('Link to accept the invitation'),
      'handler' => 'og_invite_handler_field_accept_link',
    ),
  );
  $data['og_invite']['decline_link'] = array(
    'title' => t('Decline'),
    'real field' => 'hash',
    'field' => array(
      'title' => t('Decline link'),
      'help' => t('Link to decline the invitation'),
      'handler' => 'og_invite_handler_field_decline_link',
    ),
  );
  
  return $data;
}
