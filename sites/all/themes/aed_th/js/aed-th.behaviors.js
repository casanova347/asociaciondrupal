(function ($) {
  Drupal.behaviors.frontidThExampleBehavior = {
    attach: function (context, settings) {
      /////////////////
      $('.parallax-wrapper').parallax({
        holderClass: 'parallax-wrapper content-absolute-centered'
      });

      ////////////////
      // ---------------------
      // @todo mover a un js independiente
      /**
       * Mueve el scroll animadamente ;) hasta una zona de la pagina.
       *
       * @param {String} dest ancla de destino. ej: "#foo"
       * @param center {Boolean} Indica si se quiere que el contenido quede
       *        centrado verticalmente.
       * @return {Boolean} indicando si el link era de tipo hash
       *         y lo hemos intervenido o link normal y no lo hemos tocado.
       */
      var goTo = function (dest, extraOffset) {
        // Le sumamos un px mas por compatibilidad con browsers.
        extraOffset || (extraOffset = 1);

        // Si no es un hash, lo dejamos continuar.
        if (dest.substr(0, 1) !== "#") {
          window.location.href = dest;
          return false;
        }

        //History.pushState(null, null, dest);
        var offset = $(dest).offset().top + extraOffset;

        window.animatingScroll = true;

        // Al usar un doble selector ($("html, body")) el callback se
        // lanza dos veces. controlamos esa situacion con este flag.
        var justOneTriggerPlease = 0;

        $("html, body").animate({scrollTop: offset}, 1200, function () {
          if (justOneTriggerPlease == 1) {
            window.animatingScroll = false;
            justOneTriggerPlease = 0;
          } else {
            justOneTriggerPlease++;
          }
        });
        return true;
      };


      $('#block-system-main-menu a').on('click', function (e) {
        e.preventDefault();
        var $this = $(this);

        if ($this.hasClass('team')) {
          goTo('#block-views-our-team-block-the-team', -40)
        }

        if ($this.hasClass('portfolio')) {
          goTo('#block-views-portfolio-portfolio-block', -40)
        }

        if ($this.hasClass('clients')) {
          goTo('#block-views-clients-block-clients', -40)
        }

        if ($this.hasClass('contact')) {
          goTo('#block-contact-form-blocks-0', -40)
        }


      });
      ////////////////
    }
  };

})(jQuery);
