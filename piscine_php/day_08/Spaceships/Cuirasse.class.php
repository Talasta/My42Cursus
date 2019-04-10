<?php

require_once(dirname(__DIR__) . '/Spaceships/Spaceship.class.php');
require_once(dirname(__DIR__) . '/Weapons/HeavyBeamlaser.class.php');

class Cuirasse extends Spaceship
{

  public static function doc()
  {
      if (file_exists(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ . '.doc.txt'))
          echo file_get_contents(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ .'.doc.txt');
  }

  function __construct( $kwarg ) {
    parent::__construct( $kwarg );
    $this->_size = [2, 7];
    $this->_PDC = 8;
    $this->_PP = 12;
    $this->_speed = 10;
    $this->_move = 5;
    $this->_shield = 2;
    $this->_weapon = [new HeavyBeamLaser()];
  }

  public function resetPP() {
    $this->_PP = 12;
  }

}


 ?>
