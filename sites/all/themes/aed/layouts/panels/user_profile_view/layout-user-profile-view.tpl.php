<?php
/**
 * @var $content array con las regiones (los panes)
 */
?>
<div class="plugin_layout_user_profile_view panel-display clearfix" <?php if (!empty($css_id)) {
  print "id=\"$css_id\"";
}?>>

    <table class="heading clearfix">
        <tr>
        <td class="region region-foto">
          <?php print $content['foto']; ?>
        </td>

        <td class="region region-nombre">
          <?php print $content['nombre']; ?>
        </td>
        </tr>
    </table>

    <div class="conten-zone clearfix">

      <?php if ($content['contenido-header']): ?>
        <div class="region region-contenido-header">
          <?php print $content['contenido-header']; ?>
        </div>
      <?php endif; ?>

      <?php if ($content['contenido']): ?>
        <div class="region region-contenido">
          <?php print $content['contenido']; ?>
        </div>
      <?php endif; ?>

      <?php if ($content['contenido-footer']): ?>
        <div class="region region-contenido-footer">
          <?php print $content['contenido-footer']; ?>
        </div>
      <?php endif; ?>
    </div>

</div>
