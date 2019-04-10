<?php

require_once 'Camera.class.php';

class ClassName extends AnotherClass
{

  private $_a;
  private $_b;
  private $_c;

  public static $verbose = False;

  public function getA() { return $this->_a; }
  public function getB() { return $this->_b; }
  public function getC() { return $this->_c; }

  function __construct( array $kwarg ) {
    if (array_key_exists('A', $kwarg)
      && array_key_exists('B', $kwarg)
      && array_key_exists('C', $kwarg)) {
        $this->_a = $kwarg['A'];
        $this->_b = $kwarg['B'];
        $this->_c = $kwarg['C'];
    }
    if (self::$verbose) {
      print("Triangle instance constructed" . PHP_EOL);
    }
  }

  function __destruct() {
    if (self::$verbose) {
      print("Triangle instance destructed" . PHP_EOL);
    }
  }

  public function doc() {
    print(file_get_contents('Triangle.doc.php'));
  }


}


?>
