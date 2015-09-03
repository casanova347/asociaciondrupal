<div<?php print $attributes; ?>>

  <div class="l-admin">
    <div class="l-container">
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
    </div>
  </div>

  <?php if (!empty($page['one'])): ?>
    <div class="l-one">
      <div class="mobile-menu">
        <div class="close"></div>
      </div>
      <?php print render($page['one']); ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($page['two'])): ?>
    <div class="l-two">
      <?php print render($page['two']); ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($page['three'])): ?>
    <div class="l-three">
      <?php print render($page['three']); ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($page['four'])): ?>
    <div class="l-four">
      <?php print render($page['four']); ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($page['five'])): ?>
    <div class="l-five">
      <?php print render($page['five']); ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($page['six'])): ?>
    <div class="l-six">
      <?php print render($page['six']); ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($page['seven'])): ?>
    <div class="l-seven">
      <?php print render($page['seven']); ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($page['eight'])): ?>
    <div class="l-eight">
      <?php print render($page['eight']); ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($page['nine'])): ?>
    <div class="l-nine">
      <?php print render($page['nine']); ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($page['ten'])): ?>
    <div class="l-ten">
      <?php print render($page['ten']); ?>
    </div>
  <?php endif; ?>

</div>
