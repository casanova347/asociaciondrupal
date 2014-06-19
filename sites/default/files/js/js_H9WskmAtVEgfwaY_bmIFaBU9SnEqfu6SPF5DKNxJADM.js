Drupal.locale = { 'pluralFormula': function ($n) { return Number(($n!=1)); }, 'strings': {"":{"An AJAX HTTP error occurred.":"Hubo un error HTTP AJAX.","HTTP Result Code: !status":"C\u00f3digo de Resultado HTTP: !status","An AJAX HTTP request terminated abnormally.":"Una solicitud HTTP de AJAX termin\u00f3 de manera anormal.","Debugging information follows.":"A continuaci\u00f3n se detalla la informaci\u00f3n de depuraci\u00f3n.","Path: !uri":"Ruta: !uri","StatusText: !statusText":"StatusText: !statusText","ResponseText: !responseText":"ResponseText: !responseText","ReadyState: !readyState":"ReadyState: !readyState","Show shortcuts":"Mostrar atajos","Hide shortcuts":"Ocultar atajos","Re-order rows by numerical weight instead of dragging.":"Reordenar las filas por peso num\u00e9rico en lugar de arrastrar.","Show row weights":"Mostrar pesos de la fila","Hide row weights":"Ocultar pesos de la fila","Drag to re-order":"Arrastre para reordenar","Changes made in this table will not be saved until the form is submitted.":"Los cambios realizados en esta tabla no se guardar\u00e1n hasta que se env\u00ede el formulario","Hide":"Ocultar","Show":"Mostrar","(active tab)":"(solapa activa)","Disabled":"Desactivado","Enabled":"Activado","Edit":"Editar","From @title":"De @title","Changes to the checkout panes will not be saved until the \u003Cem\u003ESave configuration\u003C\/em\u003E button is clicked.":"Los cambios a los paneles de pedido no ser\u00e1n guardados hasta que el bot\u00f3n de \u003Cem\u003E Guardar Configuraci\u00f3n \u003C\/em\u003E sea presionado.","To @title":"A @title","Created @date":"Creado @date","New order":"Nuevo pedido","Updated @date":"Actualizado @date","Add":"Agregar","Configure":"Configurar","Select all rows in this table":"Seleccionar todas las filas de esta tabla","Deselect all rows in this table":"Quitar la selecci\u00f3n a todas las filas de esta tabla","Not published":"No publicado","Shortcuts":"Atajos","Please wait...":"Espere, por favor...","Remove group":"Eliminar grupo","By @name on @date":"Por @name en @date","By @name":"Por @name","Not in menu":"No est\u00e1 en un men\u00fa","Alias: @alias":"Alias: @alias","No alias":"Sin alias","New revision":"Nueva revisi\u00f3n","The changes to these blocks will not be saved until the \u003Cem\u003ESave blocks\u003C\/em\u003E button is clicked.":"Los cambios sobre estos bloques no se guardar\u00e1n hasta que no pulse el bot\u00f3n \u003Cem\u003EGuardar bloques\u003C\/em\u003E.","This permission is inherited from the authenticated user role.":"Este permiso se hereda del rol de usuario registrado.","No revision":"Sin revisi\u00f3n","@number comments per page":"@number comentarios por p\u00e1gina","Requires a title":"Necesita un t\u00edtulo","Not restricted":"Sin restricci\u00f3n","Not customizable":"No personalizable","Restricted to certain pages":"Restringido a algunas p\u00e1ginas","The block cannot be placed in this region.":"El bloque no se puede colocar en esta regi\u00f3n.","Hide summary":"Ocultar resumen","Edit summary":"Editar resumen","Don\u0027t display post information":"No mostrar informaci\u00f3n del env\u00edo","The selected file %filename cannot be uploaded. Only files with the following extensions are allowed: %extensions.":"El archivo seleccionado %filename no puede ser subido. Solo se permiten archivos con las siguientes extensiones: %extensions.","Autocomplete popup":"Ventana emergente con autocompletado","Searching for matches...":"Buscando coincidencias","Apply (all displays)":"Aplicar (todas las presentaciones)","Apply (this display)":"Aplicar (esta presentaci\u00f3n)","Revert to default":"Volver a los valores predeterminados","Deselect all":"Deseleccionar todo","Automatic alias":"Alias autom\u00e1tico","Available tokens":"Tokens disponibles","Insert this token into your form":"Inserta este comod\u00edn en su formulario","List additional actions":"Lista adicional de acciones","Show more":"Ver m\u00e1s","Show fewer":"Ver menos","Close":"Cerrar","Select all children":"Seleccionar todos los descendientes"}} };;
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
(function($) {

/**
 * Attaches the tree behavior to the term widget form.
 */
Drupal.behaviors.termReferenceTree = {
  attach: function(context, settings) {
    // Bind the term expand/contract button to slide toggle the list underneath.
    $('.term-reference-tree-button', context).once('term-reference-tree-button').click(function() {
      $(this).toggleClass('term-reference-tree-collapsed');
      $(this).siblings('ul').slideToggle('fast');
    });

    // An expand all button (unimplemented)
    /*
    $('.expandbutton').click(function() {
      $(this).siblings('.term-reference-tree-button').trigger('click');
    });
    */


    $('.term-reference-tree', context).once('term-reference-tree', function() {
      // On page load, check whether the maximum number of choices is already selected.
      // If so, disable the other options.
      var tree = $(this);
      checkMaxChoices(tree, false);
      $(this).find('input[type=checkbox]').change(function() {
        checkMaxChoices(tree, $(this));
      });

      //On page load, check if the user wants a track list. If so, add the
      //currently selected items to it.
      if($(this).hasClass('term-reference-tree-track-list-shown')) {
        var track_list_container = $(this).find('.term-reference-tree-track-list');

        //Var to track whether using checkboxes or radio buttons.
        var input_type =
          ( $(this).has('input[type=checkbox]').size() > 0 ) ? 'checkbox' : 'radio';

        //Find all the checked controls.
        var checked_controls = $(this).find('input[type=' + input_type + ']:checked');

        //Get their labels.
        var labels = checked_controls.next();
        var label_element;

        //For each label of the checked boxes, add item to the track list.
        labels.each(function(index) {
          label_element = $(labels[index]);
          addItemToTrackList(
            track_list_container,         //Where to add new item.
            label_element.html(),         //Text of new item.
            $(label_element).attr('for'), //Id of control new item is for.
            input_type                    //checkbox or radio
          );
        }); //End labels.each

        //Show "nothing selected" message, if needed.
        showNothingSelectedMessage(track_list_container);

        //Event - when an element on the track list is clicked on:
        //  1. Delete it.
        //  2. Uncheck the associated checkbox.
        //The event is bound to the track list container, not each element.
        $(track_list_container).click(function(event){
          //Remove the "nothing selected" message if showing - add it later if needed.
          //removeNothingSelectedMessage(track_list_container);
          var event_target = $(event.target);
          var control_id = event_target.data('control_id');

          if(control_id) {
            event_target.remove();

            var checkbox = $('#' + control_id);
            checkbox.removeAttr('checked');
            checkMaxChoices(tree, checkbox);

            //Show "nothing selected" message, if needed.
            showNothingSelectedMessage(track_list_container);
          }
        });

        //Change track list when controls are clicked.
        $(this).find('.form-' + input_type).change(function(event){
          //Remove the "nothing selected" message if showing - add it later if needed.
          removeNothingSelectedMessage(track_list_container);
          var event_target = $(event.target);
          var control_id = event_target.attr('id');
          if ( event_target.attr('checked') ) {
            //Control checked - add item to the track list.
            label_element = event_target.next();
            addItemToTrackList(
              track_list_container,         //Where to add new item.
              label_element.html(),         //Text of new item.
              $(label_element).attr('for'), //Id of control new item is for.
              input_type                    //checkbox or radio
            );
          }
          else {
            //Checkbox unchecked. Remove from the track list.
            $('#' + control_id + '_list').remove();
          }

          //Show "nothing selected" message, if needed.
          showNothingSelectedMessage(track_list_container);
        }); //End process checkbox changes.
      } //End Want a track list.

      //On page load, check if the user wants a cascading selection.
      if($(this).hasClass('term-reference-tree-cascading-selection')) {

        //Check children when checkboxes are clicked.
        $(this).find('.form-checkbox').change(function(event) {
          var event_target = $(event.target);
          var control_id = event_target.attr('id');
          var children = event_target.parent().next().children().children('div.form-type-checkbox').children('input[id^="' + control_id + '-children"]');
          if(event_target.attr('checked')) {
            //Checkbox checked - check children if none were checked.
            if(!$(children).filter(':checked').length) {
              $(children).click().trigger('change');
            }
          }
          else {
            //Checkbox unchecked. Uncheck children if all were checked.
            if(!$(children).not(':checked').length) {
              $(children).click().trigger('change');
            }
          }

        });
        //End process checkbox changes.
      } //End Want a cascading checking.

    });
  }
};

/**
 * Add a new item to the track list.
 * If more than one item can be selected, the new item is positioned to
 * match the order of the terms in the checkbox tree.
 *
 * @param track_list_container Container where the new item will be added.
 *
 * @param item_text Text of the item to add.
 *
 * @param control_id Id of the checkbox/radio control the item matches.
 *
 * @param control_type Control type - 'checkbox' or 'radio'.
 */
function addItemToTrackList(track_list_container, item_text, control_id, control_type) {
  var new_item = $('<li class="track-item">' + item_text + '</li>');
  new_item.data('control_id', control_id);

  //Add an id for easy finding of the item.
  new_item.attr('id', control_id + '_list');

  //Process radio controls - only one item can be selected.
  if ( control_type == 'radio') {
    //Find the existing element on the track list, if there is one.
    var current_items = track_list_container.find('li');

    //If there are no items on the track list, add the new item.
    if ( current_items.size() == 0 ) {
      track_list_container.append(new_item);
    }
    else {
      //There is an item on the list.
      var current_item = $(current_items.get(0));

      //Is the item we want to add different from what is there?
      if ( current_item.data('control_id') != control_id ) {
        //Remove exiting element from track list, and add the new one.
        current_item.remove();
        track_list_container.append(new_item);
      }
    }
    return;
  }

  //Using checkboxes, so there can be more than one selected item.
  //Find the right place to put the new item, to match the order of the
  //checkboxes.
  var list_items = track_list_container.find('li');
  var item_comparing_to;

  //Flag to tell whether the item was inserted.
  var inserted_flag = false;
  list_items.each(function(index){
    item_comparing_to = $(list_items[index]);

    //If item is already on the track list, do nothing.
    if ( control_id == item_comparing_to.data('control_id') ) {
      inserted_flag = true;
      return false; //Returning false stops the loop.
    }
    else if ( control_id < item_comparing_to.data('control_id') ) {
      //Add it here.
      item_comparing_to.before(new_item);
      inserted_flag = true;
      return false; //Returning false stops the loop.
    }
  });

  //If not inserted yet, add new item at the end of the track list.
  if ( ! inserted_flag ) {
    track_list_container.append(new_item);
  }
}

/**
 * Show the 'nothing selected' message if it applies.
 *
 * @param track_list_container Where the message is to be shown.
 */
function showNothingSelectedMessage(track_list_container) {
  //Is the message there already?
  var message_showing =
      (track_list_container.find('.term_ref_tree_nothing_message').size() != 0);

  //Number of real items showing.
  var num_real_items_showing =
      message_showing
      ? track_list_container.find('li').size() - 1
      : track_list_container.find('li').size();
  if ( num_real_items_showing == 0 ) {
    //No items showing, so show the message.
    if ( ! message_showing ) {
      track_list_container.append(
          '<li class="term_ref_tree_nothing_message">' + termReferenceTreeNothingSelectedText + '</li>'
      );
    }
  }
  else { // !(num_real_items_showing == 0)
    //There are real items.
    if ( message_showing ) {
      track_list_container.find('.term_ref_tree_nothing_message').remove();
    }
  }
}

/**
 * Remove the 'nothing selected' message. Makes processing easier.
 *
 * @param track_list_container Where the message is shown.
 */
function removeNothingSelectedMessage(track_list_container) {
  track_list_container.find('.term_ref_tree_nothing_message').remove();
}

// This helper function checks if the maximum number of choices is already selected.
// If so, it disables all the other options.  If not, it enables them.
function checkMaxChoices(item, checkbox) {
  var maxChoices = -1;
  try {
    maxChoices = parseInt(Drupal.settings.term_reference_tree.trees[item.attr('id')]['max_choices']);
  }
  catch (e){}
  var count = item.find(':checked').length;

  if(maxChoices > 0 && count >= maxChoices) {
    item.find('input[type=checkbox]:not(:checked)').attr('disabled', 'disabled').parent().addClass('disabled');
  } else {
    item.find('input[type=checkbox]').removeAttr('disabled').parent().removeClass('disabled');
  }

  if(checkbox) {
    if(item.hasClass('select-parents')) {
      var track_list_container = item.find('.term-reference-tree-track-list');
      var input_type =
          ( item.has('input[type=checkbox]').size() > 0 ) ? 'checkbox' : 'radio';

      if(checkbox.attr('checked')) {
        checkbox.parents('ul.term-reference-tree-level li').children('div.form-item').children('input[type=checkbox]').each(function() {
          $(this).attr('checked', checkbox.attr('checked'));

          if(track_list_container) {
            label_element = $(this).next();
            addItemToTrackList(
              track_list_container,         //Where to add new item.
              label_element.html(),         //Text of new item.
              $(label_element).attr('for'), //Id of control new item is for.
              input_type                    //checkbox or radio
            );
          }
        });
      }
    }
  }
}

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
