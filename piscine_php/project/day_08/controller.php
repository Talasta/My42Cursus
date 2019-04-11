<?php

function loadNewGame() {
  $p1 = new Player(['name' => 'Empire galactique', 'color' => '#7af442']);
  $p1->add_ship(new Cuirasse(['name' => 'Deux Ex Machina', 'pos' => new Pos(['x' => 15, 'y' => 10, 'os' => 1])]));
//  $p1->add_ship(new Fregate(['name' => 'Scout Alpha 1', 'pos' => new Pos(['x' => 12, 'y' => 13, 'os' => 1])]));
//  $p1->add_ship(new Destroyer(['name' => 'Destroyer Of Titan', 'pos' => new Pos(['x' => 10, 'y' => 17, 'os' => 1])]));
//  $p1->add_ship(new Fregate(['name' => 'Scout Alpha 2', 'pos' => new Pos(['x' => 18, 'y' => 8, 'os' => 1])]));

  $p2 = new Player(['name' => 'Orcs Legion', 'color' => '#bb6c0f']);
  $p2->add_ship(new Cuirasse(['name' => "La Mort Ki Tu", 'pos' => new Pos(['x' => 135, 'y' => 90, 'os' => 3])]));
//  $p2->add_ship(new Fregate(['name' => "Koa Kesta Toa", 'pos' => new Pos(['x' => 138, 'y' => 87, 'os' => 3])]));
//  $p2->add_ship(new Destroyer(['name' => "Dent La Gueul", 'pos' => new Pos(['x' => 135, 'y' => 83, 'os' => 3])]));
//  $p2->add_ship(new Fregate(['name' => "Kawabounga Haha", 'pos' => new Pos(['x' => 130, 'y' => 94, 'os' => 3])]));

  $game = new Game(['player_1' => $p1, 'player_2' => $p2]);
  return $game;
}

function getForm( $game ) {
  if ($game->getStatus() == 0) {
    $player = $game->getCurrentPlayer();
    $out = '<select name="ship">';
    $army = $game->getPlayer($player)->getArmy();
    foreach($army as $value) {
      if ($value->getStatus() == 0) {
        $out .= '<option value="' . $value->getName() . '">' . $value->getName() . '</option>';
      }
    }
    $out .= '</select>';
  } else if ($game->getStatus() == 1) {
    $player = $game->getCurrentPlayer();
    $PP = $game->getPlayer($player)->getShipByName($game->getShip())->getPP();
    $out = "<b>Max pp to spend = " . $PP . "</b><br>";
    $out .= 'Speed : <input name="sp_PP" type="number" min="0" max="' . $PP . '" value="0"><br>';
    $out .= 'Shield : <input name="sh_PP" type="number" min="0" max="' . $PP . '" value="0"><br>';
    $out .= 'Weapon : <input name="wp_PP" type="number" min="0" max="' . $PP . '" value="0"><br>';
  } else if ($game->getStatus() == 2) {
    $player = $game->getCurrentPlayer();
    $dist = $game->getDist();
    $out = "<b>Shield = " . $dist['shield'] . "</b><br>";
    $out .= "<b>Speed pp to spend = " . $dist['speed'] . "</b><br>";
    $inerty = $game->getPlayer($player)->getShipByName($game->getShip())->getInertyStatus();
    $speed = $game->getPlayer($player)->getShipByName($game->getShip())->getSpeed() + $dist['speed'];
    if ($inerty == 0) {
      $out .= '<select name="move">'
      . '<option value="move">Propulsion</option>'
      . '<option value="rotateRight">Rotate Right</option>'
      . '<option value="rotateLeft">Rotate Left</option>'
      . '</select><br>';
      $out .= 'Speed : <input name="speed" type="number" min="0" max="' . $speed . '" value="0"><br>';
    } else if ($inerty == 1) {
      $out .= '<select name="move">'
      . '<option value="move">Propulsion</option>'
      . '<option value="rotateRight" disabled>Rotate Right</option>'
      . '<option value="rotateLeft" disabled>Rotate Left</option>'
      . '</select><br>';
      $out .= 'Speed : <input name="speed" type="number" min="0" max="' . $speed . '" value="0"><br>';
    } else {
      $out .= '<select name="move">'
      . '<option value="move">Propulsion</option>'
      . '<option value="rotateRight">Rotate Right</option>'
      . '<option value="rotateLeft">Rotate Left</option>'
      . '</select><br>';
      $out .= 'Speed : <input name="speed" type="number" min="0" max="' . $speed . '" value="0"><br>';
    }
  } else {
    $dist = $game->getDist();
    $weapon = $dist->weapon;
    $out = "<b>Weapon pp to spend = " . $weapon . "</b><br>";
    $out .= '<input name="pp" type="number" min="0" max="' . $weapon . '" value="0"><br>';
  }
  return $out;
}

