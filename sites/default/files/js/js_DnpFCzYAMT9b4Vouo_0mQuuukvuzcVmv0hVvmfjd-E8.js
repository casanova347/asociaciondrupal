Drupal.locale = { 'pluralFormula': function ($n) { return Number(($n!=1)); }, 'strings': {"":{"An AJAX HTTP error occurred.":"Hubo un error HTTP AJAX.","HTTP Result Code: !status":"C\u00f3digo de Resultado HTTP: !status","An AJAX HTTP request terminated abnormally.":"Una solicitud HTTP de AJAX termin\u00f3 de manera anormal.","Debugging information follows.":"A continuaci\u00f3n se detalla la informaci\u00f3n de depuraci\u00f3n.","Path: !uri":"Ruta: !uri","StatusText: !statusText":"StatusText: !statusText","ResponseText: !responseText":"ResponseText: !responseText","ReadyState: !readyState":"ReadyState: !readyState","Show shortcuts":"Mostrar atajos","Hide shortcuts":"Ocultar atajos","Re-order rows by numerical weight instead of dragging.":"Reordenar las filas por peso num\u00e9rico en lugar de arrastrar.","Show row weights":"Mostrar pesos de la fila","Hide row weights":"Ocultar pesos de la fila","Drag to re-order":"Arrastre para reordenar","Changes made in this table will not be saved until the form is submitted.":"Los cambios realizados en esta tabla no se guardar\u00e1n hasta que se env\u00ede el formulario","Hide":"Ocultar","Show":"Mostrar","(active tab)":"(solapa activa)","Disabled":"Desactivado","Enabled":"Activado","Edit":"Editar","Active":"Activo","From @title":"De @title","Changes to the checkout panes will not be saved until the \u003Cem\u003ESave configuration\u003C\/em\u003E button is clicked.":"Los cambios a los paneles de pedido no ser\u00e1n guardados hasta que el bot\u00f3n de \u003Cem\u003E Guardar Configuraci\u00f3n \u003C\/em\u003E sea presionado.","To @title":"A @title","Created @date":"Creado @date","New order":"Nuevo pedido","Updated @date":"Actualizado @date","Add":"Agregar","Upload":"Subir al servidor","Configure":"Configurar","Done":"Hecho","Select all":"Seleccionar todo","Select all rows in this table":"Seleccionar todas las filas de esta tabla","Deselect all rows in this table":"Quitar la selecci\u00f3n a todas las filas de esta tabla","Not published":"No publicado","Shortcuts":"Atajos","Please wait...":"Espere, por favor...","Only files with the following extensions are allowed: %files-allowed.":"S\u00f3lo se permiten archivos con las siguientes extensiones: %files-allowed.","Remove group":"Eliminar grupo","By @name on @date":"Por @name en @date","By @name":"Por @name","Not in menu":"No est\u00e1 en un men\u00fa","Alias: @alias":"Alias: @alias","No alias":"Sin alias","New revision":"Nueva revisi\u00f3n","The changes to these blocks will not be saved until the \u003Cem\u003ESave blocks\u003C\/em\u003E button is clicked.":"Los cambios sobre estos bloques no se guardar\u00e1n hasta que no pulse el bot\u00f3n \u003Cem\u003EGuardar bloques\u003C\/em\u003E.","This permission is inherited from the authenticated user role.":"Este permiso se hereda del rol de usuario registrado.","No revision":"Sin revisi\u00f3n","@number comments per page":"@number comentarios por p\u00e1gina","Requires a title":"Necesita un t\u00edtulo","Not restricted":"Sin restricci\u00f3n","Not customizable":"No personalizable","Restricted to certain pages":"Restringido a algunas p\u00e1ginas","The block cannot be placed in this region.":"El bloque no se puede colocar en esta regi\u00f3n.","Customize dashboard":"Personalizar panel de control","Hide summary":"Ocultar resumen","Edit summary":"Editar resumen","Don\u0027t display post information":"No mostrar informaci\u00f3n del env\u00edo","The selected file %filename cannot be uploaded. Only files with the following extensions are allowed: %extensions.":"El archivo seleccionado %filename no puede ser subido. Solo se permiten archivos con las siguientes extensiones: %extensions.","Autocomplete popup":"Ventana emergente con autocompletado","Searching for matches...":"Buscando coincidencias","Apply (all displays)":"Aplicar (todas las presentaciones)","Apply (this display)":"Aplicar (esta presentaci\u00f3n)","Revert to default":"Volver a los valores predeterminados","Deselect all":"Deseleccionar todo","Automatic alias":"Alias autom\u00e1tico","Available tokens":"Tokens disponibles","Insert this token into your form":"Inserta este comod\u00edn en su formulario","List additional actions":"Lista adicional de acciones","Show more":"Ver m\u00e1s","Show fewer":"Ver menos","Close":"Cerrar","Select all children":"Seleccionar todos los descendientes","Log messages":"Registrar mensajes","Please select a file.":"Seleccione un documento, por favor.","You are not allowed to operate on more than %num files.":"No tiene permiso para actuar sobre m\u00e1s de %num documentos.","Please specify dimensions within the allowed range that is from 1x1 to @dimensions.":"Especifique unas dimensiones dentro de las permitidas, por favor. Eso va desde 1 \u00d7 1 a @dimensions.","%filename is not an image.":"%filename no es una imagen.","File browsing is disabled in directory %dir.":"La exploraci\u00f3n de documentos est\u00e1 desactivada en el directorio %dir.","Do you want to refresh the current directory?":"\u00bfQuiere actualizar la vista de este directorio?","Delete selected files?":"\u00bfBorrar los documentos seleccionados?","Please select a thumbnail.":"Seleccione una minatura, por favor.","You must select at least %num files.":"Debe seleccionar al menos %num documentos.","You can not perform this operation.":"No puede realizar esta operaci\u00f3n.","Change view":"Cambiar vista"}} };;
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

