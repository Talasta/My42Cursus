<?php

/**
 *
 */
class NightsWatch
{

  private $_fighters;
  private $_others;

  public function recruit( $arg ) {
    $impts = class_implements($arg);
    if (array_key_exists('IFighter', $impts)) {
      $this->_fighters[] = $arg;
    } else {
      $this->_other[] = $arg;
    }
  }

  public function fight() {
    foreach ($this->_fighters as $fighter) {
      $fighter->fight();
    }
  }

}


?>
