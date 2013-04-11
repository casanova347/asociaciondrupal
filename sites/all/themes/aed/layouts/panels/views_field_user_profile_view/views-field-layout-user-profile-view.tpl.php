<div class="views-field-user-profile-view clearfix" <?php if (!empty($css_id)) {
  print "id=\"$css_id\"";
}?>>

    <div class="perfil clearfix">
          <?php print $content['foto']; ?>

        <div class="datos">
            <h4 class="nombre"><?php print $content['nombre']; ?></h4>

            <div class="contenidos">
              <?php print $content['fields']; ?>
            </div>
        </div>
    </div>


</div>

