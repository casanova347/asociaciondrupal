<?php
/**
 * @file
 * aed_company.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function aed_company_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'empresas_colaboradoras';
  $page->task = 'page';
  $page->admin_title = 'Empresas colaboradoras';
  $page->admin_description = '';
  $page->path = 'empresas-colaboradoras';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Empresas colaboradoras',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_empresas_colaboradoras_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'empresas_colaboradoras';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'empresas-colaboradoras',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c63bdfd9-5080-40cc-9ab0-7aadb9d5a521';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-25f30ca4-cdcd-4445-90d3-416b23f042c9';
  $pane->panel = 'one_main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Heading text',
    'title' => '',
    'body' => 'La Asociación Española de Drupal y las empresas colaboradoras participan juntas en la expansión de Drupal en la comunidad de habla hispana y principalmente de España promoviendo su uso, organizando eventos y sprints. Convirtiéndote en una empresa colaboradora, ayudas a la Asociación a que podamos seguir organizando la Drupal Camp y el Drupal Day entre otros eventos un año más. Contacta con nosotros para más detalles de qué incluye el paquete de colaboración.',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '25f30ca4-cdcd-4445-90d3-416b23f042c9';
  $display->content['new-25f30ca4-cdcd-4445-90d3-416b23f042c9'] = $pane;
  $display->panels['one_main'][0] = 'new-25f30ca4-cdcd-4445-90d3-416b23f042c9';
  $pane = new stdClass();
  $pane->pid = 'new-d41edbd1-794f-49ec-b897-e5ed029113b2';
  $pane->panel = 'one_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'partners_by_year-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'd41edbd1-794f-49ec-b897-e5ed029113b2';
  $display->content['new-d41edbd1-794f-49ec-b897-e5ed029113b2'] = $pane;
  $display->panels['one_main'][1] = 'new-d41edbd1-794f-49ec-b897-e5ed029113b2';
  $pane = new stdClass();
  $pane->pid = 'new-ef42e5bc-f906-446f-8758-f5f1a40538be';
  $pane->panel = 'one_main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Footer',
    'title' => '',
    'body' => '    <p>Ya es posible iniciar una suscripción como empresa colaboradora de la Asociación o renovar su
        suscripción actual. El ser empresa colaboradora ayudará al desarrollo de la comunidad e implica
        interesantes ventajas:</p>

    <ul>
        <li>Presencia del logo en la web corporativa de la AED</li>
        <li>Posibilidad de colocar badges como empresa colaboradora en su web corporativa, información
institucional, redes sociales, ofertas y cualquier otro medio de comunicación en que sea beneficiosa
la publicación de la colaboración.
        </li>
        <li>Patrocinio Bronce en la <a href="http://2014.drupalcamp.es/">Drupalcamp Spain 2014</a> en Valencia y
            acceso preferente al modo Plata u Oro en caso de desearlo.
        </li>
        <li>Patrocinio <a href="http://drupalday.es/">Drupal Day 2014</a> Lugar aún por decidir.</li>
        <li>Patrocinio y presencia en todas las actividades promovidas por la AED durante 2014. Por ejemplo, sprints de código o colaboraciones de la AED en otros eventos.
        </li>
        <li>Posibilidad de descuento en el patrocinio de aquellos eventos internacionales en cuya organización colabore la asociación (dependerá del acuerdo al que se llegue con la organización en cada caso).
        </li>
    </ul>

    <p><strong>Para solicitar más información</strong>, no dudéis en utilizar el <a href="/contact">formulario
        de contacto</a>.</p>',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'ef42e5bc-f906-446f-8758-f5f1a40538be';
  $display->content['new-ef42e5bc-f906-446f-8758-f5f1a40538be'] = $pane;
  $display->panels['one_main'][2] = 'new-ef42e5bc-f906-446f-8758-f5f1a40538be';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-25f30ca4-cdcd-4445-90d3-416b23f042c9';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['empresas_colaboradoras'] = $page;

  return $pages;

}
