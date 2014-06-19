(function ($) {
  $.fn.tableCellEqualHeights = function () {

    /**
     * Cuando un view tenga el class ".cell-full-height", este script se
     * encarga de encontrar el TD mas alto y le aplica tu tamaño al resto de TD.
     */
    var $cellFullHeightTDs = $(this).find('.view-content > table > tbody > tr > td');

    $cellFullHeightTDs.find('> * ').height(Math.max.apply(null, $cellFullHeightTDs.map(function () {
      return $(this).height();
    }).get()));

  };
})(jQuery);
