<?PHP
function	ft_get_settings()
{
	$data = file_get_contents("settings.html");
	echo $data;
}
?>
