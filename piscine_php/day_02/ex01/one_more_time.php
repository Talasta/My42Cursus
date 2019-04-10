#!/usr/bin/php
<?PHP

function	ft_get_day($day)
{
	$tab = array(
		"1" => "lundi",
		"2" => "mardi",
		"3" => "mercredi",
		"4" => "jeudi",
		"5" => "vendredi",
		"6" => "samedi",
		"7" => "dimanche"
	);
	foreach($tab as $key => $val)
	{
		if ($val === $day)
			return $key;
	}
	return "0";
}

function	ft_get_month($day)
{
	$tab = array(
		"1" => "janvier",
		"2" => "fevrier",
		"3" => "mars",
		"4" => "avril",
		"5" => "mai",
		"6" => "juin",
		"7" => "juillet",
		"8" => "aout",
		"9" => "septembre",
		"10" => "octobre",
		"11" => "novembre",
		"12" => "decembre"
	);
	foreach($tab as $key => $val)
	{
		if ($val === $day)
			return $key;
	}
	return "0";
}

if ($argc > 1)
{
	$mk = NULL;
	$tab = explode(" ", $argv[1]);
	if (count($tab) == 5 && preg_match_all('/[A-Za-z][a-z]*/', $tab[0]) == 1
		&& preg_match_all('/[A-Za-z][a-z]*/', $tab[2]) == 1)
	{
		$day = ft_get_day(strtolower($tab[0]));
		$dayn = $tab[1];
		$month = ft_get_month(strtolower($tab[2]));
		$year = $tab[3];
		$time = explode(":", $tab[4]);
		// annee sur 4 chiffres
		if (count($time) == 3 && $day != "0" && $month != "0" && is_numeric($dayn) && strlen($dayn) <= 2 
				&& preg_match("/[0-9]{4}/", $year) !== 0)
		{
			//check les sur 2 chiffre
			if (preg_match("/[0-9]{2}/", $time[0]) !== 0
				&& preg_match("/[0-9]{2}/", $time[1]) !== 0
				&& preg_match("/[0-9]{2}/", $time[2]) !== 0)
			{
				date_default_timezone_set("Europe/Paris");
				$mk = mktime($time[0], $time[1], $time[2], $month, $dayn, $year, 0);
				echo $mk . "\n";
			}
			else
				echo "Wrong Format\n";
		}
		else
			echo "Wrong Format\n";
	}
	else
		echo "Wrong Format\n";
}
?>