function getMenu( $game ) {
  $out = "<b>" . $game->getPlayer($game->getCurrentPlayer())->getName() . "</b>    <i>" . $game->getShip() . "</i><br><br>";
  $out .= '
  <form action="" method="post">
  <input type="hidden" name="loaded" value="done">
  <input type="hidden" name="game" value="' . preg_replace('/"/', "'",json_encode($game->jsonSerialize())) . '">';
  $out .= getForm( $game );
  $out .= '<br><input type="submit" name="submit" value="Submit">
  </form>';
  return $out;
}

function getInfo( $game ) {
  $out = "<b>Player 1: " . $game->getPlayer1()->getName() . "</b><ul>";
  foreach ($game->getPlayer1()->getArmy() as $ship ) {
    $out .= "<li><i>" . $ship->getName() . "</i> |\t <b>PDC</b>: " . $ship->getPDC() . " <b>Shield</b>: " . $ship->getShield() . "</li>";
  }
  $out .= "</ul><b>Player 2: " . $game->getPlayer2()->getName() . "</b><ul>";
  foreach ($game->getPlayer2()->getArmy() as $ship ) {
    $out .= "<li><i>" . $ship->getName() . "</i> |\t <b>PDC</b>: " . $ship->getPDC() . " <b>Shield</b>: " . $ship->getShield() . "</li>";
  }
  $out .= "</ul>";
  return $out;
}

function checkPP($PP, $sp, $sh, $wp) {
  while ($PP < ($wp + $sp + $sh)) {
    if ($wp != 0) {
      $wp--;
    } else if ($sh != 0) {
      $sh--;
    } else if ($sp != 0) {
      $sp--;
    }
  }
  return [
    'speed' => $sp,
    'shield' => $sh,
    'weapon' => $wp
  ];
}

function win($player) {
  echo "<div class='win' style='background-color:".$player->getColor()."'><h1>".$player->getName()." wins !!</h1>
  <form method='post'><input type='submit' value='Restart'></form></div>";
}

function postController( $post ) {
  if (isset($post) && array_key_exists('loaded', $post)) {
    $game = Game::jsonUnserialize(json_decode(preg_replace("/'/", '"',trim($post['game']))));
    $game->updateStatus();
    if ($game->getStatus() == 3) {
      $game->getPlayer($game->getCurrentPlayer())->getShipByName($game->getShip())->move(['move' => $post['move'], 'lenght' => $post['speed']], $game);
      if ($game->getPlayer($game->getCurrentPlayer())->getShipByName($game->getShip())->getPDC() < 1) {
        $game->updateStatus();
      }
    }
    if ($game->getStatus() == 1) {
      $game->setShip($post['ship']);
    } else if ($game->getStatus() == 0 || $game->getStatus() == 4) {
      $game->getPlayer($game->getCurrentPlayer())->getShipByName($game->getShip())->shoot(['pp' => $post['pp']], $game);
      $ship = $game->getPlayer($game->getCurrentPlayer())->getShipByName($game->getShip());
      if ($ship) {
        $ship->setStatus(1);
      }
      $game->updateStatus();
      $game->setShip("");
    } else if ($game->getStatus() == 2) {
      $k = checkPP($game->getPlayer($game->getCurrentPlayer())->getShipByName($game->getShip())->getPP(), $post['sp_PP'], $post['sh_PP'], $post['wp_PP']);
      $game->setDist($k);
      $game->updateShield();
    }
  } else {
    $game = loadNewGame();
    $game->updateStatus();
  }
  return $game;
}

 ?>
