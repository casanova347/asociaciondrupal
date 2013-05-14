<?php

/**
 * @file
 * Provides PayPal NVP API class
 */

/**
 * Class PaypalNVP.
 *
 * Conector for NVP paypal API
 */
class PaypalNVP {

  /**
   * Function to perform the API call to PayPal using API signature.
   *
   * @param string $method_name
   *   The method name to invoke
   * @param array $params
   *   the parameters that are sent in the method call
   * @param array $settings
   *   The auth query string
   *
   * @return array
   *   returns an associtive array containing the response from the server.
   */
  static public function call($method_name, $params = array(), $settings = array()) {
    $api_url = $settings['server'];

    // Convert array params to query string format.
    $params_str = drupal_http_build_query($params);

    // Form header string.
    $authentication_str = "PWD=" . urlencode($settings['api_password']) . "&USER=" . urlencode($settings['api_username']) . "&SIGNATURE=" . urlencode($settings['api_signature']);

    // Setting the curl parameters.
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $api_url);
    curl_setopt($ch, CURLOPT_VERBOSE, 1);

    // Turning off the server and peer verification(TrustManager Concept).
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE);
    curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, FALSE);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_POST, 1);

    // Params + signature.
    $request_str = $authentication_str . '&' . $params_str;

    $request_str = "METHOD=" . urlencode($method_name) . "&VERSION=88.0&" . $request_str;

    // Setting the  POST FIELD to curl.
    curl_setopt($ch, CURLOPT_POSTFIELDS, $request_str);

    $response = curl_exec($ch);

    if (empty($response)) {
      watchdog('PaypalNVP', 'CURL connection with PayPal return empty response. !errors', array('!errors' => curl_error($ch)), WATCHDOG_ERROR);
    }
    else {
      $info = curl_getinfo($ch);
    }

    curl_close($ch);

    if (empty($info['http_code'])) {
      watchdog('PaypalNVP', 'No HTTP code was returned. !errors', array('!errors' => curl_error($ch)), WATCHDOG_ERROR);
    }

    // Convert query string response to an array.
    $response_data = drupal_get_query_array($response);

    return $response_data;
  }

}
