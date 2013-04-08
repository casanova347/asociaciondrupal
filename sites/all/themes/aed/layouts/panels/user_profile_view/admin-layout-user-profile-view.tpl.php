<?php
/**
 * @var $content array con las regiones (los panes)
 */
?>
<div class="panel-display clearfix" <?php if (!empty($css_id)) {
  print "id=\"$css_id\"";
}?>>

    <div class="region region-foto">
      <?php print $content['foto']; ?>
    </div>

    <div class="region region-nombre">
      <?php print $content['nombre']; ?>
    </div>

  <div class="clearfix"></div>

    <div class="region region-contenido-header">
      <?php print $content['contenido-header']; ?>
    </div>

    <div class="region region-contenido">
      <?php print $content['contenido']; ?>
    </div>

    <div class="region region-contenido-footer">
      <?php print $content['contenido-footer']; ?>
    </div>

</div>
