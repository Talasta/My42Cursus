<?php

require_once('Spaceships/Destroyer.class.php');
require_once('Spaceships/Cuirasse.class.php');
require_once('Spaceships/Fregate.class.php');
require_once('Pos/Pos.class.php');
require_once('Player.class.php');
require_once('Game.class.php');

include_once('controller.php');

$game = postController($_POST);

?>
<html>
<head>
  <link rel="stylesheet" type="text/css" href="index.css">
</head>
<body>
  <div class="map">
    <?php
      $out = $game->getMap()->displayAsteroids();
      foreach($game->getPlayer1()->getArmy() as $ship) {
        $out .= '<div class="ship" style="' . $ship->displayCss($game->getPlayer1()->getColor()) . '</div>' . "\n";
      }
      foreach($game->getPlayer2()->getArmy() as $ship) {
        $out .= '<div class="ship" style="' . $ship->displayCss($game->getPlayer2()->getColor()) . '</div>' . "\n";
      }
      echo $out;
     ?>
  </div>
  <div class="menu">
    <?php echo getMenu( $game );?>
    <div class="info">
        <?php echo getInfo( $game );?>
    </div>
  </div>
</body>
</html>
