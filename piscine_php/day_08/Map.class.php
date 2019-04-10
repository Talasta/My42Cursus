<?php
require_once('JsonSerializables.class.php');

class Map implements JsonSerializables
{
  private $_asteroids;

  public function getAsteriod() { return $this->_asteroids; }

  private function addAsteriod() {
    $x = rand(0, 149);
    $y = rand (0, 99);
    $s = rand(2,10);
    foreach (range(-$s, $s) as $i) {
      foreach (range(-$s, $s) as $l) {
        if ($x+$i < 150 && $y+$l < 100 && $x+$i >= 0 && $y+$l >= 0 &&
        (($x > 40 || $y > 40) && ($x < 110 || $y < 60)) &&
        pow(abs($i),2) + pow(abs($l),2) < pow($s, 2) + rand(-$s,$s)) {
          $this->_asteroids[] = [$x+$i, $y+$l];
        }
      }
    }
  }

  public static function doc()
  {
      if (file_exists(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ . '.doc.txt'))
          echo file_get_contents(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ .'.doc.txt');
  }

  function __construct() {
    $nb = rand(10, 20);
    $i = 0;
    while (++$i < $nb) {
      $this->addAsteriod();
    }
  }

  public function displayAsteroids() {
    $out = "";
    foreach ($this->_asteroids as $asteroids) {
      $out .= '<div class="ship" style="'
      . "width: 10px; height: 10px;"
      . " left: " . $asteroids[0] * 10 . "px; top: " . $asteroids[1] * 10 . "px;"
      . " background-color: #000000;"
      . '"></div>' . "\n";
    }
    return $out;
  }

  public function jsonSerialize() {
    return [
      '_asteroids' => $this->_asteroids
    ];
  }

  public static function jsonUnserialize( $jsonString ) {
    $new = new self( NULL );
    $new->_asteroids = $jsonString->_asteroids;
    return $new;
  }

}



 ?>
