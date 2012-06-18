<?php

/**
 * Implements hook_panels_layouts().
 */
function campuswiki_omega_12_threecol_3_9_stacked_panels_layouts() {
  $items['omega_12_threecol_3_9_stacked'] = array(
    'title' => t('Three Column 3-9 Stacked'),
    'category' => t('Omega: 12 Column Grid'),
    'icon' => 'omega_12_threecol_3_9_stacked.png',
    'theme' => 'omega_12_threecol_3_9_stacked',
    'admin css' => '../omega_panels_admin_12.css',
    'regions' => array(
      'left' => t('Left side'),
      'right' => t('Right side'),
      'top' => t('Top'),
      'center' => t('Center')
    ),
  );

  return $items;
}
