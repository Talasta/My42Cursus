<?PHP

include_once("database.php");

function	disp_products_pan($session)
{
	$data = ft_get_products_pan($session['login_connected']);
	$total_price = 0;
	echo '<form method="POST" action="action_validate.php">'
		. '<input name="ID" type="hidden" value="' . $session['login_connected'] . '" />'
		. '<input class="archive" type="submit" name="archive" value="Validate" />'
		. '</form>';
	foreach ($data as $prod)
	{
		echo '<p class="elem">'
			. ucfirst($prod[0]) . ':<br><span style="font-family: monospace;"> price ' . $prod[1] . '$ <span style="font-family: monospace;">x ' . $prod[4]
			. '</span><form class="al_del" method="POST" action="action_delete.php">'
			. '<input name="IDu" type="hidden" value="' . $prod[2] . '" />'
			. '<input name="IDp" type="hidden" value="' . $prod[3] . '" />'
			. '<input class="delete" type="submit" name="Delete" value="Delete" />'
			. '</form>'
			. '</p>';
		$total_price += $prod[2] * $prod[4];
	}
	echo '<p class="price">'
		. 'Total: ' . $total_price . '$'
		. '</p>';
}

function	ft_get_nb_id($id)
{
	$cook = unserialize($_COOKIE['cookie_panier']);
	$nbr = 0;
	foreach ($cook as $prod)
	{
		if ($id == $prod)
			$nbr++;
	}
	return $nbr;
}

function	check_data2($data, $id)
{
	foreach ($data as $prod)
	{
		if ($prod[0] == $id)
			return TRUE;
	}
	return FALSE;
}

function	disp_products_pan_no_user()
{
	$cook = unserialize($_COOKIE['cookie_panier']);
	$total_price = 0;
	$data2 = [];
	$i = 0;
	foreach ($cook as $prod)
	{
		$data = ft_get_id_product($prod);
		$data = $data[0];
		$nbr_id = ft_get_nb_id($prod);
		if (!check_data2($data2, $data[1]))
		{
			$data2[$i][0] = $data[1];
			$data2[$i][1] = $data[2];
			$data2[$i][2] = $nbr_id;
			$data2[$i][3] = $prod;
		}
		$total_price += $data[2];
		$i++;
	}
	foreach ($data2 as $prod)
	{
		echo '<p class="elem">'
		. ucfirst($prod[0]) . ':<br><span style="font-family: monospace;"> price ' . $prod[1] . '$ <span style="font-family: monospace;">x ' . $prod[2]
		. '</span><form class="al_del" method="POST" action="action_delete.php">'
			. '<input name="IDp" type="hidden" value="' . $prod[3] . '" />'
			. '<input class="delete" type="submit" name="Delete" value="Delete" />'
			. '</form>'
			. '</p>';
	}
	if ($total_price !== false)
		echo '<p class="price">'
			. 'Total: ' . $total_price . '$'
			. '</p>';

}

function	disp_panier($session)
{
	echo '<div class="panier">';
	echo '<h2>Votre panier</h2>';
	if (isset($session['login_connected']))
	{
		disp_products_pan($session);
	}
	else
		disp_products_pan_no_user();
	echo '</div>';
}
?>
