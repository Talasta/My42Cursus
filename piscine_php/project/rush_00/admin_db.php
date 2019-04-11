<?PHP
session_start();
include_once("database.php");

function	ft_user_db($p)
{
	if (isset($p['submit']) && isset($p['login']) && isset($p['passwd']) && $p['login'] && $p['passwd'])
	{
		if ($p['admin'])
			$p['admin'] = 'true';
		else
			$p['admin'] = 'false';
		if ($p['submit'] == 'Update')
			ft_update_user($p['ID'], $p['login'], hash("md5", $p['passwd']), $p['admin']);
		if ($p['submit'] == 'Delete')
			ft_delete_user($p['ID']);
		if ($p['submit'] == 'Add')
		{
			ft_add_new_user($p['login'], hash("md5",$p['passwd']), $p['admin']);
		}
		if ($p['submit'] == 'More Info')
		{
					header("Location: admin_usr.php?id=" . $p['ID']);
					die();
		}
	}
}

function	ft_product_db($p)
{
	if (isset($p['submit']) && isset($p['name']) && isset($p['price']) && $p['name'] && $p['price'] > 0)
	{
		if ($p['submit'] == 'Update')
			ft_update_product($p['ID'], $p['name'], $p['price'], $p['desq']);
		if ($p['submit'] == 'Delete')
			ft_delete_product($p['ID']);
		if ($p['submit'] == 'Add')
			ft_add_new_product($p['name'], $p['price'], $p['desq']);
	}
}

function	ft_category_db($p)
{
	if (isset($p['submit']) && isset($p['name']) && $p['name'])
	{
		if ($p['submit'] == 'Update')
			ft_update_category($p['ID'], $p['name']);
		if ($p['submit'] == 'Delete')
			ft_delete_category($p['ID']);
		if ($p['submit'] == 'Add')
			ft_add_new_category($p['name']);
		if ($p['submit'] == 'More Info')
		{
					header("Location: admin_cat.php?id=" . $p['ID']);
					die();
		}
	}
}

function	ft_panier_db($p)
{
	if (isset($p['submit']) && isset($p['name']))
	{
		if ($p['submit'] == 'Update')
			ft_update_panier($p['pID'], $p['uID'], $p['count'], $p['status']);
		if ($p['submit'] == 'Archive')
			ft_archive_panier($p['uID'], $p['pID']);
		if ($p['submit'] == 'Delete')
			ft_delete_panier($p['pID'], $p['uID'], $p['status']);
	}
}

function	ft_link_db($p)
{
	if (isset($p['submit']) && isset($p['cID']) && isset($p['pID']))
	{
		if ($p['submit'] == 'Add')
			ft_add_to_category($p['pID'], $p['cID']);
		if ($p['submit'] == 'Delete')
			ft_del_product_in_category($p['pID'], $p['cID']);
	}
}

if (isset($_SESSION['admin']) && $_SESSION['admin'] == TRUE)
{
	if (isset($_POST['type']))
	{
		if ($_POST['type'] == 'product')
			ft_product_db($_POST);
		if ($_POST['type'] == 'user')
			ft_user_db($_POST);
		if ($_POST['type'] == 'category')
			ft_category_db($_POST);
		if ($_POST['type'] == 'panier')
		{
			ft_panier_db($_POST);
			header("Location: admin_usr.php?id=" . $_POST['uID']);
			die();
		}
		if ($_POST['type'] == 'link')
		{
			ft_link_db($_POST);
			header("Location: admin_cat.php?id=" . $_POST['cID']);
			die();
		}
	}
	header("Location: admin.php?type=" . $_POST['type']);
	die();
}
header("Location: admin.php");
?>
