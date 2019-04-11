<?php

class Targaryen
{
  protected $_burning;

  public function resistsFire() {
    return False;
  }

  function __construct() {
    $this->_burning = $this->resistsFire();
  }

  public function getBurned() {
    if ($this->_burning) {
      return "emerges naked but unharmed";
    } else {
      return "burns alive";
    }
  }

}

?>
