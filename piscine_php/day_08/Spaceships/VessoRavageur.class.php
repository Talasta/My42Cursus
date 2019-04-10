<?php

require_once(dirname(__DIR__) . '/Spaceships/Spaceship.class.php');
require_once(dirname(__DIR__) . '/Weapons/FlancLaser.class.php');

class VessoRavageur extends Spaceship
{

  public static function doc()
  {
      if (file_exists(__DIR__ . DIRECTORY_SEPARATOR . 'Vesso_ravageur.doc.txt'))
          echo file_get_contents(__DIR__ . DIRECTORY_SEPARATOR . 'Vesso_ravageur.doc.txt');
  }

  function __construct( $kwarg ) {
    parent::__construct( $kwarg );
    $this->_size = [1, 2];
    $this->_PDC = 4;
    $this->_PP = 10;
    $this->_speed = 16;
    $this->_move = 3;
    $this->_shield = 0;
    $this->_weapon = [new FlancLaser()];
  }

  public function resetPP() {
    $this->_PP = 10;
  }

}


 ?>
