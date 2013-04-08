(function ($) {

    Drupal.behaviors.viewsTab = {
        attach:function (context, settings) {
            $(".views-tabs").tabs();
        }
    };

}(jQuery));
