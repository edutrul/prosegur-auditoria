<?php

/**
 * @file
 * Definition of pau_core_create_audit_field
 */
  
/**
 * Provides a custom views field.
 */
class pau_core_create_audit_field extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }
  
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
  
  function query() {
    // do nothing -- to override the parent query.
  }
  
  function render($data) {
    // If the devel module is enabled, you may view all of the
    // data provided by fields previously added in your view.
    // dpm($data);
    // Insert PHP code here, or display greeting.
    dpm($data);
    if (!empty($data->field_field_tipo_servicio[0]['raw']['target_id'])) {
      $tid = $data->field_field_tipo_servicio[0]['raw']['target_id'];
      $tipo_servicio = taxonomy_term_load($tid);
      $options = array();
      switch ($tipo_servicio->name) {
        case 'AMPLIACIONES':
        case 'CONNECIÓN+CRA CARTERAS':
          $options = array(
            'query' => array(
              'field_auditoria_tecnica' => 'hide',
              'field_auditoria_venta' => 'hide',
              'planificacion_nid' => $data->nid
            )
          );
          break;
        case 'INSTALACIÓN+CONEXIÓN':
          $options = array(
            'query' => array(
              'field_auditoria_servicio' => 'hide',
              'planificacion_nid' => $data->nid
            )
          );
          break;
        case 'SERVICIO TECNICO':
          $options = array(
            'query' => array(
              'field_auditoria_venta' => 'hide',
              'field_auditoria_servicio' => 'hide'              
            )
          );
          break;
      }
      return l('Crear auditoria', 'node/add/auditoria', $options);
    }
    return '';
  }
}