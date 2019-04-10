<?php

require_once('JsonSerializables.class.php');
abstract class Weapon implements JsonSerializables
{

  protected $_charge;
  protected $_range;
  protected $_zone;

  public static function doc()
  {
      if (file_exists(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ . '.doc.txt'))
          echo file_get_contents(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ .'.doc.txt');
  }

  function __toString() {
    $out = get_class($this) . ": charge=" . $this->_charge . "; ";
    foreach ($this->_range as $key => $val) {
      $out .= $key . "=" . $val[0] . "-" . $val[1] . ", ";
    }
    $out .= "; " . $this->_zone;
    return $out;
  }

  public function jsonSerialize() {
    return [
      '_charge' => $this->_charge,
      '_range' => $this->_range,
      '_zone' => $this->_zone
    ];
  }

  public static function jsonUnserialize( $jsonString ) {
    $type = $jsonString[0];
    $jsonString = $jsonString[1];
    $new = new $type( [] );
    $new->_charge = $jsonString->_charge;
    $new->_range = $jsonString->_range;
    $new->_zone = $jsonString->_zone;
    return $new;
  }

  public function shoot( Pos $pos, $PP, Game $world) {
    $obstacle = $pos->checkObst($this->_range['long'][1], $world);
    $i = 0;
    if ($obstacle['obj'] instanceof Spaceship) {
      $ship = $obstacle['obj'];
      if ($obstacle['dist'] < $this->_range['mid'][0]) {
        $min = 4;
      } else if ($obstacle['dist'] > $this->_range['mid'][1]) {
        $min = 6;
      } else {
        $min = 5;
      }
      while ($i++ < $PP + $this->_charge) {
        if (rand(1, 6) >= $min) {
          $ship->takeDamage(1);
        }
      }
    }
  }

}


 ?>
