(function ($) {
///////////////////
  var $document = $(document);
  var $offCanvas = false;

  $(document).ready(function () {
    var $mobileMenu = $('#off-canvas');

    // Items que vamos a meter en el menu mobile.
    // Estan ordenados por el orden en el que van a aparecer en el menu mobile.
    var itemsToMobile = [
      $('#block-search-form'),
      $('#block-gestalt-gestalt-header-tel-block')
    ];

    $.each(itemsToMobile, function (i, v) {
      // Los clonamos porque no queremos quitar los que hay en desktop.
      var $el = $(this).clone(true);
      $el.appendTo($mobileMenu);
    });

  });

  // No queremos tener que esperar al elemento (evitamos el bloqueo)
  // asi que escuchamos al documento en lugar de al elemento en si.
  $document.click(function (e) {
    var $el = $(e.target);

    $offCanvas || ($offCanvas = $('#off-canvas'));
    if ($el.parent().hasClass('off-canvas-toggler')) {
      $offCanvas.toggleClass('open');
    } else {
      //if ($offCanvas.hasClass('open') && !$el.attr('href')) {
      //  e.preventDefault();
      //  $offCanvas.toggleClass('open');
      //}

    }

  });
///////////////////
})(jQuery);



