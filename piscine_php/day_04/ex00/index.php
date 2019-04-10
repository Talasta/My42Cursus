<?PHP
session_start();
?>
<html>
	<head>
		<title>index.php</title>
		<meta charset="utf-8">
	</head>
	<body align="center">
		<form method="get">
<?PHP
function	ft_isset($array, $neddle)
{
	foreach($array as $key => $elem)
	{
		if ($key === $neddle)
			return  TRUE;
	}
	return FALSE;
}

$login = "";
$passwd = "";
if (ft_isset($_GET, 'login') && ft_isset($_GET, 'passwd'))
{
	$_SESSION['login'] = $_GET['login'];
	$_SESSION['passwd'] = $_GET['passwd'];
}
if (ft_isset($_SESSION, 'login'))
	$login = $_SESSION['login'];
if (ft_isset($_SESSION, 'passwd'))
	$passwd = $_SESSION['passwd'];
echo 'Identifiant: <input type="text" name="login" value="' . $login . '">' . "\n" . '</br>' . "\n";
echo 'Mot de Passe: <input type="password" name="passwd" value="' . $passwd . '"></ br>' . "\n";
echo '<input type="submit" value="OK"></ br>' . "\n";
?>
		</form>
	</body>
</html>
