<?PHP
session_start();
include_once("database.php");

if (!isset($_SESSION['admin']))
{
	header("Location: index.php");
	die();
}
$data = file_get_contents("header.html");
echo $data;
$data = file_get_contents("logged.html");
echo $data;
if (isset($_GET['id']))
{
	$login = ft_get_login_from_id($_GET['id']);
	$login = $login[0][0];
	echo "<h1>Panier de " . $login . "</h1>";
	echo "<br />";
	$panier = ft_panier_id($_GET['id'], 1);
	$old_panier = ft_panier_id($_GET['id'], 0);
	echo "<h2>Panier courant</h2>";
	echo '<form action="admin_db.php" method="post">';
	echo '<input type="text" name="name" value="Name" disabled>';
	echo '<input type="text" name="nbr" value="Nbr" disabled>';
	echo '</form>';
	foreach($panier as $item)
	{
		echo '<form action="admin_db.php" method="post">';
		echo '<input type="hidden" name="uID" value="' . $item[1] . '">'
			. '<input type="hidden" name="pID" value="' . $item[2] . '">'
			. '<input type="hidden" name="status" value="1">'
			. '<input type="hidden" name="type" value="panier">'
			. ' <input type="text" name="name" value="' . $item[0] . '">'
			. ' <input type="number" step="1" name="count" min="0" value="' . $item[3] . '">'
			. ' <input class="udt" type="submit" name="submit" value="Update">'
			. ' <input class="add" type="submit" name="submit" value="Archive">'
			. ' <input class="del" type="submit" name="submit" value="Delete">';
		echo '</form>';
	}
	echo "<h2>Historique des achats</h2>";
	foreach($old_panier as $item)
	{
		echo '<form action="admin_db.php" method="post">';
		echo '<input type="hidden" name="uID" value="' . $item[1] . '">'
			. '<input type="hidden" name="pID" value="' . $item[2] . '">'
			. '<input type="hidden" name="status" value="0">'
			. '<input type="hidden" name="type" value="panier">'
			. ' <input type="text" name="name" value="' . $item[0] . '" readonly="readonly">'
			. ' <input type="number" step="1" name="count" min="0" value="' . $item[3] . '" readonly="readonly">'
			. ' <input class="del" type="submit" name="submit" value="Delete">';
		echo '</form>';
	}
}
echo '<a href="admin.php">Go back to main menu</a>';
$data = file_get_contents("footer.html");
echo $data;
?>
