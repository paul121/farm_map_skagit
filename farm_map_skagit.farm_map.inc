<?php
/**
 * @file
 * Farm Map hooks implemented by the Farm Map Skagit module.
 */

/**
 * Implements hook_farm_map_behaviors().
 */
function farm_map_skagit_farm_map_behaviors() {
  return array(
    'farm_map_skagit' => array(
      'js' => 'farmOS.map.behaviors.farm_map_skagit.js',
    ),
  );
}

/**
 * Implements hook_farm_map_behavior_settings().
 */
function farm_map_skagit_farm_map_behavior_settings($behavior)
{

  // Define Skagit County layers to include.
  $layers = array(
    array('name'=> 'Images/Lidar2016Hillshade', 'type'=>'ImageServer'),
    array('name'=> 'Images/SkagitCounty2017_4inch', 'type'=>'ImageServer'),
    array('name'=> 'Images/SkagitCounty2018_6inch', 'type'=>'ImageServer'),
    array('name'=> 'Images/SkagitCounty2019_4inch', 'type'=>'ImageServer'),
    array('name'=> 'Images/SkagitCounty2019_9inch', 'type'=>'ImageServer'),
  );

  $settings = array();
  if ($behavior == 'farm_map_skagit') {
    $settings['layers'] = $layers;
  }
  return $settings;
}

/**
 * Implements hook_farm_map_view().
 */
function farm_map_skagit_farm_map_view($name, $element) {
  farm_map_add_behavior('farm_map_skagit');
}
