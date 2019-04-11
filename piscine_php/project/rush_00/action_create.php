<?PHP
session_start();
?>
<html>
<?php
include_once('database.php');
$data = file_get_contents("header.html");
echo $data;
if (isset($_POST['login']) && $_POST['login'] && isset($_POST['password']) && $_POST['password'] && isset($_POST['c_password']) && $_POST['c_password'] && $_POST['password'] == $_POST['c_password'])
{
		$hash = hash("md5", $_POST['password']);
		$check = ft_add_new_user($_POST['login'], $hash, "false");
		if ($check)
		{
			$_SESSION['login_connected'] = $_POST['login'];
			header("Location: index.php");
		}
}
$data = file_get_contents("create.html");
echo $data;
?>
</html>
