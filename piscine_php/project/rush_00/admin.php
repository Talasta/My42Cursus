<?PHP
session_start();
if (!($_SESSION['admin'] == TRUE))
{
	header("Location: index.php");
	die('You cannot access this page !!!');
}
?>
<html>
<?PHP
include_once("admin_controller.php");
include_once("admin_disp.php");
$data = file_get_contents("header.html");
echo $data;
$data = file_get_contents("logged.html");
echo $data;
ft_disp($_GET);
button_index();
if (isset($_SESSION['error']))
	unset($_SESSION['error']);
$data = file_get_contents("footer.html");
echo $data;
?>
</html>
