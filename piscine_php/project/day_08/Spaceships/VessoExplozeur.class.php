<?php

require_once(dirname(__DIR__) . '/Spaceships/Spaceship.class.php');
require_once(dirname(__DIR__) . '/Weapons/HeavyGatling.class.php');
require_once(dirname(__DIR__) . '/Weapons/MacroCanon.class.php');

class VessoExplozeur extends Spaceship
{

  public static function doc()
  {
      if (file_exists(__DIR__ . DIRECTORY_SEPARATOR . 'Vesso_explozeur.doc.txt'))
          echo file_get_contents(__DIR__ . DIRECTORY_SEPARATOR . 'Vesso_explozeur.doc.txt');
  }

  function __construct( $kwarg ) {
    parent::__construct( $kwarg );
    $this->_size = [1, 5];
    $this->_PDC = 6;
    $this->_PP = 10;
    $this->_speed = 12;
    $this->_move = 4;
    $this->_shield = 0;
    $this->_weapon = [new MacroCanon()];
  }

  public function resetPP() {
    $this->_PP = 10;
  }

}


 ?>
