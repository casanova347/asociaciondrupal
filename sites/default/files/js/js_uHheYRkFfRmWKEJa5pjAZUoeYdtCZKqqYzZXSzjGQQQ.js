Drupal.locale = { 'pluralFormula': function ($n) { return Number(($n!=1)); }, 'strings': {"":{"An AJAX HTTP error occurred.":"Hubo un error HTTP AJAX.","HTTP Result Code: !status":"C\u00f3digo de Resultado HTTP: !status","An AJAX HTTP request terminated abnormally.":"Una solicitud HTTP de AJAX termin\u00f3 de manera anormal.","Debugging information follows.":"A continuaci\u00f3n se detalla la informaci\u00f3n de depuraci\u00f3n.","Path: !uri":"Ruta: !uri","StatusText: !statusText":"StatusText: !statusText","ResponseText: !responseText":"ResponseText: !responseText","ReadyState: !readyState":"ReadyState: !readyState","Show shortcuts":"Mostrar atajos","Hide shortcuts":"Ocultar atajos","Re-order rows by numerical weight instead of dragging.":"Reordenar las filas por peso num\u00e9rico en lugar de arrastrar.","Show row weights":"Mostrar pesos de la fila","Hide row weights":"Ocultar pesos de la fila","Drag to re-order":"Arrastre para reordenar","Changes made in this table will not be saved until the form is submitted.":"Los cambios realizados en esta tabla no se guardar\u00e1n hasta que se env\u00ede el formulario","Hide":"Ocultar","Show":"Mostrar","(active tab)":"(solapa activa)","Disabled":"Desactivado","Enabled":"Activado","Edit":"Editar","Active":"Activo","From @title":"De @title","Changes to the checkout panes will not be saved until the \u003Cem\u003ESave configuration\u003C\/em\u003E button is clicked.":"Los cambios a los paneles de pedido no ser\u00e1n guardados hasta que el bot\u00f3n de \u003Cem\u003E Guardar Configuraci\u00f3n \u003C\/em\u003E sea presionado.","To @title":"A @title","Created @date":"Creado @date","New order":"Nuevo pedido","Updated @date":"Actualizado @date","Add":"Agregar","Upload":"Subir al servidor","Configure":"Configurar","Done":"Hecho","Select all":"Seleccionar todo","Select all rows in this table":"Seleccionar todas las filas de esta tabla","Deselect all rows in this table":"Quitar la selecci\u00f3n a todas las filas de esta tabla","Not published":"No publicado","Shortcuts":"Atajos","Please wait...":"Espere, por favor...","Only files with the following extensions are allowed: %files-allowed.":"S\u00f3lo se permiten archivos con las siguientes extensiones: %files-allowed.","Remove group":"Eliminar grupo","By @name on @date":"Por @name en @date","By @name":"Por @name","Not in menu":"No est\u00e1 en un men\u00fa","Alias: @alias":"Alias: @alias","No alias":"Sin alias","New revision":"Nueva revisi\u00f3n","The changes to these blocks will not be saved until the \u003Cem\u003ESave blocks\u003C\/em\u003E button is clicked.":"Los cambios sobre estos bloques no se guardar\u00e1n hasta que no pulse el bot\u00f3n \u003Cem\u003EGuardar bloques\u003C\/em\u003E.","This permission is inherited from the authenticated user role.":"Este permiso se hereda del rol de usuario registrado.","No revision":"Sin revisi\u00f3n","@number comments per page":"@number comentarios por p\u00e1gina","Requires a title":"Necesita un t\u00edtulo","Not restricted":"Sin restricci\u00f3n","Not customizable":"No personalizable","Restricted to certain pages":"Restringido a algunas p\u00e1ginas","The block cannot be placed in this region.":"El bloque no se puede colocar en esta regi\u00f3n.","Customize dashboard":"Personalizar panel de control","Hide summary":"Ocultar resumen","Edit summary":"Editar resumen","Don\u0027t display post information":"No mostrar informaci\u00f3n del env\u00edo","The selected file %filename cannot be uploaded. Only files with the following extensions are allowed: %extensions.":"El archivo seleccionado %filename no puede ser subido. Solo se permiten archivos con las siguientes extensiones: %extensions.","Autocomplete popup":"Ventana emergente con autocompletado","Searching for matches...":"Buscando coincidencias","Apply (all displays)":"Aplicar (todas las presentaciones)","Apply (this display)":"Aplicar (esta presentaci\u00f3n)","Revert to default":"Volver a los valores predeterminados","Deselect all":"Deseleccionar todo","Automatic alias":"Alias autom\u00e1tico","Available tokens":"Tokens disponibles","Insert this token into your form":"Inserta este comod\u00edn en su formulario","List additional actions":"Lista adicional de acciones","Show more":"Ver m\u00e1s","Show fewer":"Ver menos","Close":"Cerrar","Select all children":"Seleccionar todos los descendientes","Log messages":"Registrar mensajes","Please select a file.":"Seleccione un documento, por favor.","You are not allowed to operate on more than %num files.":"No tiene permiso para actuar sobre m\u00e1s de %num documentos.","Please specify dimensions within the allowed range that is from 1x1 to @dimensions.":"Especifique unas dimensiones dentro de las permitidas, por favor. Eso va desde 1 \u00d7 1 a @dimensions.","%filename is not an image.":"%filename no es una imagen.","File browsing is disabled in directory %dir.":"La exploraci\u00f3n de documentos est\u00e1 desactivada en el directorio %dir.","Do you want to refresh the current directory?":"\u00bfQuiere actualizar la vista de este directorio?","Delete selected files?":"\u00bfBorrar los documentos seleccionados?","Please select a thumbnail.":"Seleccione una minatura, por favor.","You must select at least %num files.":"Debe seleccionar al menos %num documentos.","You can not perform this operation.":"No puede realizar esta operaci\u00f3n.","Insert file":"Insertar archivo","Change view":"Cambiar vista"}} };;
(function ($) {

/**
 * Attach handlers to evaluate the strength of any password fields and to check
 * that its confirmation is correct.
 */
Drupal.behaviors.password = {
  attach: function (context, settings) {
    var translate = settings.password;
    $('input.password-field', context).once('password', function () {
      var passwordInput = $(this);
      var innerWrapper = $(this).parent();
      var outerWrapper = $(this).parent().parent();

      // Add identifying class to password element parent.
      innerWrapper.addClass('password-parent');

      // Add the password confirmation layer.
      $('input.password-confirm', outerWrapper).parent().prepend('<div class="password-confirm">' + translate['confirmTitle'] + ' <span></span></div>').addClass('confirm-parent');
      var confirmInput = $('input.password-confirm', outerWrapper);
      var confirmResult = $('div.password-confirm', outerWrapper);
      var confirmChild = $('span', confirmResult);

      // Add the description box.
      var passwordMeter = '<div class="password-strength"><div class="password-strength-text" aria-live="assertive"></div><div class="password-strength-title">' + translate['strengthTitle'] + '</div><div class="password-indicator"><div class="indicator"></div></div></div>';
      $(confirmInput).parent().after('<div class="password-suggestions description"></div>');
      $(innerWrapper).prepend(passwordMeter);
      var passwordDescription = $('div.password-suggestions', outerWrapper).hide();

      // Check the password strength.
      var passwordCheck = function () {

        // Evaluate the password strength.
        var result = Drupal.evaluatePasswordStrength(passwordInput.val(), settings.password);

        // Update the suggestions for how to improve the password.
        if (passwordDescription.html() != result.message) {
          passwordDescription.html(result.message);
        }

        // Only show the description box if there is a weakness in the password.
        if (result.strength == 100) {
          passwordDescription.hide();
        }
        else {
          passwordDescription.show();
        }

        // Adjust the length of the strength indicator.
        $(innerWrapper).find('.indicator').css('width', result.strength + '%');

        // Update the strength indication text.
        $(innerWrapper).find('.password-strength-text').html(result.indicatorText);

        passwordCheckMatch();
      };

      // Check that password and confirmation inputs match.
      var passwordCheckMatch = function () {

        if (confirmInput.val()) {
          var success = passwordInput.val() === confirmInput.val();

          // Show the confirm result.
          confirmResult.css({ visibility: 'visible' });

          // Remove the previous styling if any exists.
          if (this.confirmClass) {
            confirmChild.removeClass(this.confirmClass);
          }

          // Fill in the success message and set the class accordingly.
          var confirmClass = success ? 'ok' : 'error';
          confirmChild.html(translate['confirm' + (success ? 'Success' : 'Failure')]).addClass(confirmClass);
          this.confirmClass = confirmClass;
        }
        else {
          confirmResult.css({ visibility: 'hidden' });
        }
      };

      // Monitor keyup and blur events.
      // Blur must be used because a mouse paste does not trigger keyup.
      passwordInput.keyup(passwordCheck).focus(passwordCheck).blur(passwordCheck);
      confirmInput.keyup(passwordCheckMatch).blur(passwordCheckMatch);
    });
  }
};

/**
 * Evaluate the strength of a user's password.
 *
 * Returns the estimated strength and the relevant output message.
 */
Drupal.evaluatePasswordStrength = function (password, translate) {
  var weaknesses = 0, strength = 100, msg = [];

  var hasLowercase = /[a-z]+/.test(password);
  var hasUppercase = /[A-Z]+/.test(password);
  var hasNumbers = /[0-9]+/.test(password);
  var hasPunctuation = /[^a-zA-Z0-9]+/.test(password);

  // If there is a username edit box on the page, compare password to that, otherwise
  // use value from the database.
  var usernameBox = $('input.username');
  var username = (usernameBox.length > 0) ? usernameBox.val() : translate.username;

  // Lose 5 points for every character less than 6, plus a 30 point penalty.
  if (password.length < 6) {
    msg.push(translate.tooShort);
    strength -= ((6 - password.length) * 5) + 30;
  }

  // Count weaknesses.
  if (!hasLowercase) {
    msg.push(translate.addLowerCase);
    weaknesses++;
  }
  if (!hasUppercase) {
    msg.push(translate.addUpperCase);
    weaknesses++;
  }
  if (!hasNumbers) {
    msg.push(translate.addNumbers);
    weaknesses++;
  }
  if (!hasPunctuation) {
    msg.push(translate.addPunctuation);
    weaknesses++;
  }

  // Apply penalty for each weakness (balanced against length penalty).
  switch (weaknesses) {
    case 1:
      strength -= 12.5;
      break;

    case 2:
      strength -= 25;
      break;

    case 3:
      strength -= 40;
      break;

    case 4:
      strength -= 40;
      break;
  }

  // Check if password is the same as the username.
  if (password !== '' && password.toLowerCase() === username.toLowerCase()) {
    msg.push(translate.sameAsUsername);
    // Passwords the same as username are always very weak.
    strength = 5;
  }

  // Based on the strength, work out what text should be shown by the password strength meter.
  if (strength < 60) {
    indicatorText = translate.weak;
  } else if (strength < 70) {
    indicatorText = translate.fair;
  } else if (strength < 80) {
    indicatorText = translate.good;
  } else if (strength <= 100) {
    indicatorText = translate.strong;
  }

  // Assemble the final message.
  msg = translate.hasWeaknesses + '<ul><li>' + msg.join('</li><li>') + '</li></ul>';
  return { strength: strength, message: msg, indicatorText: indicatorText };

};

/**
 * Field instance settings screen: force the 'Display on registration form'
 * checkbox checked whenever 'Required' is checked.
 */
Drupal.behaviors.fieldUserRegistration = {
  attach: function (context, settings) {
    var $checkbox = $('form#field-ui-field-edit-form input#edit-instance-settings-user-register-form');

    if ($checkbox.length) {
      $('input#edit-instance-required', context).once('user-register-form-checkbox', function () {
        $(this).bind('change', function (e) {
          if ($(this).attr('checked')) {
            $checkbox.attr('checked', true);
          }
        });
      });

    }
  }
};

})(jQuery);
;
(function ($) {

/**
 * A progressbar object. Initialized with the given id. Must be inserted into
 * the DOM afterwards through progressBar.element.
 *
 * method is the function which will perform the HTTP request to get the
 * progress bar state. Either "GET" or "POST".
 *
 * e.g. pb = new progressBar('myProgressBar');
 *      some_element.appendChild(pb.element);
 */
Drupal.progressBar = function (id, updateCallback, method, errorCallback) {
  var pb = this;
  this.id = id;
  this.method = method || 'GET';
  this.updateCallback = updateCallback;
  this.errorCallback = errorCallback;

  // The WAI-ARIA setting aria-live="polite" will announce changes after users
  // have completed their current activity and not interrupt the screen reader.
  this.element = $('<div class="progress" aria-live="polite"></div>').attr('id', id);
  this.element.html('<div class="bar"><div class="filled"></div></div>' +
                    '<div class="percentage"></div>' +
                    '<div class="message">&nbsp;</div>');
};

/**
 * Set the percentage and status message for the progressbar.
 */
Drupal.progressBar.prototype.setProgress = function (percentage, message) {
  if (percentage >= 0 && percentage <= 100) {
    $('div.filled', this.element).css('width', percentage + '%');
    $('div.percentage', this.element).html(percentage + '%');
  }
  $('div.message', this.element).html(message);
  if (this.updateCallback) {
    this.updateCallback(percentage, message, this);
  }
};

/**
 * Start monitoring progress via Ajax.
 */
Drupal.progressBar.prototype.startMonitoring = function (uri, delay) {
  this.delay = delay;
  this.uri = uri;
  this.sendPing();
};

/**
 * Stop monitoring progress via Ajax.
 */
Drupal.progressBar.prototype.stopMonitoring = function () {
  clearTimeout(this.timer);
  // This allows monitoring to be stopped from within the callback.
  this.uri = null;
};

/**
 * Request progress data from server.
 */
Drupal.progressBar.prototype.sendPing = function () {
  if (this.timer) {
    clearTimeout(this.timer);
  }
  if (this.uri) {
    var pb = this;
    // When doing a post request, you need non-null data. Otherwise a
    // HTTP 411 or HTTP 406 (with Apache mod_security) error may result.
    $.ajax({
      type: this.method,
      url: this.uri,
      data: '',
      dataType: 'json',
      success: function (progress) {
        // Display errors.
        if (progress.status == 0) {
          pb.displayError(progress.data);
          return;
        }
        // Update display.
        pb.setProgress(progress.percentage, progress.message);
        // Schedule next timer.
        pb.timer = setTimeout(function () { pb.sendPing(); }, pb.delay);
      },
      error: function (xmlhttp) {
        pb.displayError(Drupal.ajaxError(xmlhttp, pb.uri));
      }
    });
  }
};

/**
 * Display errors on the page.
 */
Drupal.progressBar.prototype.displayError = function (string) {
  var error = $('<div class="messages error"></div>').html(string);
  $(this.element).before(error).hide();

  if (this.errorCallback) {
    this.errorCallback(this);
  }
};

})(jQuery);
;
/**
 * @file
 * Provides JavaScript additions to the managed file field type.
 *
 * This file provides progress bar support (if available), popup windows for
 * file previews, and disabling of other file fields during Ajax uploads (which
 * prevents separate file fields from accidentally uploading files).
 */

