<?PHP
session_start();
unset($_SESSION['login_connected']);
if ($_SESSION['admin'])
	unset($_SESSION['admin']);
header('Location: index.php');
?>
