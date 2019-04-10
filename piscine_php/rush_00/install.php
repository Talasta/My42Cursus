<?php
$db = mysqli_connect('localhost', 'root', '123456');
$cmd = file_get_contents("shop.sql");
$cmd = explode(";", $cmd);
foreach($cmd as $sql)
{
  mysqli_query($db, $sql);
}
mysqli_close($db);
header("Location: index.php");
?>
