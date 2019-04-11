<?PHP
if (isset($_SERVER["PHP_AUTH_USER"]) && isset($_SERVER["PHP_AUTH_PW"])
	&& $_SERVER["PHP_AUTH_USER"] === "zaz" && $_SERVER["PHP_AUTH_PW"] === "jaimelespetitsponeys")
{
	$data = file_get_contents('../img/42.png');
	$data = base64_encode($data);
	echo "<html><body>Bonjour Zaz<br />";
	echo "<img src='data:image/png;base64," . $data . "'>";
	echo "</body></html>\n";
}
else
{
	header("HTTP/1.0 401 Unauthorized");
	header("WWW-Authenticate: Basic realm=''Espace membres''");
	echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n";
	connection_aborted();
}
?>
