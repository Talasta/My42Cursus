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

function	ft_inarr($data, $name)
{
	foreach($data as $row)
	{
		if ($row['login'] == $name)
			return FALSE;
	}
	return TRUE;
}

if (ft_isset($_POST, 'login') && ft_isset($_POST, 'passwd') && $_POST['passwd'] && $_POST['login'])
{
	$file = '../private/passwd';
	$pass = hash('md5', $_POST['passwd']);
	$data = [];
	if (!file_exists("../private"))
		mkdir("../private");
	if (file_exists($file))
	{
		$data = file_get_contents($file);
		$data = unserialize($data);
	}
	if (ft_inarr($data, $_POST['login']))
	{
		$data[] = ['login' => $_POST['login'], 'passwd' => $pass];
		$data = serialize($data);
		file_put_contents($file, $data);
		echo "OK";
	}
	else
		echo "ERROR\n";
}
else
	echo "ERROR\n";

?>
