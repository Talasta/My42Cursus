<?PHP
session_start();

include_once('database.php');

function	ft_add_cookie_db()
{
	$cook = unserialize($_COOKIE['cookie_panier']);
	foreach ($cook as $prod)
	{
		ft_add_panier($prod, $_SESSION['login_connected']);
	}
	setcookie('cookie_panier', serialize([]), time() - 3600);
	unset($_COOKIE['cookie_panier']);
}

if (isset($_POST['login'])
	&& isset($_POST['passwd']) && $_POST['passwd']
	&& $_POST['login'])
{
	$data = [];
	$hash = hash("md5", $_POST['passwd']);
	$data = ft_get_user($_POST['login']);
	if ($data)
	{
		if ($data[0][2] == $hash)
		{
			if ($data[0][3] == TRUE)
				$_SESSION['admin'] = TRUE;
			$_SESSION['login_connected'] = $_POST['login'];
			ft_add_cookie_db();
		}
		else
		{
			$_SESSION['error'] = "Wrong password";
		}
	}
	else
		$_SESSION['error'] = "Wrong user";
}
else
	$_SESSION['error'] = "Wrong Informations";
header("Location: index.php");
?>
