<?PHP
session_start();
if (!isset($_COOKIE['cookie_panier']))
	setcookie("cookie_panier", serialize([]), time() + 3600);
?>
<html>
<?PHP
include_once("products.php");
include_once("panier.php");
include_once("settings.php");
include_once("admin_controller.php");

$data = file_get_contents("header.html");
echo $data;

if (isset($_SESSION['login_connected']))
{
	$data = file_get_contents("logged.html");
	echo $data;
}
else
{
	$data = file_get_contents("login.html");
	echo $data;
}
if (isset($_GET['setting']))
	ft_get_settings();
else
{
	disp_panier($_SESSION);
	echo '<br />';
	ft_filter();
	if (isset($_GET['filter']) && $_GET['filter']== 'Filter' && isset($_GET['category']) && isset($_GET['size']))
		show_products($_GET['category'], $_GET['size']);
	else
		show_products();
}
button_admin($_SESSION);
if (isset($_SESSION['error']))
	unset($_SESSION['error']);
$data = file_get_contents("footer.html");
echo $data;
?>
</html>
