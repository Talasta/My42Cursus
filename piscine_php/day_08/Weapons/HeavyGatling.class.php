<?php

require_once('Weapon.class.php');

class HeavyGatling extends Weapon
{

  public static function doc()
  {
      if (file_exists(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ . '.doc.txt'))
          echo file_get_contents(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ .'.doc.txt');
  }
  
  function __construct() {
    $this->_charge = 5;
    $this->_range = ['close' => [1, 3], 'mid' => [4, 7] , 'long' => [8, 10]];
    $this->_zone = 'point';
  }

}


 ?>