(function ($) {

/**
 * Attach behaviors to managed file element upload fields.
 */
Drupal.behaviors.fileValidateAutoAttach = {
  attach: function (context, settings) {
    if (settings.file && settings.file.elements) {
      $.each(settings.file.elements, function(selector) {
        var extensions = settings.file.elements[selector];
        $(selector, context).bind('change', {extensions: extensions}, Drupal.file.validateExtension);
      });
    }
  },
  detach: function (context, settings) {
    if (settings.file && settings.file.elements) {
      $.each(settings.file.elements, function(selector) {
        $(selector, context).unbind('change', Drupal.file.validateExtension);
      });
    }
  }
};

/**
 * Attach behaviors to the file upload and remove buttons.
 */
Drupal.behaviors.fileButtons = {
  attach: function (context) {
    $('input.form-submit', context).bind('mousedown', Drupal.file.disableFields);
    $('div.form-managed-file input.form-submit', context).bind('mousedown', Drupal.file.progressBar);
  },
  detach: function (context) {
    $('input.form-submit', context).unbind('mousedown', Drupal.file.disableFields);
    $('div.form-managed-file input.form-submit', context).unbind('mousedown', Drupal.file.progressBar);
  }
};

/**
 * Attach behaviors to links within managed file elements.
 */
Drupal.behaviors.filePreviewLinks = {
  attach: function (context) {
    $('div.form-managed-file .file a, .file-widget .file a', context).bind('click',Drupal.file.openInNewWindow);
  },
  detach: function (context){
    $('div.form-managed-file .file a, .file-widget .file a', context).unbind('click', Drupal.file.openInNewWindow);
  }
};

/**
 * File upload utility functions.
 */
Drupal.file = Drupal.file || {
  /**
   * Client-side file input validation of file extensions.
   */
  validateExtension: function (event) {
    // Remove any previous errors.
    $('.file-upload-js-error').remove();

    // Add client side validation for the input[type=file].
    var extensionPattern = event.data.extensions.replace(/,\s*/g, '|');
    if (extensionPattern.length > 1 && this.value.length > 0) {
      var acceptableMatch = new RegExp('\\.(' + extensionPattern + ')$', 'gi');
      if (!acceptableMatch.test(this.value)) {
        var error = Drupal.t("The selected file %filename cannot be uploaded. Only files with the following extensions are allowed: %extensions.", {
          // According to the specifications of HTML5, a file upload control
          // should not reveal the real local path to the file that a user
          // has selected. Some web browsers implement this restriction by
          // replacing the local path with "C:\fakepath\", which can cause
          // confusion by leaving the user thinking perhaps Drupal could not
          // find the file because it messed up the file path. To avoid this
          // confusion, therefore, we strip out the bogus fakepath string.
          '%filename': this.value.replace('C:\\fakepath\\', ''),
          '%extensions': extensionPattern.replace(/\|/g, ', ')
        });
        $(this).closest('div.form-managed-file').prepend('<div class="messages error file-upload-js-error">' + error + '</div>');
        this.value = '';
        return false;
      }
    }
  },
  /**
   * Prevent file uploads when using buttons not intended to upload.
   */
  disableFields: function (event){
    var clickedButton = this;

    // Only disable upload fields for Ajax buttons.
    if (!$(clickedButton).hasClass('ajax-processed')) {
      return;
    }

    // Check if we're working with an "Upload" button.
    var $enabledFields = [];
    if ($(this).closest('div.form-managed-file').length > 0) {
      $enabledFields = $(this).closest('div.form-managed-file').find('input.form-file');
    }

    // Temporarily disable upload fields other than the one we're currently
    // working with. Filter out fields that are already disabled so that they
    // do not get enabled when we re-enable these fields at the end of behavior
    // processing. Re-enable in a setTimeout set to a relatively short amount
    // of time (1 second). All the other mousedown handlers (like Drupal's Ajax
    // behaviors) are excuted before any timeout functions are called, so we
    // don't have to worry about the fields being re-enabled too soon.
    // @todo If the previous sentence is true, why not set the timeout to 0?
    var $fieldsToTemporarilyDisable = $('div.form-managed-file input.form-file').not($enabledFields).not(':disabled');
    $fieldsToTemporarilyDisable.attr('disabled', 'disabled');
    setTimeout(function (){
      $fieldsToTemporarilyDisable.attr('disabled', false);
    }, 1000);
  },
  /**
   * Add progress bar support if possible.
   */
  progressBar: function (event) {
    var clickedButton = this;
    var $progressId = $(clickedButton).closest('div.form-managed-file').find('input.file-progress');
    if ($progressId.length) {
      var originalName = $progressId.attr('name');

      // Replace the name with the required identifier.
      $progressId.attr('name', originalName.match(/APC_UPLOAD_PROGRESS|UPLOAD_IDENTIFIER/)[0]);

      // Restore the original name after the upload begins.
      setTimeout(function () {
        $progressId.attr('name', originalName);
      }, 1000);
    }
    // Show the progress bar if the upload takes longer than half a second.
    setTimeout(function () {
      $(clickedButton).closest('div.form-managed-file').find('div.ajax-progress-bar').slideDown();
    }, 500);
  },
  /**
   * Open links to files within forms in a new window.
   */
  openInNewWindow: function (event) {
    $(this).attr('target', '_blank');
    window.open(this.href, 'filePreview', 'toolbar=0,scrollbars=1,location=1,statusbar=1,menubar=0,resizable=1,width=500,height=550');
    return false;
  }
};

})(jQuery);
;

