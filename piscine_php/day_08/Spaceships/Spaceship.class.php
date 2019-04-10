<?php

require_once('JsonSerializables.class.php');
require_once(dirname(__DIR__) . '/Pos/Pos.class.php');

abstract class Spaceship implements JsonSerializables
{

  protected $_name;
  protected $_size;
  protected $_sprite;
  protected $_PDC;
  protected $_pos;
  protected $_PP;
  protected $_speed;
  protected $_move;
  protected $_inerty = 0;
  protected $_shield;
  protected $_weapon;
  protected $_status;

  abstract public function resetPP();
  public function getPos() { return $this->_pos; }
  public function getName() { return $this->_name; }
  public function getPP() { return $this->_PP; }
  public function getPDC() { return $this->_PDC; }
  public function getInerty() { return $this->_inerty; }
  public function getSpeed() { return $this->_speed; }
  public function getStatus() { return $this->_status; }
  public function getShield() { return $this->_shield; }

  public function getInertyStatus() {
    if ($this->_inerty == 0) {
      return 0;
    } else if ($this->_inerty < $this->_move) {
      return 1;
    }
    return 2;
  }

  public function setShield( $k ) { $this->_shield = $k; }
  public function setStatus( $k ) { $this->_status = $k; }

  public static function doc()
  {
      if (file_exists(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ . '.doc.txt'))
          echo file_get_contents(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ .'.doc.txt');
  }

  function __construct( $kwarg ) {
    if (array_key_exists('name', $kwarg)) {
      $this->_name = $kwarg['name'];
    }
    if (array_key_exists('pos', $kwarg)) {
      $this->setPos($kwarg['pos']);
    }
    $this->_status = 0;
  }

  function __toString() {
    $out = "Spaceship - type " . get_class($this) . PHP_EOL;
    $out .= "Name: " . $this->_name . PHP_EOL;
    $out .= "Size: " . $this->_size[0] . "-" . $this->_size[1] . PHP_EOL;
    $out .= "PDC: " . $this->_PDC . PHP_EOL;
    $out .= "PP: " . $this->_PP . PHP_EOL;
    $out .= "speed: " . $this->_speed . PHP_EOL;
    $out .= "move: " . $this->_move . PHP_EOL;
    $out .= "shield: " . $this->_shield . PHP_EOL;
    $out .= "Weapon: " . PHP_EOL;
    foreach ($this->_weapon as $val) {
      $out .= "- " . $val . PHP_EOL;
    }
    return $out;
  }

  public function displayCss( $color ) {
    $out = "";
    $os = $this->_pos->getOs();
    if ($os == 1) {
      // Est
      $out = "width: " . $this->_size[1] * 10 . "px; height: ". $this->_size[0] * 10 ."px;"
      . " left: " . ($this->_pos->getX() - $this->_size[1] + 1) * 10 . "px; top: " . $this->_pos->getY() * 10 . "px;"
      . " background-color: $color;" . '" title="' . $this->_name . '">';
    } else if ($os == 2) {
      // Sud
      $out = "width: " . $this->_size[0] * 10 . "px; height: ". $this->_size[1] * 10 ."px;"
      . " left: " . $this->_pos->getX() * 10 . "px; top: " . ($this->_pos->getY() - $this->_size[1]) * 10 . "px;"
      . " background-color: $color;" . '" title="' . $this->_name . '">';
    } else if ($os == 3) {
      // Ouest
      $out = "width: " . $this->_size[1] * 10 . "px; height: ". $this->_size[0] * 10 ."px;"
      . " left: " . $this->_pos->getX() * 10 . "px; top: " . $this->_pos->getY() * 10 . "px;"
      . " background-color: $color;" . '" title="' . $this->_name . '">';
    } else if ($os == 0) {
      // Nord
      $out = "width: " . $this->_size[0] * 10 . "px; height: ". $this->_size[1] * 10 ."px;"
      . " left: " . $this->_pos->getX() * 10 . "px; top: " . $this->_pos->getY() * 10 . "px;"
      . " background-color: $color;" . '" title="' . $this->_name . '">';
    }
    return $out;
  }

