#!/usr/bin/php
<?PHP
if ($argc > 1)
{
	$tab = NULL;
	$buff = explode(" ", $argv[1]);
	foreach($buff as $b)
	{
		$buff2 = explode("\t", $b);
		foreach($buff2 as $b2)
		{
			if ($b2 != NULL)
				$tab[] = $b2;
		}
	}
	if ($tab != NULL)
	{
		$str = NULL;
		foreach($tab as $word)
			$str .= $word . " ";
		echo trim($str);
	}
	echo "\n";
}
?>
