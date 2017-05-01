<?php
/**
 * @file
 * Views definitions for 'pau_core'
 */
 
/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */
function pau_core_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'pau_core'),
    ),
    'handlers' => array(
      // The name of my handler
      'pau_core_handler_custom_field' => array(
        // The name of the handler we are extending.
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
 
/**
 * Implements hook_views_data().
 */
function pau_core_views_data() {
  $data = array();
  // Add Example group
  $data['pau_core']['table']['group'] = t('Prosegur');
  $data['pau_core']['table']['join'] = array(
    // #global is a special flag which let's a table appear all the time.
    '#global' => array(),
  );
  // Add custom field
  $data['pau_core']['create_audit'] = array(
    'title' => t('Crear auditoria'),
    'help' => t('Crea auditoria basado en tipo de servicio.'),
    'field' => array(
      'handler' => 'pau_core_create_audit_field',
    ),
  );
  return $data;
}