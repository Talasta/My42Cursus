<?php

session_start();

include_once("database.php");

function	ft_delete_one_pan_cook($IDp)
{
	$data = [];
	$cook = unserialize($_COOKIE['cookie_panier']);
	$cook = array_reverse($cook);
	$c = 0;
	foreach($cook as $prod)
	{
		if ($c == 0 && $prod == $IDp)
			$c = 1;
		else
			$data[] = $prod;
	}
	$data = array_reverse($data);
	setcookie('cookie_panier', serialize($data));
}

if (isset($_SESSION['login_connected']))
	ft_delete_one_pan($_POST['IDp'], $_POST['IDu'], 1);
else
	ft_delete_one_pan_cook($_POST['IDp']);
header('Location: index.php');
?>
