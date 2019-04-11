<?php

require_once 'Color.class.php';

class Vertex
{

  private $_x;
  private $_y;
  private $_z;
  private $_w;
  private $_color;
  public static $verbose = False;

  public function getX() { return $this->_x; }
  public function getY() { return $this->_y; }
  public function getZ() { return $this->_z; }
  public function getW() { return $this->_w; }
  public function getColor() { return $this->_color; }

  private function setX($attr) { $this->_x = $attr; }
  private function setY($attr) { $this->_y = $attr; }
  private function setZ($attr) { $this->_z = $attr; }
  private function setW($attr) { $this->_w = $attr; }
  private function setColor($attr) { $this->_color = $attr; }


  function __construct( array $kwarg ) {
    if (array_key_exists('x', $kwarg) && array_key_exists('y', $kwarg) && array_key_exists('z', $kwarg)) {
      $this->setX($kwarg['x']);
      $this->setY($kwarg['y']);
      $this->setZ($kwarg['z']);
    }

    if (array_key_exists('w', $kwarg)) {
      $this->setW($kwarg['w']);
    } else {
      $this->setW(1.0);
    }

    if (array_key_exists('color', $kwarg)) {
      $this->setColor($kwarg['color']);
    } else {
      $this->setColor(new Color(['rgb' => 0x00ffffff]));
    }

    if (self::$verbose){
      print($this . " constructed" . PHP_EOL);
    }
  }

  function __destruct() {
    if (self::$verbose){
      print($this . " destructed" . PHP_EOL);
    }
  }

  function __toString() {
    $out = sprintf('Vertex( x: % .2f, y: % .2f, z: % .2f, w: % .2f', $this->getX(), $this->getY(), $this->getZ(), $this->getW());
    if (self::$verbose){
      $out .= ", " . $this->getColor();
    }
    return $out . " )";
  }

  static function doc() {
    $out = file_get_contents("Vertex.doc.txt");
    print($out);
  }

}

?>
