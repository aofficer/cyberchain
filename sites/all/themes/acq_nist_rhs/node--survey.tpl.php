<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> <?php print $zebra; ?> clearfix"<?php print $attributes; ?>>

  <?php //print $user_picture; ?>

  <?php if (isset($icon)) : print render($icon); endif; ?>
  
  <div class="float-overflow tb-terminal">
    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <div class="content"<?php print $content_attributes; ?>>
      <?php
        // Hide elements of the content and render them later.
        hide($content['field_assessment_type']);
        hide($content['field_assessment_part']);
        hide($content['field_assessment_order']);
        hide($content['comments']);
        hide($content['links']);
        
        /* Check if it is set or hiding it will render an empty node to appear as if it has content.*/
        if(!empty($content['addthis'])) {
          hide($content['addthis']);
        }
        
        /* Check if it is set or hiding it will render an empty node to appear as if it has content.*/
        if(!empty($content['field_tags'])) {
          hide($content['field_tags']);
        }
        print render($content);
      ?>
    </div>
    
    <?php if(!empty($content['field_tags'])) : ?>
      <div class="tags">
        <?php print render($content['field_tags']); ?>
      </div>
    <?php endif; ?>
    
    <?php if(!empty($content['addthis'])) : ?>
      <div class="social">
        <?php print render($content['addthis']); ?>
      </div>
    <?php endif; ?>
    
  </div>

  <?php
    if (isset($content['links']['comment'])) {
      hide($content['links']['comment']);
    }
    print render($content['links']);
    if (isset($content['links']['comment'])) {
      print render($content['links']['comment']);
    }
  ?>

  <?php print render($content['comments']); ?>

</div>
