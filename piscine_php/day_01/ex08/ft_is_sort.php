<?PHP
function	ft_is_sort($tab)
{
	$buff = $tab;
	sort($buff);
	$i = 0;
	while ($i < count($tab))
	{
		if (strcmp($tab[$i], $buff[$i]) != 0)
			return 0;
		$i++;
	}
	return 1;
}
?>
