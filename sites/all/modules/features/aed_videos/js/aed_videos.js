(function($) {

  /**
   * Live preview of Administration menu components.
   */
  Drupal.behaviors.aedVideosFlag = {
    attach: function (context, settings) {
      $('input[name=filter_flag]').click(function() {
        window.location.replace(settings.aed_videos_filter[$(this).val()]);
      });
    }
  };

})(jQuery);