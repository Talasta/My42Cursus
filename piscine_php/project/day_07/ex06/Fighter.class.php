<?php

abstract class Fighter
{

  protected $_type;

  public function getType() { return $this->_type; }

  public function __construct( $kwarg ) {
    $this->_type = $kwarg;
  }

  abstract public function fight( $target );

}


?>
