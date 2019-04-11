#!/usr/bin/php
<?PHP
while (TRUE)
{
	unset($line);
	echo "Entrez un nombre: ";
	$line = fgets(STDIN);
	if ($line !== FALSE)
	{
		$line = trim($line);
		if (ctype_digit($line))
		{
			echo "Le chiffre $line est ";
			if ($line % 2 == 0)
				echo "Pair\n";
			else
				echo "Impair\n";
		}
		else
			echo "'$line' n'est pas un chiffre\n";
	}
	else
	{
		echo "\n";
		break;
	}
}
?>
