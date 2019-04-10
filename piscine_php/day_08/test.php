<?php

require_once('Destroyer.class.php');
require_once('Cuirasse.class.php');
require_once('Fregate.class.php');
require_once('Player.class.php');

$p1 = new Player(['name' => 'Maxime']);
$p1->add_ship(new Cuirasse(['name' => 'V1']));
$p1->add_ship(new Fregate(['name' => 'V2']));
$p1->add_ship(new Destroyer(['name' => 'V3']));
$p1->add_ship( new Fregate(['name' => 'V4']));

echo $p1;

 ?>
