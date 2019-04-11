<?php

require_once(dirname(__DIR__) . '/Spaceships/Spaceship.class.php');
require_once(dirname(__DIR__) . '/Weapons/BeamLaser.class.php');

class Harponneur extends Spaceship
{

  public static function doc()
  {
      if (file_exists(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ . '.doc.txt'))
          echo file_get_contents(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ .'.doc.txt');
  }

  function __construct( $kwarg ) {
    parent::__construct( $kwarg );
    $this->_size = [1, 4];
    $this->_PDC = 5;
    $this->_PP = 10;
    $this->_speed = 15;
    $this->_move = 4;
    $this->_shield = 0;
    $this->_weapon = [new BeamLaser()];
  }

  public function resetPP() {
    $this->_PP = 10;
  }

}


 ?>
