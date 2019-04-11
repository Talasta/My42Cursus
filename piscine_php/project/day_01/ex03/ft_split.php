<?PHP
function ft_split($str)
{
	$tab =  NULL;
	$buff = explode(" ", $str);
	foreach($buff as $word)
	{
		if ($word != NULL)
			$tab[] = $word;
	}
	sort($tab, SORT_STRING);
	return ($tab);
}
?>
