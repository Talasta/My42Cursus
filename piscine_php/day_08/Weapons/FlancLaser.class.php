<?php

require_once('Weapon.class.php');

class FlancLaser extends Weapon
{

  public static function doc()
  {
      if (file_exists(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ . '.doc.txt'))
          echo file_get_contents(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ .'.doc.txt');
  }
  
  function __construct() {
    $this->_charge = 0;
    $this->_range = ['close' => [1, 10], 'mid' => [11, 20] , 'long' => [21, 30]];
    $this->_zone = 'spray';
  }

}


 ?>
