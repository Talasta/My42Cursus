#!/usr/bin/php
<?PHP
if ($argc == 2)
{
	$tab = explode(" ", $argv[1]);
	$str = "";
	foreach($tab as $word)
	{
		if ($word != NULL)
			$str .= "$word ";
	}
	$str = trim($str, " ");
	echo "$str\n";
}
?>
