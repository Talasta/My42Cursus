#!/usr/bin/php
<?PHP
function	ft_mupcase($m)
{
	return $m[1] . strtoupper($m[2]) . $m[3]; 
}

function	ft_replace($line)
{
	$line = $line[0];
	$data = preg_replace_callback(['/(<[^>]*?title=["\'])(.*?)(["\'])/s'], 'ft_mupcase', $line);
	$data = preg_replace_callback(['/(>)(.*?)(<)/s'], 'ft_mupcase', $data);
	return $data;
}

function	ft_get_file_data($file_name)
{
	$fd = fopen($file_name, "r");
	while ($fd)
	{
		$buff = fgets($fd);
		if ($buff)
			$line .= $buff;
		else
			break;
	}
	return ($line);
}
if ($argc == 2 && file_exists($argv[1]))
{
	$line = ft_get_file_data($argv[1]);
	$data = preg_replace_callback("/<a.*<\/a>/s", 'ft_replace', $line);
	echo $data;
}
?>
