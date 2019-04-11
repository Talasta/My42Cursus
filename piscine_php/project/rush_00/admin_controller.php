<?PHP

function	button_admin($session)
{
	if (isset($session['admin']) && $session['admin'] == TRUE)
	{
		echo '<div class="admin_ref">'
			. '<a href="admin.php">'
			. '<input class="admin_btn" type="submit" value="Admin page">
			. </a>'
			. '</div>';
	}
}

function	button_index()
{
	echo '<div class="admin_ref">'
		. '<a href="index.php">'
		. '<input class="admin_btn" type="submit" value="Home page">'
		. '</a>'
		. '</div>';
}

?>
