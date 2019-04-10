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
	$login = ft_get_category_name_from_id($_GET['id']);
	$login = $login[0][0];
	echo "<h1>List de " . $login . "</h1>";
	echo "<br />";
	$in = ft_in_cat($_GET['id']);
	$not_in = ft_not_in_cat($_GET['id']);
	echo '<form>'
		. '<input style="width: 200px;" type="text" name="name of product" value="Name of product" disabled>'
		. '</form>';
	echo '<form action="admin_db.php" method="post">'
		. '<input type="hidden" name="type" value="link">'
		. '<input type="hidden" name="cID" value="'.$_GET['id'].'">'
		. '<select name="pID" style="width: 200px;">';
	echo '<option value="0">NULL</option><option disabled>-----</option>';
	foreach ($in as $elem) {
		echo '<option value="' . $elem[0] . '">' . $elem[1] . '</option>';
	}
	echo '</select> <input class="del" type="submit" name="submit" value="Delete"></form>';

	echo '<form action="admin_db.php" method="post">'
		. '<input type="hidden" name="type" value="link">'
		. '<input type="hidden" name="cID" value="'.$_GET['id'].'">'
		. '<select name="pID" style="width: 200px;">';
	echo '<option value="0">NULL</option><option disabled>-----</option>';
	foreach ($not_in as $elem) {
		echo '<option value="' . $elem[0] . '">' . $elem[1] . '</option>';
	}
	echo '</select> <input class="add" type="submit" name="submit" value="Add"></form>';
}
echo '<a style="color: white;" href="admin.php">Go back to main menu</a>';
$data = file_get_contents("footer.html");
echo $data;
?>
