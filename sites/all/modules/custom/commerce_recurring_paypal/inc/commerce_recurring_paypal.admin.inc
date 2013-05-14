<?php

/**
 * @file
 * Provides admin forms and settings.
 */

/**
 * Class CommerceRecurringPaypalAdmin
 */
class CommerceRecurringPaypalAdmin {

  /**
   * Payment gateway settings.
   *
   * @param array $settings
   *   stored settings
   *
   * @return array
   *   FAPI
   */
  static public function getSettingsForm($settings) {
    $form = array();
    $settings = (array) $settings + array(
      'language' => 'US',
      'cart_items_list' => 0,
      'server' => 'sandbox',
      'api_username' => '',
      'api_password' => '',
      'api_signature' => '',
    );

    $form['language'] = array(
      '#type' => 'select',
      '#title' => t('PayPal login page language / locale'),
      '#options' => array(
        t('By country') => array(
          'AU' => t('Australia'),
          'AT' => t('Austria'),
          'BE' => t('Belgium'),
          'BR' => t('Brazil'),
          'CA' => t('Canada'),
          'CN' => t('China'),
          'FR' => t('France'),
          'DE' => t('Germany'),
          'IT' => t('Italy'),
          'NL' => t('Netherlands'),
          'PL' => t('Poland'),
          'PT' => t('Portugal'),
          'RU' => t('Russia'),
          'ES' => t('Spain'),
          'CH' => t('Switzerland'),
          'GB' => t('United Kingdom'),
          'US' => t('United States'),
        ),
        t('By language') => array(
          'da_DK' => t('Danish (for Denmark only)'),
          'he_IL' => t('Hebrew (for all)'),
          'id_ID' => t('Indonesian (for Indonesia only)'),
          'jp_JP' => t('Japanese (for Japan only)'),
          'no_NO' => t('Norwegian (for Norway only)'),
          'pt_BR' => t('Brazilian Portuguese (for Portugal and Brazil only)'),
          'ru_RU' => t('Russian (for Lithuania, Latvia, and Ukraine only)'),
          'sv_SE' => t('Swedish (for Sweden only)'),
          'th_TH' => t('Thai (for Thailand only)'),
          'tr_TR' => t('Turkish (for Turkey only)'),
          'zh_CN' => t('Simplified Chinese (for China only)'),
          'zh_HK' => t('Traditional Chinese (for Hong Kong only)'),
          'zh_TW' => t('Traditional Chinese (for Taiwan only)'),
        ),
      ),
      '#default_value' => $settings['language'],
    );
    $form['api_username'] = array(
      '#type' => 'textfield',
      '#title' => t('PayPal API Username'),
      '#description' => t('The PayPal API Username.'),
      '#default_value' => $settings['api_username'],
      '#required' => TRUE,
    );
    $form['api_password'] = array(
      '#type' => 'textfield',
      '#title' => t('PayPal API Password'),
      '#description' => t('The PayPal API Password.'),
      '#default_value' => $settings['api_password'],
      '#required' => TRUE,
    );
    $form['api_signature'] = array(
      '#type' => 'textfield',
      '#title' => t('PayPal API Signature'),
      '#description' => t('The PayPal API Signature.'),
      '#default_value' => $settings['api_signature'],
      '#required' => TRUE,
    );
    $form['cart_items_list'] = array(
      '#type' => 'checkbox',
      '#title' => t('Send the shopping cart item list to PayPal to display in the summary of PayPal payment page.'),
      '#default_value' => $settings['cart_items_list'],
    );
    $form['server'] = array(
      '#type' => 'radios',
      '#title' => t('PayPal server'),
      '#options' => array(
        'sandbox' => ('Sandbox - use for testing, requires a PayPal Sandbox account'),
        'live' => ('Live - use for processing real transactions'),
      ),
      '#default_value' => $settings['server'],
    );

    return $form;
  }
}
