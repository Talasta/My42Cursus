<?php

require_once 'Matrix.class.php';

class Camera
{

  private $_tT;
  private $_tR;
  private $_Proj;
  private $_origin;
  private $_view_matrix;

  public static $verbose = False;

  private function getOrigin() { return $this->_origin; }

  function __construct( array $kwarg ) {
    if (array_key_exists('width', $kwarg)
      && array_key_exists('height', $kwarg)
      && !array_key_exists('ratio', $kwarg)) {
      $ratio = $kwarg['width'] / $kwarg['height'];
    } else if (array_key_exists('ratio', $kwarg)) {
      $ratio = $kwarg['ratio'];
    } else {
      die();
    }
    if (array_key_exists('origin', $kwarg)
      && array_key_exists('orientation', $kwarg)
      && array_key_exists('fov', $kwarg)
      && array_key_exists('near', $kwarg)
      && array_key_exists('far', $kwarg)) {
        $this->_origin = $kwarg['origin'];
        $optv = new Vector(['dest' => $kwarg['origin']]);
        $optv = $optv->opposite();
        $this->_tT = new Matrix(['preset' => Matrix::TRANSLATION, 'vtc' => $optv]);
        $this->_tR = $kwarg['orientation']->transposeMatrix();
        $this->_view_matrix = $this->_tR->mult($this->_tT);
        $this->_Proj = new Matrix(array(
          'preset' => Matrix::PROJECTION,
        	'fov' => $kwarg['fov'],
        	'ratio' => $ratio,
        	'near' => $kwarg['near'],
        	'far' => $kwarg['far']
        ));
      }
      if (self::$verbose) {
        print("Camera instance constructed" . PHP_EOL);
      }
  }

  function __destruct() {
    if (self::$verbose) {
      print("Camera instance destructed" . PHP_EOL);
    }
  }

  function __toString() {
    $out = "Camera(" . PHP_EOL;
    $out .= "+ Origine: " . $this->getOrigin() . PHP_EOL;
    $out .= "+ tT:" . PHP_EOL . $this->_tT . PHP_EOL;
    $out .= "+ tR:" . PHP_EOL . $this->_tR . PHP_EOL;
    $out .= "+ tR->mult( tT ):" . PHP_EOL . $this->_view_matrix . PHP_EOL;
    $out .= "+ Proj:" . PHP_EOL . $this->_Proj . PHP_EOL . ")";
    return $out;
  }

  public function doc() {
    print(file_get_contents('Camera.doc.txt'));
  }

  public function watchVertex( Vertex $worldVertex ) {
    $newVertex = $this->_Proj->transformVertex($this->_tR->transposeMatrix()->transformVertex($worldVertex));
    return $newVertex;
  }

}


?>
