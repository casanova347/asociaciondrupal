(function ($) {

    Drupal.behaviors.aedTheme = {
        attach:function (context, settings) {

            $('#mini-menu-toggle-wrapper a', context).once('mini-menu-toggler', function () {

                var $menu = $("#menu-bar");

                $(this).each(function () {

                    var $self = $(this);

                    $self.click(function () {
                        $menu.toggle();
                        $self.toggleClass("active");
                    });
                });

            });

        }
    };

}(jQuery));

window.addEventListener('load', function () {
    new FastClick(document.body);
}, false);