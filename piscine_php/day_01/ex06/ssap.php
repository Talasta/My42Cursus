#!/usr/bin/php
<?PHP
if ($argc > 1)
{
	$i = 1;
	$result = NULL;
	while ($i < $argc)
	{
		$tab = explode(" ", $argv[$i]);
		foreach($tab as $word)
		{
			if ($word != NULL)
				$result[] = $word;
		}
		$i++;
	}
	sort($result, SORT_STRING);
	foreach($result as $str)
		echo "$str\n";
}
?>
