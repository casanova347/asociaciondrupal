<?php

/**
 * @file
 * Default simple view template to display a rows in a grid.
 *
 * - $rows contains a nested array of rows. Each row contains an array of
 *   columns.
 *
 * @ingroup views_templates
 */
//We nedd ensure thats no conflict if more than one views tab
$seed = rand(0, 9990);
?>

<div class="views-tabs clearfix">
    <ul>
      <?php for ($i = 0; $i < count($tabs); $i++): ?>
        <li><a href="#tab-content-<?php print $i . "-" . $seed; ?>"><?php print $tabs[$i]; ?></a></li>
      <?php endfor; ?>
    </ul>

  <?php for ($i = 0; $i < count($content_tabs); $i++): ?>
    <div id="tab-content-<?php print $i . "-" . $seed; ?>">
      <?php print $content_tabs[$i]; ?>
    </div>
  <?php endfor; ?>

</div>