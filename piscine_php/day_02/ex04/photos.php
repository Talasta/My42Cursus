#!/usr/bin/php
<?PHP
function	ft_url_clean($url, $home)
{
	$addr = explode('src=', $url);
	$addr = trim($addr[1], '"');
	if (preg_match('/http.*?/', $addr) == 0)
		return 'http://' . trim($home, '/') . '/' . trim($addr, '/');
	return $addr;
}

function	ft_get_name($home, $url)
{
	$data = explode("/", $url);
	return trim($home, '/') . '/' . $data[count($data) - 1];
}

if ($argc > 1 && $argv[1])
{
	$ch = curl_init($argv[1]);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
	curl_setopt($ch, CURLOPT_BINARYTRANSFER, true);
	$content = curl_exec($ch);
	$data = preg_match_all('/<img.*?src=".*?"/s', $content, $matchs);
	$matchs = $matchs[0];
	if (count($matchs) != 0 && $matchs[0])
	{
		$home = explode("://", $argv[1]);
		$home = $home[count($home) - 1];
		if(!file_exists($home))
		{
			mkdir($home);
			foreach ($matchs as $key => $match)
			{
				$url = ft_url_clean($match, $argv[1]);
				$ch1 = curl_init($url);
		 		curl_setopt($ch1, CURLOPT_HEADER, 0);
  				curl_setopt($ch1, CURLOPT_RETURNTRANSFER, 1);
				curl_setopt($ch1, CURLOPT_BINARYTRANSFER,1);
		    	$raw=curl_exec($ch1);
			    curl_close($ch1);
				$name = ft_get_name($home, $url);
			    if(file_exists($name))
				{
		    	    unlink($name);
				}
			    $fp = fopen($name,'x');
		    	fwrite($fp, $raw);
			    fclose($fp);
			}
		}
	}
	curl_close($ch);
}
?>
