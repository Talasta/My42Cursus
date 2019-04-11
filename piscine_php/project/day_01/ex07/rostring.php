#!/usr/bin/php
<?PHP
if ($argc > 1)
{
	$tab = NULL;
	$buff = explode(" ", $argv[1]);
	foreach($buff as $str)
	{
		if ($str != NULL)
			$tab[] = $str;
	}
	$i = 1;
	while ($i < count($tab))
	{
		echo $tab[$i];
		echo " ";
		$i++;
	}
	echo $tab[0];
	echo "\n";
}
?>
