<?PHP

$GLOBAL["host"] = "localhost";
$GLOBAL["user"] = "root";
$GLOBAL["passwd"] = "123456";
$GLOBAL["db_name"] = "shop";

function	ft_getdb()
{
	$db = mysqli_connect("localhost", "root", "123456", "shop");
	return $db;
}

function	ft_get_password_from_login($login)
{
	$data = [];
	$db = ft_getdb();
	if($db === false) {
		return FALSE;
	}
	$sql = "SELECT * FROM user WHERE login='" . mysqli_real_escape_string($db ,$login) . "'";
	$result = mysqli_query($db,$sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	mysqli_close($db);
	return $data;
}

function	ft_change_password($login, $pass)
{
	$data = [];
	$db = ft_getdb();
	if($db === false) {
		return FALSE;
	}
	$sql = "UPDATE user SET passwd='" . mysqli_real_escape_string($db ,$pass) . "' WHERE login='" . mysqli_real_escape_string($db ,$login) . "'";
	$result = mysqli_query($db,$sql);
	mysqli_close($db);
}

function	ft_change_login($login, $oldlog)
{
	$data = [];
	$db = ft_getdb();
	if($db === false) {
		return FALSE;
	}
	$sql = "UPDATE user SET login='" . mysqli_real_escape_string($db ,$login) . "' WHERE login='" . mysqli_real_escape_string($db ,$oldlog) . "'";
	$result = mysqli_query($db,$sql);
	if ($result)
		$_SESSION['login_connected'] = $login;
	mysqli_close($db);
}

function	ft_delete_login($login)
{
	$data = [];
	$db = ft_getdb();
	if($db === false) {
		return FALSE;
	}
	$sql = "DELETE FROM user WHERE login='" . mysqli_real_escape_string($db ,$login) . "'";
	$result = mysqli_query($db,$sql);
	mysqli_close($db);
}

function	ft_update_category($ID, $name)
{
	$db = ft_getdb();
	if($db === false) {
		return FALSE;
	}
	$data = ft_get_a_category($name);
	if ($data == NULL)
	{
		$sql = "UPDATE category SET name='" . mysqli_real_escape_string($db ,$name) . "' WHERE ID=" . mysqli_real_escape_string($db ,$ID);
		$result = mysqli_query($db,$sql);
	}
	mysqli_close($db);
}

function	ft_delete_category($ID)
{
	$db = ft_getdb();
	if($db === false) {
		return FALSE;
	}
	$sql = "DELETE FROM category WHERE ID=" . mysqli_real_escape_string($db ,$ID) . "";
	$result = mysqli_query($db,$sql);
	mysqli_close($db);
}

function	ft_add_new_category($name)
{
	$db = ft_getdb();
	if($db === false) {
		return FALSE;
	}
	$data = ft_get_a_category($name);
	if ($data == NULL)
	{
		$sql = "INSERT INTO category (name) VALUES('" . mysqli_real_escape_string($db ,$name) . "')";
		$result = mysqli_query($db,$sql);
		mysqli_close($db);
		return TRUE;
	}
	mysqli_close($db);
	return FALSE;
}

function	ft_update_product($ID, $name, $price, $desq)
{
	$db = ft_getdb();
	if($db === false) {
		return FALSE;
	}
	$data = ft_get_a_product($name);
	if ($data[0][0] == $ID || $data == NULL)
	{
		$sql = "UPDATE product SET name='" . mysqli_real_escape_string($db ,$name) . "', price='" . mysqli_real_escape_string($db ,$price) . "', desq='" . mysqli_real_escape_string($db ,$desq) . "' WHERE ID=" . mysqli_real_escape_string($db ,$ID);
		$result = mysqli_query($db,$sql);
	}
	mysqli_close($db);
}

function	ft_delete_product($ID)
{
	$db = ft_getdb();
	if($db === false) {
		return FALSE;
	}
	$sql = "DELETE FROM product WHERE ID=" . mysqli_real_escape_string($db ,$ID) . "";
	$result = mysqli_query($db,$sql);
	mysqli_close($db);
}

function	ft_add_new_product($name, $price, $desq)
{
	$db = ft_getdb();
	if($db === false) {
		return FALSE;
	}
	$data = ft_get_a_product($name);
	if ($data == NULL)
	{
		$sql = "INSERT INTO product (name, price, desq) VALUES('" . mysqli_real_escape_string($db ,$name) . "', " . mysqli_real_escape_string($db ,$price) . ", '" . mysqli_real_escape_string($db ,$desq) . "')";
		$result = mysqli_query($db,$sql);
	}
	mysqli_close($db);
}

function	ft_update_user($ID, $login, $passwd, $admin)
{
	$db = ft_getdb();
	if($db === false) {
		return FALSE;
	}
	$data = ft_get_user($login);
	if ($data[0][0] == $ID || $data == NULL)
	{
		$sql = "UPDATE user SET login='" . mysqli_real_escape_string($db ,$login) . "', passwd='" . mysqli_real_escape_string($db ,$passwd) . "', admin=" . mysqli_real_escape_string($db ,$admin) . " WHERE ID=" . mysqli_real_escape_string($db ,$ID);
		$result = mysqli_query($db,$sql);
	}
	mysqli_close($db);
}

function	ft_delete_user($ID)
{
	$db = ft_getdb();
	if($db === false) {
		return FALSE;
	}
	$sql = "DELETE FROM user WHERE user.ID=" . mysqli_real_escape_string($db ,$ID) . "";
	$result = mysqli_query($db,$sql);
	mysqli_close($db);
}

function	ft_add_new_user($login, $pass, $admin)
{
	$db = ft_getdb();
	if($db === false) {
		return FALSE;
	}
	$data = ft_get_user($login);
	if ($data == NULL)
	{
		$sql = "INSERT INTO user (login, passwd, admin) VALUES('" . mysqli_real_escape_string($db ,$login) . "', '" . mysqli_real_escape_string($db ,$pass) . "', " . mysqli_real_escape_string($db ,$admin) . ")";
		$result = mysqli_query($db,$sql);
		mysqli_close($db);
		return TRUE;
	}
	mysqli_close($db);
	return FALSE;
}

function	ft_get_a_product($name)
{
	$data = [];
	$db = ft_getdb();
	if($db === false) {
		return NULL;
	}
	$sql="SELECT * FROM product WHERE name='" . mysqli_real_escape_string($db ,$name) . "'";
	$result = mysqli_query($db,$sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	mysqli_close($db);
	return $data;
}

function	ft_get_id_product($id)
{
	$data = [];
	$db = ft_getdb();
	if($db === false) {
		return NULL;
	}
	$sql="SELECT * FROM product WHERE ID='" . mysqli_real_escape_string($db ,$id) . "'";
	$result = mysqli_query($db,$sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	mysqli_close($db);
	return $data;
}

function	ft_get_a_category($name)
{
	$data = [];
	$db = ft_getdb();
	if($db === false) {
		return NULL;
	}
	$sql="SELECT * FROM category WHERE name='" . mysqli_real_escape_string($db ,$name) . "'";
	$result = mysqli_query($db,$sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	mysqli_close($db);
	return $data;
}

function	ft_get_user($login)
{
	$data = [];
	$db = ft_getdb();
	if($db === false) {
		return NULL;
	}
	$sql="SELECT * FROM user WHERE login='" . mysqli_real_escape_string($db ,$login) . "'";
	$result = mysqli_query($db,$sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	mysqli_close($db);
	return $data;
}

function	ft_get_prod_from_login($id, $login)
{
	$data = [];
	$db = ft_getdb();
	if ($db === false)
		return NULL;
	$sql = "SELECT * FROM panier JOIN user ON user.ID=panier.ID_user "
		. "WHERE user.login='" . mysqli_real_escape_string($db ,$login) . "' AND panier.status=1 "
		. "AND panier.ID_product=" . mysqli_real_escape_string($db ,$id);
	$result = mysqli_query($db, $sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	return $data;
}

function	ft_get_productfrom_id($id)
{
	$data = [];
	$db = ft_getdb();
	$user = ft_get_user($login);
	if ($db === false)
		return NULL;
	$sql = "SELECT * FROM product WHERE ID=" . mysqli_real_escape_string($db ,$id);
	$result = mysqli_query($db, $sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	return $data;
}

function	ft_add_panier($id, $login, $ID = -1)
{
	$product = ft_get_productfrom_id($id);
	$data = ft_get_prod_from_login($id, $login);
	$db = ft_getdb();
	$user = ft_get_user($login);
	if ($db === false)
		return FALSE;
	if ($user && $product)
	{
		if ($data)
		{
			$sql = "UPDATE panier SET count = count + 1 WHERE ID_user="
				. mysqli_real_escape_string($db ,$data[0][0]) . " AND ID_product=" . mysqli_real_escape_string($db ,$id) . " AND status=1";
			$result = mysqli_query($db, $sql);
		}
		else
		{
			$sql = "INSERT INTO panier (ID_user, ID_product, count, status) "
				. "VALUES( " . mysqli_real_escape_string($db ,$user[0][0]) . ", " . mysqli_real_escape_string($db ,$id) . ", 1, 1)";
			$result = mysqli_query($db, $sql);
		}
	}
	return TRUE;
}

function	ft_get_product($suffle = FALSE, $size = 0)
{
	$data = [];
	$db = ft_getdb();
	if($db === false) {
		return NULL;
	}
	$sql="SELECT * FROM product";
	$result = mysqli_query($db,$sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	if ($suffle)
		shuffle($data);
	if ($size > 0 && $size < count($data))
		$data = array_slice($data, 0, $size);
	mysqli_close($db);
	return $data;
}

function	ft_get_category($suffle = FALSE, $size = 0)
{
	$data = [];
	$db = ft_getdb();
	if($db === false) {
		return NULL;
	}
	$sql="SELECT * FROM category";
	$result = mysqli_query($db,$sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	if ($suffle)
		shuffle($data);
	if ($size > 0 && $size < count($data))
		$data = array_slice($data, 0, $size);
	mysqli_close($db);
	return $data;
}

function	ft_get_all_user($suffle = FALSE, $size = 0)
{
	$data = [];
	$db = ft_getdb();
	if($db === false) {
		return NULL;
	}
	$sql="SELECT * FROM user";
	$result = mysqli_query($db,$sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	if ($suffle)
		shuffle($data);
	if ($size > 0 && $size < count($data))
		$data = array_slice($data, 0, $size);
	mysqli_close($db);
	return $data;
}

function	ft_get_products_pan($login)
{
	$data = [];
	$id = 0;
	$db = ft_getdb();
	if ($db === false)
		return NULL;
	$sql = "SELECT product.name, product.price, panier.* "
		. "FROM user "
		. "INNER JOIN panier ON user.ID=panier.ID_user "
		. "INNER JOIN product ON product.ID=panier.ID_product "
		. "WHERE user.login='" . mysqli_real_escape_string($db ,$login) . "' AND panier.status=1 ";
	$result = mysqli_query($db, $sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	mysqli_close($db);
	return $data;
}

function	ft_get_product_category($ID_product, $ID_category)
{
	$data = [];
	$id = 0;
	$db = ft_getdb();
	if ($db === false)
		return FALSE;

	$sql = "SELECT * FROM product_category WHERE ID_product=" . mysqli_real_escape_string($db ,$ID_product)
		. " AND ID_category=" . mysqli_real_escape_string($db ,$ID_category);
	$result = mysqli_query($db, $sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	mysqli_close($db);
	return $data;
}

function	ft_add_product_category($ID_product, $category)
{
	$data = [];
	$id = 0;
	$db = ft_getdb();
	if ($db === false)
		return FALSE;
	$data = ft_get_product_category($ID_product, $ID_category);
	if ($data == NULL)
	{
		$sql = "INSERT INTO product_category (ID_product, ID_category) "
			. "VALUES(" . mysqli_real_escape_string($db ,$ID_product) . ", " . mysqli_real_escape_string($db ,$ID_category) . ")";
		$result = mysqli_query($db, $sql);
	}
	mysqli_close($db);
}

function	ft_del_category_product($ID_product, $category)
{
	$db = ft_getdb();
	if ($db === false)
		return FALSE;
	$sql = "DELETE FROM product_category WHERE ID_product=". mysqli_real_escape_string($db ,$ID_product)
		. " AND ID_category=" . mysqli_real_escape_string($db ,$ID_category);
	$result = mysqli_query($db, $sql);
	mysqli_close($db);
}

function	ft_panier_id($ID, $status = 1)
{
	$data = [];
	$id = 0;
	$db = ft_getdb();
	if ($db === false)
		return NULL;
	$sql = "SELECT product.name, panier.* "
		. "FROM user "
		. "INNER JOIN panier ON user.ID=panier.ID_user "
		. "INNER JOIN product ON product.ID=panier.ID_product "
		. "WHERE user.ID='" . mysqli_real_escape_string($db ,$ID) . "' AND panier.status=" . mysqli_real_escape_string($db ,$status) . " ";
	$result = mysqli_query($db, $sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	mysqli_close($db);
	return $data;
}

function	ft_delete_one_pan($IDp, $IDu, $status)
{
	$data = [];
	$id = 0;
	$db = ft_getdb();
	if ($db === false)
		return NULL;
	$sql = "SELECT count FROM panier WHERE ID_user=" . mysqli_real_escape_string($db ,$IDu)
		. " AND ID_product=" . mysqli_real_escape_string($db ,$IDp) . " AND status=" . mysqli_real_escape_string($db ,$status) . " ";
	$result = mysqli_query($db, $sql);
	while ($row = mysqli_fetch_row($result))
		$data[] = $row;
	$count = $data[0][0];
	var_dump($count);
	if ($count > 1)
	{
		$sql = "UPDATE panier SET count = count - 1 WHERE ID_user="
			. $IDu . " AND ID_product=" . $IDp . " AND status=" . $status . " ";
		$result = mysqli_query($db, $sql);
	}
	else
	{
		$sql = "DELETE FROM panier WHERE ID_user=" . $IDu
			. " AND ID_product=" . $IDp . " AND status=" . $status . " ";
		$result = mysqli_query($db, $sql);
	}
	mysqli_close($db);
	return $data;
}

function	ft_delete_panier($IDp, $IDu, $status)
{
	$data = [];
	$id = 0;
	$db = ft_getdb();
	if ($db === false)
		return NULL;
	$sql = "DELETE FROM panier WHERE ID_user=" . mysqli_real_escape_string($db ,$IDu)
		. " AND ID_product=" . mysqli_real_escape_string($db ,$IDp) . " AND status=" . mysqli_real_escape_string($db ,$status);
	$result = mysqli_query($db, $sql);
	mysqli_close($db);
}

function	ft_update_panier($IDp, $IDu, $count, $status)
{
	$db = ft_getdb();
	if ($db === false)
		return FALSE;
	$sql = "UPDATE panier SET count = " . mysqli_real_escape_string($db ,$count) . " WHERE ID_user="
	. mysqli_real_escape_string($db ,$IDu) . " AND ID_product=" . mysqli_real_escape_string($db ,$IDp) . " AND status=" . mysqli_real_escape_string($db ,$status);
	$result = mysqli_query($db, $sql);
	mysqli_close($db);
}

function	ft_in_cat($ID)
{
	$data = [];
	$db = ft_getdb();
	if ($db === false)
		return FALSE;
	$sql = "SELECT product.* FROM product "
	. "INNER JOIN product_category ON product_category.ID_product=product.ID "
	. "WHERE product_category.ID_category=" . mysqli_real_escape_string($db ,$ID);
	$result = mysqli_query($db, $sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	mysqli_close($db);
	return $data;
}

function	ft_not_in_cat($ID)
{
	$data = [];
	$db = ft_getdb();
	if ($db === false)
		return FALSE;
	$sql = "SELECT product.* FROM product "
	. "WHERE ID NOT IN(SELECT product.ID FROM product "
	. "INNER JOIN product_category ON product_category.ID_product=product.ID "
	. "WHERE product_category.ID_category=" . mysqli_real_escape_string($db ,$ID) . ")";
	$result = mysqli_query($db, $sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	mysqli_close($db);
	return $data;
}

function	ft_add_to_category($pID, $cID)
{
	$data = [];
	$db = ft_getdb();
	if ($db === false)
		return FALSE;
	$sql = "SELECT * FROM product_category WHERE ID_product=" . mysqli_real_escape_string($db ,$pID) . " AND ID_category=" . mysqli_real_escape_string($db ,$cID);
	$result = mysqli_query($db, $sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	if($data == NULL)
	{
		$sql = "INSERT INTO product_category (ID_product, ID_category) VALUES(" . mysqli_real_escape_string($db ,$pID) . ", " . mysqli_real_escape_string($db ,$cID) . ")";
		$result = mysqli_query($db, $sql);
	}
	mysqli_close($db);
}

function	ft_del_product_in_category($pID, $cID)
{
	$db = ft_getdb();
	if ($db === false)
		return FALSE;
	$sql = "DELETE FROM product_category WHERE ID_product=" . mysqli_real_escape_string($db ,$pID) . " AND ID_category=" . mysqli_real_escape_string($db ,$cID);
	$result = mysqli_query($db, $sql);
	mysqli_close($db);
}

function	ft_get_category_name_from_id($id)
{
	$data = [];
	$db = ft_getdb();
	if ($db === false)
		return FALSE;
	$sql = "SELECT name FROM category WHERE ID=" . mysqli_real_escape_string($db ,$id);
	$result = mysqli_query($db, $sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	return $data;
}

function	ft_get_login_from_id($id)
{
	$data = [];
	$db = ft_getdb();
	if ($db === false)
		return FALSE;
	$sql = "SELECT login FROM user WHERE ID=" . mysqli_real_escape_string($db ,$id);
	$result = mysqli_query($db, $sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	return $data;
}

function 	ft_fetch_products($category = NULL, $suffle = FALSE, $size = 0)
{
	$data = [];
	$db = ft_getdb();
	if($db === false) {
		return NULL;
	}
	$sql="SELECT product.* FROM product";
	if ($category != NULL)
		$sql .= " INNER JOIN product_category ON product.ID=product_category.ID_product "
		. "INNER JOIN category ON category.ID=product_category.ID_category WHERE category.name='" . mysqli_real_escape_string($db ,$category) . "'";
	$sql .= " GROUP BY product.ID";
	$result = mysqli_query($db,$sql);
	while ($row = mysqli_fetch_row($result))
	{
		$data[] = $row;
	}
	if ($suffle)
		shuffle($data);
	if ($size > 0 && $size < count($data))
		$data = array_slice($data, 0, $size);
	mysqli_close($db);
	return $data;
}

function	ft_flush_panier($login)
{
	$db = ft_getdb();
	if($db === false) {
		return NULL;
	}
	$sql = "UPDATE panier SET status=0 WHERE ID_user IN (SELECT user.ID FROM user WHERE user.login='" . mysqli_real_escape_string($db ,$login) . "')";
	$result = mysqli_query($db,$sql);
	mysqli_close($db);
}

function	ft_archive_panier($uID, $pID)
{
	$db = ft_getdb();
	if($db === false) {
		return NULL;
	}
	$sql = "UPDATE panier SET status=0 WHERE ID_user=" . mysqli_real_escape_string($db ,$uID) . " AND ID_product=" . mysqli_real_escape_string($db ,$pID);
	$result = mysqli_query($db,$sql);
	mysqli_close($db);
}

?>
