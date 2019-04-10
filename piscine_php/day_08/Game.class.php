<?php

require_once('Map.class.php');
require_once('JsonSerializables.class.php');

class Game implements JsonSerializables
{

  private $_map;
  private $_player1;
  private $_player2;
  private $_current_player;
  private $_status;
  private $_turn;
  private $_ship;
  private $_dist;

  public function getMap() { return $this->_map; }
  public function getPlayer1() { return $this->_player1; }
  public function getPlayer2() { return $this->_player2; }
  public function getPlayer($id) { return $id == 1 ? $this->_player1 : $this->_player2; }
  public function getStatus() { return $this->_status; }
  public function getCurrentPlayer() { return $this->_current_player; }
  public function getShip() { return $this->_ship; }
  public function getDist() { return $this->_dist; }

  public function setShip( $name ) { $this->_ship = $name; }
  public function SetDist( $k ) { $this->_dist = $k; }

  public static function doc()
  {
      if (file_exists(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ . '.doc.txt'))
          echo file_get_contents(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ .'.doc.txt');
  }

  function __construct( array $kwarg ) {
    if (array_key_exists('player_1', $kwarg) && array_key_exists('player_2', $kwarg)) {
      $this->_player1 = $kwarg['player_1'];
      $this->_player2 = $kwarg['player_2'];
      $this->_current_player = 1;
      $this->_status = -1;
      $this->_turn = 1;
      $this->_map = new Map();
    }
  }

  private function checkShipsDead() {
    foreach ($this->_player1->getArmy() as $key => $ship) {
      if ($ship->getPDC() < 1) {
        $this->_player1->removeShip($key);
      if (count($this->_player1->getArmy) == 0)
        win($this->_player2);
      }
    }
    foreach ($this->_player2->getArmy() as $key => $ship) {
      if ($ship->getPDC() < 1) {
        $this->_player2->removeShip($key);
      if (count($this->_player2->getArmy) == 0)
        win($this->_player1);
      }
    }
  }

  private function newTurn() {
    $this->_turn++;
    $this->_current_player = 1;
    $this->_player1->resetArmy();
    $this->_player2->resetArmy();
  }

  private function switchPlayer() {
    $this->checkShipsDead();
    if ($this->_current_player == 1 && $this->_player2->stillShipToPlay() == 1) {
      $this->_current_player = 2;
    } else if ($this->_player2->stillShipToPlay() == 1) {
      $this->_current_player = 1;
    } else {
      $this->newTurn();
    }
  }

  public function updateStatus() {
    $this->_status = $this->_status + 1;
    if ($this->_status == 5) {
      $this->_status = 0;
      $this->switchPlayer();
    }
  }

  public function updateShield() {
    $this->getPlayer($this->getCurrentPlayer())->getShipByName($this->getShip())->setShield( $this->_dist['shield'] );
  }

  public function jsonSerialize() {
    return [
      '_map' => $this->_map->jsonSerialize(),
      '_player1' => $this->_player1->jsonSerialize(),
      '_player2' => $this->_player2->jsonSerialize(),
      '_current_player' => $this->_current_player,
      '_status' => $this->_status,
      '_turn' => $this->_turn,
      '_ship' => $this->_ship,
      '_dist' => $this->_dist
    ];
  }

  public static function jsonUnserialize( $jsonString ) {
    $new = new self( [] );
    $new->_map = Map::jsonUnserialize($jsonString->_map);
    $new->_player1 = Player::jsonUnserialize($jsonString->_player1);
    $new->_player2 = Player::jsonUnserialize($jsonString->_player2);
    $new->_current_player = $jsonString->_current_player;
    $new->_status = $jsonString->_status;
    $new->_turn = $jsonString->_turn;
    $new->_ship = $jsonString->_ship;
    $new->_dist = $jsonString->_dist;
    return $new;
  }

}

 ?>
