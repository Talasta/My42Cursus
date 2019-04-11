<?PHP
include_once("database.php");

function	ft_disp_prod()
{
	$data = ft_get_product();
	echo '<form action="admin_db.php" method="post">';
	echo ' <input type="text" name="name" value="Name" disabled>'
		. ' <input type="text" name="price" value="price" disabled>'
		. ' <input type="text" name="desq" value="description" disabled>';
	echo '</form>';
	foreach($data as $prod)
	{
		echo '<form action="admin_db.php" method="post">';
		echo '<input type="hidden" name="ID" value="' . $prod[0] . '">'
			. '<input type="hidden" name="type" value="product">'
			. ' <input type="text" name="name" value="' . $prod[1] . '">'
			. ' <input type="number" step="0.01" min="0" name="price" value="' . $prod[2] . '">'
			. ' <input type="text" name="desq" value="' . $prod[3] . '">'
			. ' <input class="udt" type="submit" name="submit" value="Update">'
			. ' <input class="del" type="submit" name="submit" value="Delete">';
		echo '</form>';
	}
	echo '<p>Add a Product:</p>';
	echo '<form action="admin_db.php" method="post">';
	echo ' <input type="text" name="name" value="">'
		. '<input type="hidden" name="type" value="product">'
		. ' <input type="number" step="0.01" min="0" name="price" value="0">'
		. ' <input type="text" name="desq" value="">'
		. ' <input class="add" type="submit" name="submit" value="Add">';
	echo '</form>';
}

function	ft_disp_user()
{
	$data = ft_get_all_user();
	echo '<form action="admin_db.php" method="post">';
	echo '<input type="text" name="login" value="Login" disabled>'
		. '<input type="text" name="pass" value="Password" disabled>';
	echo '</form>';
	foreach($data as $prod)
	{
		$chk = "";
		if ($prod[3] == "1")
			$chk = " checked";
		echo '<form action="admin_db.php" method="post">';
		echo '<input type="hidden" name="ID" value="' . $prod[0] . '">'
			. '<input type="hidden" name="type" value="user">'
			. ' <input type="text" name="login" value="' . $prod[1] . '"> '
			. ' <input type="text" name="passwd" value="' . $prod[2] . '">'
			. ' admin<input type="checkbox" name="admin" value="admin"' . $chk . '>'
			. ' <input class="udt" type="submit" name="submit" value="Update">'
			. ' <input class="del" type="submit" name="submit" value="Delete">'
			. ' <input class="inf" type="submit" name="submit" value="More Info">';
		echo '</form>';
	}
	echo '<p>Add a User:</p>'
		. '<form action="admin_db.php" method="post">';
	echo ' <input type="text" name="login" value=""> '
		. '<input type="hidden" name="type" value="user">'
		. ' <input type="text" name="passwd" value="">'
		. ' admin<input type="checkbox" name="admin" value="admin">'
		. ' <input class="add" type="submit" name="submit" value="Add">';
	echo '</form>';
}


function	ft_disp_category()
{
	$data = ft_get_category();
	echo '<form action="admin_db.php" method="post">';
	echo '<input type="text" name="ID" value="Name" disabled>';
	echo '</form>';
	foreach($data as $prod)
	{
		echo '<form action="admin_db.php" method="post">';
		echo '<input type="hidden" name="ID" value="' . $prod[0] . '">'
			. '<input type="hidden" name="type" value="category">'
			. ' <input type="text" name="name" value="' . $prod[1] . '">'
			. ' <input class="udt" type="submit" name="submit" value="Update">'
			. ' <input class="del" type="submit" name="submit" value="Delete">'
			. ' <input class="inf" type="submit" name="submit" value="More Info">';
		echo '</form>';
	}
	echo '<p>Add a Category:</p>';
	echo '<form action="admin_db.php" method="post">'
		. '<input type="hidden" name="type" value="category">'
		. ' <input type="text" name="name" value="">'
		. ' <input class="add" type="submit" name="submit" value="Add">';
	echo '</form>';
}

function	ft_disp($get)
{
	$data = file_get_contents("admin_nav.html");
	echo $data;
	echo '<div class="admin_panel">';
	if (!isset($get['type']))
		$get['type'] = 'product';
	echo "<h1>" . strtoupper($get['type']) . "S</h1>";
	if (isset($get['type']))
	{
		if ($get['type'] == "user")
			ft_disp_user();
		else if ($get['type'] == "category")
			ft_disp_category();
		else
			ft_disp_prod();
	}
	else
		ft_disp_prod();
	echo '</div>';
}


?>
