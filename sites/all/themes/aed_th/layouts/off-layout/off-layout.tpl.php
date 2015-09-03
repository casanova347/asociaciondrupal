<div<?php print $attributes; ?>>

  <?php if (!empty($page['heading'])) : ?>
    <div class="l-heading">
      <div class="l-container">
        <?php print render($page['heading']); ?>
      </div>
    </div>
  <?php endif; ?>

  <header class="l-header" role="banner">
    <div class="l-container">

      <div class="l-branding">
        <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-logo">
            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
          </a>
        <?php endif; ?>

        <?php if ($site_name || $site_slogan): ?>
          <?php if ($site_name): ?>
            <span class="site-name">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"
                 rel="home"><span><?php print $site_name; ?></span></a>
            </span>
          <?php endif; ?>

          <?php if ($site_slogan): ?>
            <h2 class="site-slogan"><?php print $site_slogan; ?></h2>
          <?php endif; ?>
        <?php endif; ?>

        <?php print render($page['branding']); ?>
      </div>

      <?php print render($page['header']); ?>
    </div>

    <?php if (!empty($page['navigation'])) : ?>
      <div class="relative">
        <div id="off-canvas" class="l-off-canvas">
          <div class="l-container">
            <span class="off-canvas-toggler"><span>Menu</span></span>
            <?php print render($page['navigation']); ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

  </header>


  <?php if (!empty($breadcrumb)) : ?>
    <div class="breadcrumb-region">
      <div class="l-container">
        <?php if ($title): ?><h1><?php print $title; ?></h1><?php endif; ?>
        <?php print $breadcrumb; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($messages)) : ?>
    <div class="l-messajes">
      <div class="l-container">
        <?php print $messages; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($page['pre_content'])) : ?>
    <div class="l-pre-content">
      <?php print render($page['pre_content']); ?>
    </div>
  <?php endif; ?>

  <div class="l-content" role="main">
    <?php print render($page['highlighted']); ?>
    <div class="l-container">
      <?php print render($title_prefix); ?>
      <?php print render($title_suffix); ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>



      <div class="content">
        <?php print render($page['content']); ?>
      </div>

      <?php print render($page['sidebar_first']); ?>

      <?php print render($page['sidebar_second']); ?>
    </div>
  </div>

  <?php if (!empty($page['post_content'])) : ?>
    <div class="l-post-content">
      <div class="l-container">
        <?php print render($page['post_content']); ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($page['footer'])) : ?>
    <footer class="l-footer" role="contentinfo">
      <div class="l-container">
        <?php print render($page['footer']); ?>
      </div>
    </footer>
  <?php endif; ?>

  <?php if (!empty($page['post_footer'])) : ?>
    <footer class="l-post-footer">
      <div class="l-container">
        <?php print render($page['post_footer']); ?>
      </div>
    </footer>
  <?php endif; ?>
</div>
