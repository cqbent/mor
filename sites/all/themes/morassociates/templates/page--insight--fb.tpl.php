<div id="page">
  <div id="main">
        <div id="content" class="column" role="main">
            <div class="inner clearfix">
                <a name="top"></a>
                <?php print render($page['highlighted']); ?>
                <?php print $breadcrumb; ?>
                <a id="main-content"></a>
                <?php if(isset($node) && $node->type == 'blog'): ?>
                
                <p class="submitted"><?php print format_date($node->created, 'minimal'); ?></p>
                <?php endif; ?>
                <?php print render($title_prefix); ?>
                <?php if ($title): ?>
                <h1 class="title" id="page-title"><?php print $title; ?></h1>
                <?php endif; ?>
                <?php print render($title_suffix); ?>
                <?php print $messages; ?>
                <?php print render($tabs); ?>
                <?php print render($page['help']); ?>
                <?php if ($action_links): ?>
                <ul class="action-links"><?php print render($action_links); ?></ul>
                <?php endif; ?>
				<?php print render($page['content']); ?>
                
            <?php print $feed_icons; ?>
            </div>
        </div><!-- /#content -->
  </div><!-- /#main -->

</div><!-- /#page -->