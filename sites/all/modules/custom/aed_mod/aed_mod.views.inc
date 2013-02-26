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

  /**@var $table_plugin views_plugin_style_table */
  var $table_plugin = NULL;

  /**@var $grid_plugin views_plugin_style_grid */
  var $grid_plugin = NULL;

  function init(&$view, &$display, $options = NULL) {
    parent::init($view, $display, $options);

    $this->table_plugin = new views_plugin_style_table();
    $this->table_plugin->definition = array();
    $this->table_plugin->init($this->view, $this->display, $this->options["table"]);


    $this->grid_plugin = new views_plugin_style_grid();
    $this->grid_plugin->definition = array();
    $this->grid_plugin->init($this->view, $this->display, $this->options["grid"]);

  }

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

    $options["table"] = array(
      'default' => array(
        'columns' => array(),
        'default' => '',
        'info' => array(),
        'override' => TRUE,
        'sticky' => FALSE,
        'order' => 'asc',
        'summary' => '',
        'empty_table' => FALSE,
        'theme' => 'views_view_table',
      )
    );

    $options["grid"] = array(
      'default' => array(
        'columns' => '4',
        'alignment' => 'horizontal',
        'fill_single_line' => TRUE,
        'summary' => '',
        'theme' => 'views_view_grid'
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
    ///////////////
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

    ///////////////

    $form['html-table-config'] = array(
      '#type' => 'fieldset',
      '#title' => t('Table settings'),
      '#dependency' => array('radio:style_options[style_plugin]' => array('table')),
    );

    $table_form = array();
    $this->table_plugin->options_form($table_form, $form_state);

    $table_form["columns"]['#default_value'] = $this->options['table']['columns'];
    $table_form["default"]['#default_value'] = $this->options['table']['default'];
    $table_form["info"]['#default_value'] = $this->options['table']['info'];
    $table_form["override"]['#default_value'] = $this->options['table']['override'];
    $table_form["sticky"]['#default_value'] = $this->options['table']['sticky'];
    $table_form["order"]['#default_value'] = $this->options['table']['order'];
    $table_form["summary"]['#default_value'] = $this->options['table']['summary'];
    $table_form["empty_table"]['#default_value'] = $this->options['table']['empty_table'];
    $form['html-table-config'][] = $table_form;

    ///////////////

    $form['html-grid-config'] = array(
      '#type' => 'fieldset',
      '#title' => t('Grid settings'),
      '#dependency' => array('radio:style_options[style_plugin]' => array('grid')),
    );

    $grid_form = array();
    $this->grid_plugin->options_form($grid_form, $form_state);

    $grid_form["columns"]['#default_value'] = $this->options['grid']['columns'];
    $grid_form["alignment"]['#default_value'] = $this->options['grid']['alignment'];
    $grid_form["fill_single_line"]['#default_value'] = $this->options['grid']['fill_single_line'];
    $grid_form["summary"]['#default_value'] = $this->options['grid']['summary'];
    $form['html-grid-config'][] = $grid_form;

  }

  /**
   * Handle any special handling on the validate form.
   */
  function options_submit(&$form, &$form_state) {

    //Metemos las preferencias que el usuario ha configurado en su lugar
    $form_state['values']['style_options']['list'] = $form_state['values']['style_options']['html-list-config'][0];
    $form_state['values']['style_options']['table'] = $form_state['values']['style_options']['html-table-config'][0];
    $form_state['values']['style_options']['grid'] = $form_state['values']['style_options']['html-grid-config'][0];

    unset(
    $form_state['values']['style_options']['html-list-config'],
    $form_state['values']['style_options']['html-table-config'],
    $form_state['values']['style_options']['html-grid-config']
    );
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

  function sanitize_columns($columns, $fields = NULL) {
    return $this->table_plugin->sanitize_columns($columns, $fields);
  }

}
