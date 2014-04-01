<?php

/**
 * Company view callback.
 */
function company_view($company) {
  drupal_set_title(entity_label('company', $company));
  return entity_view('company', array(entity_id('company', $company) => $company), 'full');
}
