#!/usr/bin/php
<?PHP

$fd = fopen("/var/run/utmpx", "r");
$line = NULL;
while ($buff = fread($fd, 628))
{
	$tab[] = unpack("a224user/a33residu/a3id/a32tty/i1pid/i1type/i1time/i1milli", $buff);
}
sort($tab);
foreach ($tab as $term)
{
	date_default_timezone_set("Europe/Paris");
	$date = date("M d H:i", $term["time"]);
	if ($term["type"] == 7)
		echo trim($term["user"]) . " " . trim($term["tty"]) . "  " . trim($date) . " \n";
}
?>
