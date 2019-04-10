<?php

require_once 'Vector.class.php';

class Matrix
{
  const IDENTITY = "IDENTITY";
  const SCALE = "SCALE";
  const RX = "Ox ROTATION";
  const RY = "Oy ROTATION";
  const RZ = "Oz ROTATION";
  const TRANSLATION = "TRANSLATION";
  const PROJECTION = "PROJECTION";

  private $_matrix;

  public static $verbose = False;

  public function getMatrix() { return $this->_matrix; }

  private function setIdentity() {
    $this->_matrix = [
      [1.0, 0.0, 0.0, 0.0],
      [0.0, 1.0, 0.0, 0.0],
      [0.0, 0.0, 1.0, 0.0],
      [0.0, 0.0, 0.0, 1.0]
    ];
  }

  private function setScale( $k ) {
    $this->_matrix = [
      [$k, 0.0, 0.0, 0.0],
      [0.0, $k, 0.0, 0.0],
      [0.0, 0.0, $k, 0.0],
      [0.0, 0.0, 0.0, 1.0]
    ];
  }

  private function setRX( $k ) {
    $this->_matrix = [
      [1.0, 0.0, 0.0, 0.0],
      [0.0, cos($k), -1.0 * sin($k), 0.0],
      [0.0, sin($k), cos($k), 0.0],
      [0.0, 0.0, 0.0, 1.0]
    ];
  }

  private function setRY( $k ) {
    $this->_matrix = [
      [cos($k), 0.0, sin($k), 0.0],
      [0.0, 1.0, 0.0, 0.0],
      [-1.0 * sin($k), 0.0, cos($k), 0.0],
      [0.0, 0.0, 0.0, 1.0]
    ];
  }

  private function setRZ( $k ) {
    $this->_matrix = [
      [cos($k), -1.0 * sin($k), 0.0, 0.0],
      [sin($k), cos($k), 0.0, 0.0],
      [0.0, 0.0, 1.0, 0.0],
      [0.0, 0.0, 0.0, 1.0]
    ];
  }

  private function setTranslation( Vector $k ) {
    $this->_matrix = [
      [1.0, 0.0, 0.0, $k->getX()],
      [0.0, 1.0, 0.0, $k->getY()],
      [0.0, 0.0, 1.0, $k->getZ()],
      [0.0, 0.0, 0.0, 1.0]
    ];
  }

  private function setProjection( $fov, $ratio, $near, $far ) {
    $s = 1.0 / (tan($fov * 0.5 * M_PI / 180.0));
    $this->_matrix = [
      [$s / $ratio, 0.0, 0.0, 0.0],
      [0.0, $s, 0.0, 0.0],
      [0.0, 0.0, -1.0 * ($far + $near) / ($far - $near), -1.0 * 2 * $far * $near / ($far - $near)],
      [0.0, 0.0, -1.0, 0.0]
    ];
  }

  function __construct( array $kwarg ) {
    if (array_key_exists('preset', $kwarg)) {
      if ($kwarg['preset'] == self::IDENTITY) {
        $this->setIdentity();
      }
      if ($kwarg['preset'] == self::SCALE && array_key_exists('scale', $kwarg)) {
        $this->setScale($kwarg['scale']);
      }
      if ($kwarg['preset'] == self::RX && array_key_exists('angle', $kwarg)) {
        $this->setRX($kwarg['angle']);
      }
      if ($kwarg['preset'] == self::RY && array_key_exists('angle', $kwarg)) {
        $this->setRY($kwarg['angle']);
      }
      if ($kwarg['preset'] == self::RZ && array_key_exists('angle', $kwarg)) {
        $this->setRZ($kwarg['angle']);
      }
      if ($kwarg['preset'] == self::TRANSLATION && array_key_exists('vtc', $kwarg)) {
        $this->setTranslation($kwarg['vtc']);
      }
      if ($kwarg['preset'] == self::PROJECTION && array_key_exists('fov', $kwarg) && array_key_exists('ratio', $kwarg) && array_key_exists('near', $kwarg) && array_key_exists('far', $kwarg)) {
        $this->setProjection($kwarg['fov'], $kwarg['ratio'], $kwarg['near'], $kwarg['far']);
      }
    }

    if (self::$verbose == True) {
      $out = "Matrix " . $kwarg['preset'];
      if ($kwarg['preset'] != self::IDENTITY) {
        $out .= " preset";
      }
      $out .= " instance constructed";
      print($out . PHP_EOL);
    }
  }

  function __destruct() {
    if (self::$verbose) {
      print("Matrix instance destructed" . PHP_EOL);
    }
  }

  function __toString() {
    $out = "M | vtcX | vtcY | vtcZ | vtxO" . PHP_EOL;
    $out .= "-----------------------------" . PHP_EOL;
    $out .= sprintf("x | %.2f | %.2f | %.2f | %.2f", $this->_matrix[0][0], $this->_matrix[0][1], $this->_matrix[0][2], $this->_matrix[0][3]) . PHP_EOL;
    $out .= sprintf("y | %.2f | %.2f | %.2f | %.2f", $this->_matrix[1][0], $this->_matrix[1][1], $this->_matrix[1][2], $this->_matrix[1][3]) . PHP_EOL;
    $out .= sprintf("z | %.2f | %.2f | %.2f | %.2f", $this->_matrix[2][0], $this->_matrix[2][1], $this->_matrix[2][2], $this->_matrix[2][3]) . PHP_EOL;
    $out .= sprintf("w | %.2f | %.2f | %.2f | %.2f", $this->_matrix[3][0], $this->_matrix[3][1], $this->_matrix[3][2], $this->_matrix[3][3]);
    return $out;
  }

  static function doc() {
    $out = file_get_contents('Matrix.doc.txt');
    print($out);
  }

  public function mult( Matrix $rhs ) {
    $new = new Matrix(['preset' => self::IDENTITY]);
    $new->_matrix[0][0] = 0.0;
    $new->_matrix[1][1] = 0.0;
    $new->_matrix[2][2] = 0.0;
    $new->_matrix[3][3] = 0.0;
    $i = -1;
    while (++$i < 4) {
      $j = -1;
      while (++$j < 4) {
        $h = -1;
        while (++$h < 4) {
          $new->_matrix[$i][$j] += $this->_matrix[$i][$h] * $rhs->_matrix[$h][$j];
        }
      }
    }
    return ($new);
  }

  public function transformVertex( Vertex $vtx ) {

    $new = new Vertex(array(
      'x' => 0.0,
      'y' => 0.0,
      'z' => 0.0,
      'w' => 1.0,
      'color' => $vtx->getColor()
    ));
    $i = -1;
    $new->setX($vtx->getX() * $this->_matrix[0][0] + $vtx->getY() * $this->_matrix[0][1] + $vtx->getZ() * $this->_matrix[0][2] + $vtx->getW() * $this->_matrix[0][3]);
    $new->setY($vtx->getX() * $this->_matrix[1][0] + $vtx->getY() * $this->_matrix[1][1] + $vtx->getZ() * $this->_matrix[1][2] + $vtx->getW() * $this->_matrix[1][3]);
    $new->setZ($vtx->getX() * $this->_matrix[2][0] + $vtx->getY() * $this->_matrix[2][1] + $vtx->getZ() * $this->_matrix[2][2] + $vtx->getW() * $this->_matrix[2][3]);
    $new->setW($vtx->getX() * $this->_matrix[3][0] + $vtx->getY() * $this->_matrix[3][1] + $vtx->getZ() * $this->_matrix[3][2] + $vtx->getW() * $this->_matrix[3][3]);
    return $new;
  }

}


?>