(function ($) {
  Drupal.ModuleFilter = Drupal.ModuleFilter || {};
  Drupal.ModuleFilter.textFilter = '';
  Drupal.ModuleFilter.timeout;
  Drupal.ModuleFilter.tabs = {};
  Drupal.ModuleFilter.enabling = {};
  Drupal.ModuleFilter.disabling = {};

  Drupal.behaviors.moduleFilter = {
    attach: function() {
      // Set the focus on the module filter textfield.
      $('input[name="module_filter[name]"]').focus();

      $('#module-filter-squeeze').css('min-height', $('#module-filter-tabs').height());

      $('#module-filter-left a.project-tab').each(function(i) {
        Drupal.ModuleFilter.tabs[$(this).attr('id')] = new Drupal.ModuleFilter.Tab(this);
      });

      // Move anchors to top of tabs.
      $('a.anchor', $('#module-filter-left')).remove().prependTo('#module-filter-tabs');

      $('input[name="module_filter[name]"]').keyup(function(e) {
        switch (e.which) {
          case 13:
            if (Drupal.ModuleFilter.timeout) {
              clearTimeout(Drupal.ModuleFilter.timeout);
            }

            Drupal.ModuleFilter.filter(Drupal.ModuleFilter.textFilter);
            break;
          default:
            if (Drupal.ModuleFilter.textFilter != $(this).val()) {
              Drupal.ModuleFilter.textFilter = this.value;
              if (Drupal.ModuleFilter.timeout) {
                clearTimeout(Drupal.ModuleFilter.timeout);
              }
              Drupal.ModuleFilter.timeout = setTimeout('Drupal.ModuleFilter.filter("' + Drupal.ModuleFilter.textFilter + '")', 500);
            }
            break;
        }
      });
      $('input[name="module_filter[name]"]').keypress(function(e) {
        if (e.which == 13) e.preventDefault();
      });

      Drupal.ModuleFilter.showEnabled = $('#edit-module-filter-show-enabled').is(':checked');
      $('#edit-module-filter-show-enabled').change(function() {
        Drupal.ModuleFilter.showEnabled = $(this).is(':checked');
        Drupal.ModuleFilter.filter($('input[name="module_filter[name]"]').val());
      });
      Drupal.ModuleFilter.showDisabled = $('#edit-module-filter-show-disabled').is(':checked');
      $('#edit-module-filter-show-disabled').change(function() {
        Drupal.ModuleFilter.showDisabled = $(this).is(':checked');
        Drupal.ModuleFilter.filter($('input[name="module_filter[name]"]').val());
      });
      Drupal.ModuleFilter.showRequired = $('#edit-module-filter-show-required').is(':checked');
      $('#edit-module-filter-show-required').change(function() {
        Drupal.ModuleFilter.showRequired = $(this).is(':checked');
        Drupal.ModuleFilter.filter($('input[name="module_filter[name]"]').val());
      });
      Drupal.ModuleFilter.showUnavailable = $('#edit-module-filter-show-unavailable').is(':checked');
      $('#edit-module-filter-show-unavailable').change(function() {
        Drupal.ModuleFilter.showUnavailable = $(this).is(':checked');
        Drupal.ModuleFilter.filter($('input[name="module_filter[name]"]').val());
      });

      if (Drupal.settings.moduleFilter.visualAid == 1) {
        $('table.package tbody td.checkbox input').change(function() {
          if ($(this).is(':checked')) {
            Drupal.ModuleFilter.updateVisualAid('enable', $(this).parents('tr'));
          }
          else {
            Drupal.ModuleFilter.updateVisualAid('disable', $(this).parents('tr'));
          }
        });
      }

      // Check for anchor.
      var url = document.location.toString();
      if (url.match('#')) {
        // Make tab active based on anchor.
        var anchor = '#' + url.split('#')[1];
        $('a[href="' + anchor + '"]').click();
      }
      // Else if no active tab is defined, set it to the all tab.
      else if (Drupal.ModuleFilter.activeTab == undefined) {
        Drupal.ModuleFilter.activeTab = Drupal.ModuleFilter.tabs['all-tab'];
      }
    }
  }

  Drupal.ModuleFilter.visible = function(checkbox) {
    if (checkbox.length > 0) {
      if (Drupal.ModuleFilter.showEnabled) {
        if ($(checkbox).is(':checked') && !$(checkbox).is(':disabled')) {
          return true;
        }
      }
      if (Drupal.ModuleFilter.showDisabled) {
        if (!$(checkbox).is(':checked') && !$(checkbox).is(':disabled')) {
          return true;
        }
      }
      if (Drupal.ModuleFilter.showRequired) {
        if ($(checkbox).is(':checked') && $(checkbox).is(':disabled')) {
          return true;
        }
      }
    }
    if (Drupal.ModuleFilter.showUnavailable) {
      if (checkbox.length == 0 || (!$(checkbox).is(':checked') && $(checkbox).is(':disabled'))) {
        return true;
      }
    }
    return false;
  }

  Drupal.ModuleFilter.filter = function(string) {
    var stringLowerCase = string.toLowerCase();
    var flip = 'odd';

    if (Drupal.ModuleFilter.activeTab.id == 'all-tab') {
      var selector = 'table.package tbody tr td label > strong';
    }
    else {
      var selector = 'table.package tbody tr.' + Drupal.ModuleFilter.activeTab.id + '-content td label strong';
    }

    $(selector).each(function(i) {
      var $row = $(this).parents('tr');
      var module = $(this).text();
      var moduleLowerCase = module.toLowerCase();

      if (moduleLowerCase.match(stringLowerCase)) {
        if (Drupal.ModuleFilter.visible($('td.checkbox :checkbox', $row))) {
          $row.removeClass('odd even');
          $row.addClass(flip);
          $row.show();
          flip = (flip == 'odd') ? 'even' : 'odd';
        }
        else {
          $row.hide();
        }
      }
      else {
        $row.hide();
      }
    });
  }

  Drupal.ModuleFilter.Tab = function(element) {
    this.id = $(element).attr('id');
    this.element = element;

    $(this.element).click(function() {
      Drupal.ModuleFilter.tabs[$(this).attr('id')].setActive();
    });
  }

  Drupal.ModuleFilter.Tab.prototype.setActive = function() {
    if (Drupal.ModuleFilter.activeTab) {
      $(Drupal.ModuleFilter.activeTab.element).parent().removeClass('active');
    }
    // Assume the default active tab is #all-tab. Remove its active class.
    else {
      $('#all-tab').parent().removeClass('active');
    }

    Drupal.ModuleFilter.activeTab = this;
    $(Drupal.ModuleFilter.activeTab.element).parent().addClass('active');
    Drupal.ModuleFilter.activeTab.displayRows();

    // Clear filter textfield and refocus on it.
    $('input[name="module_filter[name]"]').val('');
    $('input[name="module_filter[name]"]').focus();
  }

  Drupal.ModuleFilter.Tab.prototype.displayRows = function() {
    var flip = 'odd';
    var selector = (Drupal.ModuleFilter.activeTab.id == 'all-tab') ? 'table.package tbody tr' : 'table.package tbody tr.' + this.id + '-content';
    $('table.package tbody tr').hide();
    $('table.package tbody tr').removeClass('odd even');
    $(selector).each(function(i) {
      if (Drupal.ModuleFilter.visible($('td.checkbox input', $(this)))) {
        $(this).addClass(flip);
        flip = (flip == 'odd') ? 'even' : 'odd';
        $(this).show();
      }
    });
  }

  Drupal.ModuleFilter.Tab.prototype.updateEnabling = function(amount) {
    this.enabling = this.enabling || 0;
    this.enabling += amount;
    if (this.enabling == 0) {
      delete(this.enabling);
    }
  }

  Drupal.ModuleFilter.Tab.prototype.updateDisabling = function(amount) {
    this.disabling = this.disabling || 0;
    this.disabling += amount;
    if (this.disabling == 0) {
      delete(this.disabling);
    }
  }

  Drupal.ModuleFilter.Tab.prototype.updateVisualAid = function() {
    var visualAid = '';
    if (this.enabling != undefined) {
      visualAid += '<span class="enabling">' + Drupal.t('+@count', { '@count': this.enabling }) + '</span>';
    }
    if (this.disabling != undefined) {
      visualAid += '<span class="disabling">' + Drupal.t('-@count', { '@count': this.disabling }) + '</span>';
    }

    if (!$('span.visual-aid', $(this.element)).size() && visualAid != '') {
      $(this.element).prepend('<span class="visual-aid"></span>');
    }

    $('span.visual-aid', $(this.element)).empty().append(visualAid);
  }

  Drupal.ModuleFilter.updateVisualAid = function(type, row) {
    // Find row class.
    var classes = row.attr('class').split(' ');
    for (var i in classes) {
      // Remove '-content' so we can use as id.
      var id = classes[i].substring(0, classes[i].length - 8);
      if (Drupal.ModuleFilter.tabs[id] != undefined) {
        break;
      }
    }

    if (Drupal.ModuleFilter.activeTab.id == 'all-tab') {
      var allTab = Drupal.ModuleFilter.activeTab;
      var projectTab = Drupal.ModuleFilter.tabs[id];
    }
    else {
      var allTab = Drupal.ModuleFilter.tabs['all-tab'];
      var projectTab = Drupal.ModuleFilter.activeTab;
    }

    var name = $('td label strong', row).text();
    switch (type) {
      case 'enable':
        if (Drupal.ModuleFilter.disabling[id + name] != undefined) {
          delete(Drupal.ModuleFilter.disabling[id + name]);
          allTab.updateDisabling(-1);
          projectTab.updateDisabling(-1);
          row.removeClass('disabling');
        }
        else {
          Drupal.ModuleFilter.enabling[id + name] = name;
          allTab.updateEnabling(1);
          projectTab.updateEnabling(1);
          row.addClass('enabling');
        }
        break;
      case 'disable':
        if (Drupal.ModuleFilter.enabling[id + name] != undefined) {
          delete(Drupal.ModuleFilter.enabling[id + name]);
          allTab.updateEnabling(-1);
          projectTab.updateEnabling(-1);
          row.removeClass('enabling');
        }
        else {
          Drupal.ModuleFilter.disabling[id + name] = name;
          allTab.updateDisabling(1);
          projectTab.updateDisabling(1);
          row.addClass('disabling');
        }
        break;
    }

    allTab.updateVisualAid();
    projectTab.updateVisualAid();
  }
})(jQuery);
;
(function ($) {

/**
 * Attaches sticky table headers.
 */
Drupal.behaviors.tableHeader = {
  attach: function (context, settings) {
    if (!$.support.positionFixed) {
      return;
    }

    $('table.sticky-enabled', context).once('tableheader', function () {
      $(this).data("drupal-tableheader", new Drupal.tableHeader(this));
    });
  }
};

/**
 * Constructor for the tableHeader object. Provides sticky table headers.
 *
 * @param table
 *   DOM object for the table to add a sticky header to.
 */
Drupal.tableHeader = function (table) {
  var self = this;

  this.originalTable = $(table);
  this.originalHeader = $(table).children('thead');
  this.originalHeaderCells = this.originalHeader.find('> tr > th');
  this.displayWeight = null;

  // React to columns change to avoid making checks in the scroll callback.
  this.originalTable.bind('columnschange', function (e, display) {
    // This will force header size to be calculated on scroll.
    self.widthCalculated = (self.displayWeight !== null && self.displayWeight === display);
    self.displayWeight = display;
  });

  // Clone the table header so it inherits original jQuery properties. Hide
  // the table to avoid a flash of the header clone upon page load.
  this.stickyTable = $('<table class="sticky-header"/>')
    .insertBefore(this.originalTable)
    .css({ position: 'fixed', top: '0px' });
  this.stickyHeader = this.originalHeader.clone(true)
    .hide()
    .appendTo(this.stickyTable);
  this.stickyHeaderCells = this.stickyHeader.find('> tr > th');

  this.originalTable.addClass('sticky-table');
  $(window)
    .bind('scroll.drupal-tableheader', $.proxy(this, 'eventhandlerRecalculateStickyHeader'))
    .bind('resize.drupal-tableheader', { calculateWidth: true }, $.proxy(this, 'eventhandlerRecalculateStickyHeader'))
    // Make sure the anchor being scrolled into view is not hidden beneath the
    // sticky table header. Adjust the scrollTop if it does.
    .bind('drupalDisplaceAnchor.drupal-tableheader', function () {
      window.scrollBy(0, -self.stickyTable.outerHeight());
    })
    // Make sure the element being focused is not hidden beneath the sticky
    // table header. Adjust the scrollTop if it does.
    .bind('drupalDisplaceFocus.drupal-tableheader', function (event) {
      if (self.stickyVisible && event.clientY < (self.stickyOffsetTop + self.stickyTable.outerHeight()) && event.$target.closest('sticky-header').length === 0) {
        window.scrollBy(0, -self.stickyTable.outerHeight());
      }
    })
    .triggerHandler('resize.drupal-tableheader');

  // We hid the header to avoid it showing up erroneously on page load;
  // we need to unhide it now so that it will show up when expected.
  this.stickyHeader.show();
};

/**
 * Event handler: recalculates position of the sticky table header.
 *
 * @param event
 *   Event being triggered.
 */
Drupal.tableHeader.prototype.eventhandlerRecalculateStickyHeader = function (event) {
  var self = this;
  var calculateWidth = event.data && event.data.calculateWidth;

  // Reset top position of sticky table headers to the current top offset.
  this.stickyOffsetTop = Drupal.settings.tableHeaderOffset ? eval(Drupal.settings.tableHeaderOffset + '()') : 0;
  this.stickyTable.css('top', this.stickyOffsetTop + 'px');

  // Save positioning data.
  var viewHeight = document.documentElement.scrollHeight || document.body.scrollHeight;
  if (calculateWidth || this.viewHeight !== viewHeight) {
    this.viewHeight = viewHeight;
    this.vPosition = this.originalTable.offset().top - 4 - this.stickyOffsetTop;
    this.hPosition = this.originalTable.offset().left;
    this.vLength = this.originalTable[0].clientHeight - 100;
    calculateWidth = true;
  }

  // Track horizontal positioning relative to the viewport and set visibility.
  var hScroll = document.documentElement.scrollLeft || document.body.scrollLeft;
  var vOffset = (document.documentElement.scrollTop || document.body.scrollTop) - this.vPosition;
  this.stickyVisible = vOffset > 0 && vOffset < this.vLength;
  this.stickyTable.css({ left: (-hScroll + this.hPosition) + 'px', visibility: this.stickyVisible ? 'visible' : 'hidden' });

  // Only perform expensive calculations if the sticky header is actually
  // visible or when forced.
  if (this.stickyVisible && (calculateWidth || !this.widthCalculated)) {
    this.widthCalculated = true;
    var $that = null;
    var $stickyCell = null;
    var display = null;
    var cellWidth = null;
    // Resize header and its cell widths.
    // Only apply width to visible table cells. This prevents the header from
    // displaying incorrectly when the sticky header is no longer visible.
    for (var i = 0, il = this.originalHeaderCells.length; i < il; i += 1) {
      $that = $(this.originalHeaderCells[i]);
      $stickyCell = this.stickyHeaderCells.eq($that.index());
      display = $that.css('display');
      if (display !== 'none') {
        cellWidth = $that.css('width');
        // Exception for IE7.
        if (cellWidth === 'auto') {
          cellWidth = $that[0].clientWidth + 'px';
        }
        $stickyCell.css({'width': cellWidth, 'display': display});
      }
      else {
        $stickyCell.css('display', 'none');
      }
    }
    this.stickyTable.css('width', this.originalTable.outerWidth());
  }
};

})(jQuery);
;