  public function setPos( $pos ) {
    if ($pos instanceof Pos) {
      $this->_pos = $pos;
    }
  }

  public function getAllPos() {
    $pos = [];
    $i = 0;
    $os = $this->_pos->getOs();
    if ($os == 1) {
      while ($i < $this->_size[1]) {
        $j = 0;
        while ($j < $this->_size[0]) {
          $pos[] = [$this->_pos->getX() - $i, $this->_pos->getY() - $j];
          $j++;
        }
        $i++;
      }
    } else if ($os == 2) {
      while ($i < $this->_size[0]) {
        $j = 0;
        while ($j < $this->_size[1]) {
          $pos[] = [$this->_pos->getX() - $i, $this->_pos->getY() - $j];
          $j++;
        }
        $i++;
      }
    } else if ($os == 3) {
      while ($i < $this->_size[1]) {
        $j = 0;
        while ($j < $this->_size[0]) {
          $pos[] = [$this->_pos->getX() + $i, $this->_pos->getY() + $j];
          $j++;
        }
        $i++;
      }
    } else if ($os == 0) {
      while ($i < $this->_size[0]) {
        $j = 0;
        while ($j < $this->_size[1]) {
          $pos[] = [$this->_pos->getX() + $i, $this->_pos->getY() + $j];
          $j++;
        }
        $i++;
      }
    }
    return $pos;
  }

  public function move( array $arg, Game $game ) {
    $inerty = 0;
    if ($this->_inerty != $this->_move && $this->_inerty != 0)
    {
        $inerty += $this->_pos->move($this->_move, $game);
    }
    if (array_key_exists('move', $arg)) {
      if ($arg['move'] == 'rotateRight') {
        $this->_pos->rotateRight($this->_size, $this->_move);
      }
      if ($arg['move'] == 'rotateLeft') {
        $this->_pos->rotateLeft($this->_size, $this->_move);
      }
      if ($arg['move'] == 'move' && array_key_exists('lenght', $arg)) {
        $inerty += $this->_pos->move($arg['lenght'], $game);
      }
    }
    $this->_inerty = $inerty;
  }

  public function takeDamage( $n ) {
    if ($this->_shield < $n) {
      $n -= $this->_shield;
      $this->_shield = 0;
      $this->_PDC -= $n;
    } else {
      $this->_shield -= $n;
    }
  }

  public function shoot(array $arg, Game $world) {
    $PP = $arg['pp'];
    $weapon = $this->_weapon[0];
    $weapon->shoot($this->_pos, $PP, $world);
  }

  public function jsonSerialize() {
    $weapons = [];
    foreach ($this->_weapon as $value) {
      $weapons[] = [get_class($value), $value->jsonSerialize()];
    }
    return [
      '_name' => $this->_name,
      '_size' => $this->_size,
      '_sprite' => $this->_sprite,
      '_PDC' => $this->_PDC,
      '_pos' => $this->_pos->jsonSerialize(),
      '_PP' => $this->_PP,
      '_speed' => $this->_speed,
      '_move' => $this->_move,
      '_shield' => $this->_shield,
      '_status' => $this->_status,
      '_inerty' => $this->_inerty,
      '_weapon' => $weapons
    ];
  }

  public static function jsonUnserialize( $jsonString ) {
    $type = $jsonString[0];
    $jsonString = $jsonString[1];
    $new = new $type( [] );
    $new->_name = $jsonString->_name;
    $new->_size = $jsonString->_size;
    $new->_sprite = $jsonString->_sprite;
    $new->_PDC = $jsonString->_PDC;
    $new->_pos = Pos::jsonUnserialize($jsonString->_pos);
    $new->_PP = $jsonString->_PP;
    $new->_speed = $jsonString->_speed;
    $new->_move = $jsonString->_move;
    $new->_shield = $jsonString->_shield;
    $new->_status = $jsonString->_status;
    $new->_inerty = $jsonString->_inerty;
    foreach ($jsonString->_weapon as $value) {
      $new->_weapon[] = Weapon::jsonUnserialize($value);
    }
    return $new;
  }

}

?>
