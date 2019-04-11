<?php

include_once("database.php");

ft_flush_panier($_POST['ID']);

header('Location: index.php');
?>
