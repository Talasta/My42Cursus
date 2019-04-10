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

function	ft_modif($data, $name, $old, $new)
{
	$i = 0;
	while($i < count($data))
	{
		if ($data[$i]['login'] == $name)
		{
			if ($data[$i]['passwd'] == $old)
			{
				$data[$i]['passwd'] = $new;
				return $data;
			}
			else
				return FALSE;
		}
		$i++;
	}
	return FALSE;
}

if (ft_isset($_POST, 'login') && $_POST['login']
		&& ft_isset($_POST, 'oldpw') && $_POST['oldpw']
		&& ft_isset($_POST, 'newpw') && $_POST['newpw'])
{
	$file = '../private/passwd';
	$passold = hash('md5', $_POST['oldpw']);
	$passnew = hash('md5', $_POST['newpw']);
	$data = [];
	if (!file_exists("../private"))
		mkdir("../private");
	if (file_exists($file))
	{
		$data = file_get_contents($file);
		$data = unserialize($data);
	}
	if (($data = ft_modif($data, $_POST['login'], $passold, $passnew)))
	{
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
