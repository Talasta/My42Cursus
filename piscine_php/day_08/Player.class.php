<?php

require_once('JsonSerializables.class.php');
class Player implements JsonSerializables
{

  private $_army;
  private $_name;
  private $_color;

  public function getArmy() { return $this->_army; }
  public function getName() { return $this->_name; }
  public function getColor() { return $this->_color; }

  public static function doc()
  {
      if (file_exists(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ . '.doc.txt'))
          echo file_get_contents(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ .'.doc.txt');
  }

  function __construct( array $kwarg ) {
    if (array_key_exists('name', $kwarg) && array_key_exists('color', $kwarg)) {
      $this->_name = $kwarg['name'];
      $this->_color = $kwarg['color'];
    }
    $this->_army = [];
  }

  function __toString() {
    $out = "Player: name=" . $this->_name . PHP_EOL;
    $out .= "Army:" . PHP_EOL;
    foreach ($this->_army as $value) {
      $out .= $value . PHP_EOL;
    }
    return $out;
  }

  public function getShipByName( $name ) {
    foreach ($this->_army as $value) {
      if ($name == $value->getName()) {
        return $value;
      }
    }
    return NULL;
  }

  public function stillShipToPlay() {
    foreach($this->_army as $ship) {
      if ($ship->getStatus() == 0) {
        return 1;
      }
    }
    return 0;
  }

  public function resetArmy() {
    foreach($this->_army as $ship) {
      $ship->setShield(0);
      $ship->setStatus(0);
    }
  }

  public function add_ship( $ship ) {
    $this->_army[] = $ship;
  }

  public function removeShip( $key ) {
      unset($this->_army[$key]);
  }

  public function jsonSerialize() {
    $army = [];
    foreach ($this->_army as $value) {
      $army[] = array(get_class($value), $value->jsonSerialize());
    }
    return [
      '_name' => $this->_name,
      '_color' => $this->_color,
      '_army' => $army
    ];
  }

  public static function jsonUnserialize( $jsonString ) {
    $new = new self( [] );
    $new->_name = $jsonString->_name;
    $new->_color = $jsonString->_color;
    foreach ($jsonString->_army as $value) {
      $new->_army[] = Spaceship::jsonUnserialize($value);
    }
    return $new;
  }

}


 ?>
