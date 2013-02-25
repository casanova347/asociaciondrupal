<?php
function aed_mod_views_plugins() {
  return array(
    'style' => array(
      'tabs' => array(
        'title' => t('Tabs'),
        'help' => t('Displays rows tabs.'),
        'handler' => 'views_plugin_style_tabs',
        'theme' => 'views_view_tabs',
        'uses fields' => FALSE,
        'uses row plugin' => TRUE,
        'uses row class' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}

/**
 * Style plugin to render each item in a grid cell.
 *
 * @ingroup views_style_plugins
 */
class views_plugin_style_tabs extends views_plugin_style {



  function render_grouping_sets($sets, $level = 0) {

    $tabs = array();
    $content_tabs = array();
    $tabs_references = array();


    foreach ($sets as $set) {

      //renderizamos los fields
      if ($this->uses_row_plugin()) {
        foreach ($set['rows'] as $index => $row) {
          $this->view->row_index = $index;
          $set['rows'][$index] = $this->row_plugin->render($row);
        }
      }

      $tabs[] = $set["group"];
      $content_tabs[] = $set["rows"];
      $tabs_index[] = $this->view->row_index;
    }

    $output = theme($this->theme_functions(),
      array(
        'view' => $this->view,
        'options' => $this->options,
        'tabs' => $tabs,
        'content_tabs' => $content_tabs,
      )

    );

    //add needed resources
    drupal_add_library('system', 'ui.tabs');
    drupal_add_js(drupal_get_path('module', 'aed_mod')  . "/js/views-tab.js");

    return $output;
  }

}
