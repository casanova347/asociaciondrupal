(function ($) {
  $(document).ready(function () {
    ///////////////////

    var $mobileMenu = $(".mobile-menu");
    var $menuFixed = $(".menu-fixed");
    var $closeBtn = $mobileMenu.find('.close');

    // Items que vamos a meter en el menu mobile.
    // Estan ordenados por el orden en el que van a aparecer en el menu mobile.
    var itemsToMobile = [
        $('#block-system-main-menu')
        //, $('#otro-bloque')
    ];

    $.each(itemsToMobile, function (i, v) {
      // Los clonamos porque no queremos quitar los que hay en desktop.
      var $el = $(this).addClass('js-mobile-cloned').clone(true);
      $el.appendTo($mobileMenu);
    });

    // Eventos.
    // --------------------------------------------------
    $('.menu-toggle').click(function (e) {
      e.preventDefault();
      $mobileMenu.toggleClass('open');
      $menuFixed.toggleClass('open');
    });

    $closeBtn.click(function (e) {
      $mobileMenu.toggleClass('open');
      $menuFixed.toggleClass('open');
    });

    ///////////////////
  });
})(jQuery);
