<?php

require_once('Weapon.class.php');

class HeavyBeamLaser extends Weapon
{

  public static function doc()
  {
      if (file_exists(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ . '.doc.txt'))
          echo file_get_contents(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ .'.doc.txt');
  }
  
  function __construct() {
    $this->_charge = 3;
    $this->_range = ['close' => [1, 30], 'mid' => [31, 60] , 'long' => [61, 90]];
    $this->_zone = 'ray';
  }

}


 ?>
