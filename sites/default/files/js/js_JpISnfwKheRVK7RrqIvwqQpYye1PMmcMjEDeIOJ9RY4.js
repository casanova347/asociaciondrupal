Drupal.locale = { 'pluralFormula': function ($n) { return Number(($n!=1)); }, 'strings': {"":{"An AJAX HTTP error occurred.":"Hubo un error HTTP AJAX.","HTTP Result Code: !status":"C\u00f3digo de Resultado HTTP: !status","An AJAX HTTP request terminated abnormally.":"Una solicitud HTTP de AJAX termin\u00f3 de manera anormal.","Debugging information follows.":"A continuaci\u00f3n se detalla la informaci\u00f3n de depuraci\u00f3n.","Path: !uri":"Ruta: !uri","StatusText: !statusText":"StatusText: !statusText","ResponseText: !responseText":"ResponseText: !responseText","ReadyState: !readyState":"ReadyState: !readyState","Show shortcuts":"Mostrar atajos","Hide shortcuts":"Ocultar atajos","Re-order rows by numerical weight instead of dragging.":"Reordenar las filas por peso num\u00e9rico en lugar de arrastrar.","Show row weights":"Mostrar pesos de la fila","Hide row weights":"Ocultar pesos de la fila","Drag to re-order":"Arrastre para reordenar","Changes made in this table will not be saved until the form is submitted.":"Los cambios realizados en esta tabla no se guardar\u00e1n hasta que se env\u00ede el formulario","Hide":"Ocultar","Show":"Mostrar","(active tab)":"(solapa activa)","Disabled":"Desactivado","Enabled":"Activado","Edit":"Editar","From @title":"De @title","Changes to the checkout panes will not be saved until the \u003Cem\u003ESave configuration\u003C\/em\u003E button is clicked.":"Los cambios a los paneles de pedido no ser\u00e1n guardados hasta que el bot\u00f3n de \u003Cem\u003E Guardar Configuraci\u00f3n \u003C\/em\u003E sea presionado.","To @title":"A @title","Created @date":"Creado @date","New order":"Nuevo pedido","Updated @date":"Actualizado @date","Add":"Agregar","Upload":"Subir al servidor","Configure":"Configurar","Done":"Hecho","Select all":"Seleccionar todo","Select all rows in this table":"Seleccionar todas las filas de esta tabla","Deselect all rows in this table":"Quitar la selecci\u00f3n a todas las filas de esta tabla","Not published":"No publicado","Shortcuts":"Atajos","Please wait...":"Espere, por favor...","Only files with the following extensions are allowed: %files-allowed.":"S\u00f3lo se permiten archivos con las siguientes extensiones: %files-allowed.","Remove group":"Eliminar grupo","By @name on @date":"Por @name en @date","By @name":"Por @name","Not in menu":"No est\u00e1 en un men\u00fa","Alias: @alias":"Alias: @alias","No alias":"Sin alias","New revision":"Nueva revisi\u00f3n","The changes to these blocks will not be saved until the \u003Cem\u003ESave blocks\u003C\/em\u003E button is clicked.":"Los cambios sobre estos bloques no se guardar\u00e1n hasta que no pulse el bot\u00f3n \u003Cem\u003EGuardar bloques\u003C\/em\u003E.","This permission is inherited from the authenticated user role.":"Este permiso se hereda del rol de usuario registrado.","No revision":"Sin revisi\u00f3n","@number comments per page":"@number comentarios por p\u00e1gina","Requires a title":"Necesita un t\u00edtulo","Not restricted":"Sin restricci\u00f3n","Not customizable":"No personalizable","Restricted to certain pages":"Restringido a algunas p\u00e1ginas","The block cannot be placed in this region.":"El bloque no se puede colocar en esta regi\u00f3n.","Customize dashboard":"Personalizar panel de control","Hide summary":"Ocultar resumen","Edit summary":"Editar resumen","Don\u0027t display post information":"No mostrar informaci\u00f3n del env\u00edo","The selected file %filename cannot be uploaded. Only files with the following extensions are allowed: %extensions.":"El archivo seleccionado %filename no puede ser subido. Solo se permiten archivos con las siguientes extensiones: %extensions.","Autocomplete popup":"Ventana emergente con autocompletado","Searching for matches...":"Buscando coincidencias","Apply (all displays)":"Aplicar (todas las presentaciones)","Apply (this display)":"Aplicar (esta presentaci\u00f3n)","Revert to default":"Volver a los valores predeterminados","Deselect all":"Deseleccionar todo","Automatic alias":"Alias autom\u00e1tico","Available tokens":"Tokens disponibles","Insert this token into your form":"Inserta este comod\u00edn en su formulario","List additional actions":"Lista adicional de acciones","Show more":"Ver m\u00e1s","Show fewer":"Ver menos","Close":"Cerrar","Select all children":"Seleccionar todos los descendientes","Log messages":"Registrar mensajes","Please select a file.":"Seleccione un documento, por favor.","You are not allowed to operate on more than %num files.":"No tiene permiso para actuar sobre m\u00e1s de %num documentos.","Please specify dimensions within the allowed range that is from 1x1 to @dimensions.":"Especifique unas dimensiones dentro de las permitidas, por favor. Eso va desde 1 \u00d7 1 a @dimensions.","%filename is not an image.":"%filename no es una imagen.","File browsing is disabled in directory %dir.":"La exploraci\u00f3n de documentos est\u00e1 desactivada en el directorio %dir.","Do you want to refresh the current directory?":"\u00bfQuiere actualizar la vista de este directorio?","Delete selected files?":"\u00bfBorrar los documentos seleccionados?","Please select a thumbnail.":"Seleccione una minatura, por favor.","You must select at least %num files.":"Debe seleccionar al menos %num documentos.","You can not perform this operation.":"No puede realizar esta operaci\u00f3n.","Change view":"Cambiar vista"}} };;
(function ($) {
  Drupal.behaviors.vbo = {
    attach: function(context) {
      $('.vbo-views-form', context).each(function() {
        Drupal.vbo.initTableBehaviors(this);
        Drupal.vbo.initGenericBehaviors(this);
      });
    }
  }

  Drupal.vbo = Drupal.vbo || {};
  Drupal.vbo.initTableBehaviors = function(form) {
    // If the table is not grouped, "Select all on this page / all pages"
    // markup gets inserted below the table header.
    var selectAllMarkup = $('.vbo-table-select-all-markup', form);
    if (selectAllMarkup.length) {
      $('.views-table > tbody', form).prepend('<tr class="views-table-row-select-all even">></tr>');
      var colspan = $('table th', form).length;
      $('.views-table-row-select-all', form).html('<td colspan="' + colspan + '">' + selectAllMarkup.html() + '</td>');

      $('.vbo-table-select-all-pages', form).click(function() {
        Drupal.vbo.tableSelectAllPages(form);
        return false;
      });
      $('.vbo-table-select-this-page', form).click(function() {
        Drupal.vbo.tableSelectThisPage(form);
        return false;
      });
    }

    $('.vbo-table-select-all', form).show();
    // This is the "select all" checkbox in (each) table header.
    $('.vbo-table-select-all', form).click(function() {
      var table = $(this).closest('table')[0];
      $('input[id^="edit-views-bulk-operations"]:not(:disabled)', table).attr('checked', this.checked);

      // Toggle the visibility of the "select all" row (if any).
      if (this.checked) {
        $('.views-table-row-select-all', table).show();
      }
      else {
        $('.views-table-row-select-all', table).hide();
        // Disable "select all across pages".
        Drupal.vbo.tableSelectThisPage(form);
      }
    });

    // Set up the ability to click anywhere on the row to select it.
    $('.views-table tbody tr', form).click(function(event) {
      if (event.target.tagName.toLowerCase() != 'input' && event.target.tagName.toLowerCase() != 'a') {
        $('input[id^="edit-views-bulk-operations"]:not(:disabled)', this).each(function() {
          var checked = this.checked;
          // trigger() toggles the checkmark *after* the event is set,
          // whereas manually clicking the checkbox toggles it *beforehand*.
          // that's why we manually set the checkmark first, then trigger the
          // event (so that listeners get notified), then re-set the checkmark
          // which the trigger will have toggled. yuck!
          this.checked = !checked;
          $(this).trigger('click');
          this.checked = !checked;
        });
      }
    });
  }

  Drupal.vbo.tableSelectAllPages = function(form) {
    $('.vbo-table-this-page', form).hide();
    $('.vbo-table-all-pages', form).show();
    // Modify the value of the hidden form field.
    $('.select-all-rows', form).val('1');
  }
  Drupal.vbo.tableSelectThisPage = function(form) {
    $('.vbo-table-all-pages', form).hide();
    $('.vbo-table-this-page', form).show();
    // Modify the value of the hidden form field.
    $('.select-all-rows', form).val('0');
  }

  Drupal.vbo.initGenericBehaviors = function(form) {
    // Show the "select all" fieldset.
    $('.vbo-select-all-markup', form).show();

    $('.vbo-select-this-page', form).click(function() {
      $('input[id^="edit-views-bulk-operations"]', form).attr('checked', this.checked);
      $('.vbo-select-all-pages', form).attr('checked', false);

      // Toggle the "select all" checkbox in grouped tables (if any).
      $('.vbo-table-select-all', form).attr('checked', this.checked);
    });
    $('.vbo-select-all-pages', form).click(function() {
      $('input[id^="edit-views-bulk-operations"]', form).attr('checked', this.checked);
      $('.vbo-select-this-page', form).attr('checked', false);

      // Toggle the "select all" checkbox in grouped tables (if any).
      $('.vbo-table-select-all', form).attr('checked', this.checked);

      // Modify the value of the hidden form field.
      $('.select-all-rows', form).val(this.checked);
    });

    $('.vbo-select', form).click(function() {
      // If a checkbox was deselected, uncheck any "select all" checkboxes.
      if (!this.checked) {
        $('.vbo-select-this-page', form).attr('checked', false);
        $('.vbo-select-all-pages', form).attr('checked', false);
        // Modify the value of the hidden form field.
        $('.select-all-rows', form).val('0')

        var table = $(this).closest('table')[0];
        if (table) {
          // Uncheck the "select all" checkbox in the table header.
          $('.vbo-table-select-all', table).attr('checked', false);

          // If there's a "select all" row, hide it.
          if ($('.vbo-table-select-this-page', table).length) {
            $('.views-table-row-select-all', table).hide();
            // Disable "select all across pages".
            Drupal.vbo.tableSelectThisPage(form);
          }
        }
      }
    });
  }

})(jQuery);
;
(function($) {

Drupal.admin = Drupal.admin || {};
Drupal.admin.behaviors = Drupal.admin.behaviors || {};

/**
 * @ingroup admin_behaviors
 * @{
 */

/**
 * Apply active trail highlighting based on current path.
 *
 * @todo Not limited to toolbar; move into core?
 */
Drupal.admin.behaviors.toolbarActiveTrail = function (context, settings, $adminMenu) {
  if (settings.admin_menu.toolbar && settings.admin_menu.toolbar.activeTrail) {
    $adminMenu.find('> div > ul > li > a[href="' + settings.admin_menu.toolbar.activeTrail + '"]').addClass('active-trail');
  }
};

/**
 * @} End of "ingroup admin_behaviors".
 */

Drupal.admin.behaviors.shorcutcollapsed = function (context, settings, $adminMenu) {

  // Create the dropdown base 
  $("<li class=\"label\"><a>"+Drupal.t('Shortcuts')+"</a></li>").prependTo("body.menu-render-collapsed div.toolbar-shortcuts ul"); 

}

Drupal.admin.behaviors.shorcutselect = function (context, settings, $adminMenu) {

  // Create the dropdown base
  $("<select id='shortcut-menu'/>").appendTo("body.menu-render-dropdown div.toolbar-shortcuts");
    
  // Create default option "Select"
  $("<option />", {
    "selected"  :  "selected",
    "value"     :  "",
    "text"      :  Drupal.t('Shortcuts')
  }).appendTo("body.menu-render-dropdown div.toolbar-shortcuts select");
    
  // Populate dropdown with menu items
  $("body.menu-render-dropdown div.toolbar-shortcuts a").each(function() {
    var el = $(this);
    $("<option />", {
      "value"   :  el.attr("href"),
      "text"    :  el.text()
    }).appendTo("body.menu-render-dropdown div.toolbar-shortcuts select");
    });
    
  $("body.menu-render-dropdown div.toolbar-shortcuts select").change(function() {
    window.location = $(this).find("option:selected").val();
  });
  
  $('body.menu-render-dropdown div.toolbar-shortcuts ul').remove();

};

})(jQuery);
;
