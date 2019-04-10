<?php

require_once('JsonSerializables.class.php');

class Pos implements JsonSerializables
{

  private $_x;
  private $_y;
  private $_os;

  public function getX() { return $this->_x; }
  public function getY() { return $this->_y; }
  public function getOs() { return $this->_os; }

  public static function doc()
  {
      if (file_exists(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ . '.doc.txt'))
          echo file_get_contents(__DIR__ . DIRECTORY_SEPARATOR . __CLASS__ .'.doc.txt');
  }

  function __construct( $kwarg ) {
    if (array_key_exists('x',$kwarg) && array_key_exists('y', $kwarg) && array_key_exists('os', $kwarg)) {
      $this->_x = $kwarg['x'];
      $this->_y = $kwarg['y'];
      $this->_os = $kwarg['os'];
    }
  }

  public function rotateRight( array $size ) {
    $this->_os = ($this->_os + 1) % 4;
  }

  public function rotateLeft( array $size, $manover ) {
    $this->_os = ($this->_os - 1) % 4;
  }

  public function move( $k, Game $game) {
    $res = $this->checkObst($k, $game);
    if ($this->_os == 1) { $this->_x += $res['dist']; }
    if ($this->_os == 2) { $this->_y += $res['dist']; }
    if ($this->_os == 3) { $this->_x -= $res['dist']; }
    if ($this->_os == 0) { $this->_y -= $res['dist']; }
    if ($res['dist'] != $k)
    {
      if (array_key_exists('obj', $res)) {
        $game->getPlayer($game->getCurrentPlayer())->getShipByName($game->getShip())->takeDamage($res['dist']);
        $res['obj']->takeDamage($res['dist']);
      }
      else
        $game->getPlayer($game->getCurrentPlayer())->getShipByName($game->getShip())->takeDamage(1000);
    }
    return $res['dist'];
  }

  public function checkObst($n, Game $game) {
    $dirx = 0;
    $diry = 0;
    $i = 0;
    $res = array();
    if ($this->_os == 1) {$dirx = 1;}
    if ($this->_os == 2) {$diry = 1;}
    if ($this->_os == 3) {$dirx = -1;}
    if ($this->_os == 0) {$diry = -1;}
    while ($i++ < $n) {
      if ($this->_x + $dirx * $i < 0 || $this->_y + $diry * $i < 0 ||
        $this->_x + $dirx * $i >= 150 || $this->_y + $diry * $i >= 100) {
        return (['dist' => $i]);
      }
      foreach ($game->getMap()->getAsteriod() as $test) {
        if ([$this->_x + $dirx * $i, $this->_y + $diry * $i] == $test) {
          return (['dist' => $i-1]);
        }
      }
      switch ($game->getCurrentPlayer()) {
        case 2 :
        foreach ($game->getPlayer1()->getArmy() as $ship) {
          foreach ($ship->getAllPos() as $test) {
            if ([$this->_x + $dirx * $i, $this->_y + $diry * $i] == $test) {
              return (['dist' => $i, 'obj' => $ship]);
            }
          }
        }
        case 1 :
        foreach ($game->getPlayer2()->getArmy() as $ship) {
          foreach ($ship->getAllPos() as $test) {
            if ([$this->_x + $dirx * $i, $this->_y + $diry * $i] == $test) {
              return (['dist' => $i, 'obj' => $ship]);
            }
          }
        }
      }
    }
    return (['dist' => ($i - 1)]);
  }

  public function jsonSerialize() {
    return [
      '_x' => $this->_x,
      '_y' => $this->_y,
      '_os' => $this->_os
    ];
  }

  public static function jsonUnserialize( $jsonString ) {
    $new = new self( [] );
    $new->_x = $jsonString->_x;
    $new->_y = $jsonString->_y;
    $new->_os = $jsonString->_os;
    return $new;
  }

}


 ?>
