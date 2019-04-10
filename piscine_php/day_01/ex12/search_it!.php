#!/usr/bin/php
<?PHP
if ($argc > 2)
{
	$key = $argv[1];
	$i = 1;
	$save = NULL;
	while (++$i < $argc)
	{
		$tab = explode(":", $argv[$i]);
		if (count($tab) == 2 && $key === $tab[0])
			$save = $tab[1];
	}
	if ($save != NULL)
		echo $save . "\n";
}
?>
