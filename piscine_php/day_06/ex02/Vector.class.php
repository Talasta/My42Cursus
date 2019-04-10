<?php

require_once 'Vertex.class.php';

class Vector
{

  private $_x;
  private $_y;
  private $_z;
  private $_w;
  public static $verbose = False;

  public function getX() { return $this->_x; }
  public function getY() { return $this->_y; }
  public function getZ() { return $this->_z; }
  public function getW() { return $this->_w; }

  private function setX( $val ) { $this->_x = $val; }
  private function setY( $val ) { $this->_y = $val; }
  private function setZ( $val ) { $this->_z = $val; }
  private function setW( $val ) { $this->_w = $val; }

  function __construct( array $kwarg ) {
    if (array_key_exists('dest', $kwarg)) {
      if (!array_key_exists('orig', $kwarg)) {
        $kwarg['orig'] = new Vertex(['x' => 0.0, 'y' => 0.0, 'z' => 0.0]);
      }
      $this->setX($kwarg['dest']->getX() - $kwarg['orig']->getX());
      $this->setY($kwarg['dest']->getY() - $kwarg['orig']->getY());
      $this->setZ($kwarg['dest']->getZ() - $kwarg['orig']->getZ());
    }
    $this->setW(0.0);

    if (self::$verbose) {
      print($this . " constructed" . PHP_EOL);
    }
  }

  function __destruct() {
    if (self::$verbose) {
      print($this . " destructed" . PHP_EOL);
    }
  }

  function __toString() {
    $out = sprintf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f )",
                $this->getX(), $this->getY(), $this->getZ(), $this->getW());
    return $out;
  }

  static function doc() {
      $out = file_get_contents("Vector.doc.txt");
      print($out);
  }

  public function magnitude() {
    return sqrt(pow($this->getX(), 2) + pow($this->getY(), 2) + pow($this->getZ(), 2));
  }

  public function normalize() {
    $x = $this->getX() / $this->magnitude();
    $y = $this->getY() / $this->magnitude();
    $z = $this->getZ() / $this->magnitude();
    return new Vector(['dest' => new Vertex(['x' => $x, 'y' => $y, 'z' => $z])]);
  }

  public function add( Vector $rhs ) {
    $x = $this->getX() + $rhs->getX();
    $y = $this->getY() + $rhs->getY();
    $z = $this->getZ() + $rhs->getZ();
    return new Vector(['dest' => new Vertex(['x' => $x, 'y' => $y, 'z' => $z])]);
  }

  public function sub( Vector $rhs ) {
    $x = $this->getX() - $rhs->getX();
    $y = $this->getY() - $rhs->getY();
    $z = $this->getZ() - $rhs->getZ();
    return new Vector(['dest' => new Vertex(['x' => $x, 'y' => $y, 'z' => $z])]);
  }

  public function opposite() {
    $x = $this->getX() * -1.0;
    $y = $this->getY() * -1.0;
    $z = $this->getZ() * -1.0;
    return new Vector(['dest' => new Vertex(['x' => $x, 'y' => $y, 'z' => $z])]);
  }

  public function scalarProduct( $k ) {
    $x = $this->getX() * $k;
    $y = $this->getY() * $k;
    $z = $this->getZ() * $k;
    return new Vector(['dest' => new Vertex(['x' => $x, 'y' => $y, 'z' => $z])]);
  }

  public function dotProduct( Vector $rhs )
  {
    return $this->getX() * $rhs->getX() + $this->getY() * $rhs->getY() + $this->getZ() * $rhs->getZ();
  }

  public function cos( Vector $rhs ) {
    return $this->dotProduct($rhs) / ($this->magnitude() * $rhs->magnitude());
  }

  public function crossProduct( Vector $rhs )
  {
    $x = $this->getY() * $rhs->getZ() - $this->getZ() * $rhs->getY();
    $y = $this->getZ() * $rhs->getX() - $this->getX() * $rhs->getZ();
    $z = $this->getX() * $rhs->getY() - $this->getY() * $rhs->getX();
    return new Vector(['dest' => new Vertex(['x' => $x, 'y' => $y, 'z' => $z])]);
  }

}

?>