(function($) {

/**
 * Drupal FieldGroup object.
 */
Drupal.FieldGroup = Drupal.FieldGroup || {};
Drupal.FieldGroup.Effects = Drupal.FieldGroup.Effects || {};
Drupal.FieldGroup.groupWithfocus = null;

Drupal.FieldGroup.setGroupWithfocus = function(element) {
  element.css({display: 'block'});
  Drupal.FieldGroup.groupWithfocus = element;
}

/**
 * Implements Drupal.FieldGroup.processHook().
 */
Drupal.FieldGroup.Effects.processFieldset = {
  execute: function (context, settings, type) {
    if (type == 'form') {
      // Add required fields mark to any fieldsets containing required fields
      $('fieldset.fieldset', context).once('fieldgroup-effects', function(i) {
        if ($(this).is('.required-fields') && $(this).find('.form-required').length > 0) {
          $('legend span.fieldset-legend', $(this)).eq(0).append(' ').append($('.form-required').eq(0).clone());
        }
        if ($('.error', $(this)).length) {
          $('legend span.fieldset-legend', $(this)).eq(0).addClass('error');
          Drupal.FieldGroup.setGroupWithfocus($(this));
        }
      });
    }
  }
}

/**
 * Implements Drupal.FieldGroup.processHook().
 */
Drupal.FieldGroup.Effects.processAccordion = {
  execute: function (context, settings, type) {
    $('div.field-group-accordion-wrapper', context).once('fieldgroup-effects', function () {
      var wrapper = $(this);

      wrapper.accordion({
        autoHeight: false,
        active: '.field-group-accordion-active',
        collapsible: true,
        changestart: function(event, ui) {
          if ($(this).hasClass('effect-none')) {
            ui.options.animated = false;
          }
          else {
            ui.options.animated = 'slide';
          }
        }
      });

      if (type == 'form') {

        var $firstErrorItem = false;

        // Add required fields mark to any element containing required fields
        wrapper.find('div.field-group-accordion-item').each(function(i) {

          if ($(this).is('.required-fields') && $(this).find('.form-required').length > 0) {
            $('h3.ui-accordion-header a').eq(i).append(' ').append($('.form-required').eq(0).clone());
          }
          if ($('.error', $(this)).length) {
            // Save first error item, for focussing it.
            if (!$firstErrorItem) {
              $firstErrorItem = $(this).parent().accordion("activate" , i);
            }
            $('h3.ui-accordion-header').eq(i).addClass('error');
          }
        });

        // Save first error item, for focussing it.
        if (!$firstErrorItem) {
          $('.ui-accordion-content-active', $firstErrorItem).css({height: 'auto', width: 'auto', display: 'block'});
        }

      }
    });
  }
}

/**
 * Implements Drupal.FieldGroup.processHook().
 */
Drupal.FieldGroup.Effects.processHtabs = {
  execute: function (context, settings, type) {
    if (type == 'form') {
      // Add required fields mark to any element containing required fields
      $('fieldset.horizontal-tabs-pane', context).once('fieldgroup-effects', function(i) {
        if ($(this).is('.required-fields') && $(this).find('.form-required').length > 0) {
          $(this).data('horizontalTab').link.find('strong:first').after($('.form-required').eq(0).clone()).after(' ');
        }
        if ($('.error', $(this)).length) {
          $(this).data('horizontalTab').link.parent().addClass('error');
          Drupal.FieldGroup.setGroupWithfocus($(this));
          $(this).data('horizontalTab').focus();
        }
      });
    }
  }
}

/**
 * Implements Drupal.FieldGroup.processHook().
 */
Drupal.FieldGroup.Effects.processTabs = {
  execute: function (context, settings, type) {
    if (type == 'form') {
      // Add required fields mark to any fieldsets containing required fields
      $('fieldset.vertical-tabs-pane', context).once('fieldgroup-effects', function(i) {
        if ($(this).is('.required-fields') && $(this).find('.form-required').length > 0) {
          $(this).data('verticalTab').link.find('strong:first').after($('.form-required').eq(0).clone()).after(' ');
        }
        if ($('.error', $(this)).length) {
          $(this).data('verticalTab').link.parent().addClass('error');
          Drupal.FieldGroup.setGroupWithfocus($(this));
          $(this).data('verticalTab').focus();
        }
      });
    }
  }
}

/**
 * Implements Drupal.FieldGroup.processHook().
 *
 * TODO clean this up meaning check if this is really
 *      necessary.
 */
Drupal.FieldGroup.Effects.processDiv = {
  execute: function (context, settings, type) {

    $('div.collapsible', context).once('fieldgroup-effects', function() {
      var $wrapper = $(this);

      // Turn the legend into a clickable link, but retain span.field-group-format-toggler
      // for CSS positioning.

      var $toggler = $('span.field-group-format-toggler:first', $wrapper);
      var $link = $('<a class="field-group-format-title" href="#"></a>');
      $link.prepend($toggler.contents());

      // Add required field markers if needed
      if ($(this).is('.required-fields') && $(this).find('.form-required').length > 0) {
        $link.append(' ').append($('.form-required').eq(0).clone());
      }

      $link.appendTo($toggler);

      // .wrapInner() does not retain bound events.
      $link.click(function () {
        var wrapper = $wrapper.get(0);
        // Don't animate multiple times.
        if (!wrapper.animating) {
          wrapper.animating = true;
          var speed = $wrapper.hasClass('speed-fast') ? 300 : 1000;
          if ($wrapper.hasClass('effect-none') && $wrapper.hasClass('speed-none')) {
            $('> .field-group-format-wrapper', wrapper).toggle();
          }
          else if ($wrapper.hasClass('effect-blind')) {
            $('> .field-group-format-wrapper', wrapper).toggle('blind', {}, speed);
          }
          else {
            $('> .field-group-format-wrapper', wrapper).toggle(speed);
          }
          wrapper.animating = false;
        }
        $wrapper.toggleClass('collapsed');
        return false;
      });

    });
  }
};

/**
 * Behaviors.
 */
Drupal.behaviors.fieldGroup = {
  attach: function (context, settings) {
    settings.field_group = settings.field_group || Drupal.settings.field_group;
    if (settings.field_group == undefined) {
      return;
    }

    // Execute all of them.
    $.each(Drupal.FieldGroup.Effects, function (func) {
      // We check for a wrapper function in Drupal.field_group as
      // alternative for dynamic string function calls.
      var type = func.toLowerCase().replace("process", "");
      if (settings.field_group[type] != undefined && $.isFunction(this.execute)) {
        this.execute(context, settings, settings.field_group[type]);
      }
    });

    // Fixes css for fieldgroups under vertical tabs.
    $('.fieldset-wrapper .fieldset > legend').css({display: 'block'});
    $('.vertical-tabs fieldset.fieldset').addClass('default-fallback');


    // Add a new ID to each fieldset.
    $('.group-wrapper fieldset').each(function() {
      // Tats bad, but we have to keep the actual id to prevent layouts to break.
      var fieldgorupID = 'field_group-' + $(this).attr('id') + ' ' + $(this).attr('id');
      $(this).attr('id', fieldgorupID);
    })
    // Set the hash in url to remember last userselection.
    $('.group-wrapper ul li').each(function() {
      var fieldGroupNavigationListIndex = $(this).index();
      $(this).children('a').click(function() {
        var fieldset = $('.group-wrapper fieldset').get(fieldGroupNavigationListIndex);
        // Grab the first id, holding the wanted hashurl.
        var hashUrl = $(fieldset).attr('id').replace(/^field_group-/, '').split(' ')[0];
        window.location.hash = hashUrl;
      });
    });
  }
};

})(jQuery);;
