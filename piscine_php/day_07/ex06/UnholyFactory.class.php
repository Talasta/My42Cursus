<?php

class UnholyFactory
{

  private $_types;
  private $_army;

  public function __construct() {
    $this->_type = [];
    $this->_army = [];
  }

  public function absorb( $arg ) {
    if (is_subclass_of($arg, 'Fighter')) {
      if (array_key_exists($arg->getType(), $this->_types)) {
        print(("(Factory already absorbed a fighter of type " . $arg->getType() . ")" . PHP_EOL));
      } else {
        $this->_types[$arg->getType()] = get_class($arg);
        print("(Factory absorbed a fighter of type " . $arg->getType() . ")" . PHP_EOL);
      }
    } else {
      print("(Factory can't absorb this, it's not a fighter)" . PHP_EOL);
    }
  }

  public function fabricate( $arg ) {
    if (array_key_exists($arg, $this->_types)) {
      $this->_army[] = new $this->_types[$arg]();
      print("(Factory fabricates a fighter of type " . $arg . ")" . PHP_EOL);
      return end($this->_army);
    } else {
      print("(Factory hasn't absorbed any fighter of type " . $arg . ")" . PHP_EOL);
    }
  }

}

?>
