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

  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();

    //Defaults del plugin
    $options['style_plugin'] = array('default' => 'list');

    //Defaults del renderizado HTML list
    $options["list"] = array(
      'default' => array(
        'type' => 'ul',
        'class' => '',
        'wrapper_class' => 'item-list',
        'theme' => 'views_view_list'
      )
    );

    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    //list available render styles
    $styles = views_fetch_plugin_names('style', "normal");
    unset($styles["tabs"]);

    $form['style_plugin'] = array(
      '#title' => 'Output format for contents',
      '#type' => 'radios',
      '#options' => $styles,
      '#default_value' => $this->options['style_plugin'],
    );

    //Attach selected style's form

    $form['html-list-config'] = array(
      '#type' => 'fieldset',
      '#title' => t('List settings'),
      '#dependency' => array('radio:style_options[style_plugin]' => array('list')),
    );

    $list = new views_plugin_style_list();
    $list_form = array();
    $list->options_form($list_form, $form_state);

    $list_form["type"]['#default_value'] = $this->options['list']['type'];
    $list_form["wrapper_class"]['#default_value'] = $this->options['list']['wrapper_class'];
    $list_form["class"]['#default_value'] = $this->options['list']['class'];
    $form['html-list-config'][] = $list_form;
  }

  /**
   * Handle any special handling on the validate form.
   */
  function options_submit(&$form, &$form_state) {

    //Metemos las preferencias que el usuario ha configurado en su lugar
    $form_state['values']['style_options']['list'] = $form_state['values']['style_options']['html-list-config'][0];
    unset($form_state['values']['style_options']['html-list-config']);
  }

  function render_grouping_sets($sets, $level = 0) {

    $tabs = array();
    $content_tabs = array();

    foreach ($sets as $set) {

      //renderizamos los fields
      if ($this->uses_row_plugin()) {
        foreach ($set['rows'] as $index => $row) {
          $this->view->row_index = $index;
          $set['rows'][$index] = $this->row_plugin->render($row);
        }
      }

      $tabs[] = $set["group"];

      //El format que hemos seleccionado para renderizar el contenido de cada tab
      $format = $this->options["style_plugin"];

      //Temporalmente modificamos $this->options para poder
      //emular las opciones que espera el theme del format que vayamos a usar.
      $original_options = $this->options;
      $this->options = array_merge($this->options, $this->options[$format]);

      //Nosotros nos encargamos de estructurar los tabs,
      //pero el contenido sigue siendo resposnabilidad de los formats.
      $content_tabs[] = theme($original_options[$format]["theme"],
        array(
          'view' => $this->view,
          'options' => $this->options,
          'rows' => $set['rows'],
        )
      );

      //Recuperamos nuestras opts
      $this->options = $original_options;

      $tabs_index[] = $this->view->row_index;
    }

    //ya podemos enderizar los tabs
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
    drupal_add_js(drupal_get_path('module', 'aed_mod') . "/js/views-tab.js");

    return $output;
  }

}
