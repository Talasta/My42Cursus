<?PHP
session_start();

include_once("database.php");

function	ft_add_cookie($id_product, $nbr)
{
	$cook = unserialize($_COOKIE['cookie_panier']);
	$i = 0;
	while ($i < $nbr) {
		$cook[] = $id_product;
		$i++;
	}
	setcookie('cookie_panier', serialize($cook));
}

if (!isset($_POST['size']) || $_POST['size'] < 1)
	$size = 1;
else
	$size = intval($_POST['size']);
$i = 0;
while ($i < $size)
{
	if (isset($_SESSION['login_connected']))
		ft_add_panier($_POST['ID'], $_SESSION['login_connected']);
	else
	{
		ft_add_cookie($_POST['ID'], $size);
		$i = $size;
	}
	$i++;
}
header("Location: index.php");
?>
