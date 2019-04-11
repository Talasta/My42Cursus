<?php
function	ft_isset($array, $neddle)
{
	foreach($array as $key => $val)
	{
		if ($neddle === $key)
			return TRUE;
	}
	return FALSE;
}

if (ft_isset($_GET, 'action') && ft_isset($_GET, 'name'))
{
	if (ft_isset($_GET, 'value') && $_GET["action"] == "set")
	{
		setcookie($_GET['name'], $_GET['value'], time()+3600);
	}
	if ($_GET["action"] == "get")
	{
		foreach($_COOKIE as $key1 => $val1)
		{
			if ($key1 == $_GET["name"])
			{
				echo $val1 . "\n";
				break;
			}
		}
	}
	if ($_GET["action"] == "del")
	{
			setcookie($_GET['name'], "", time() - 3600);
	}
}
?>
