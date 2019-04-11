<?PHP
session_start();

include_once("database.php");

function  ft_filter()
{
  echo '<div class="filter">';
  echo '<form method="get"><select name="category">';
    $data = ft_get_category();
		echo '<option disabled>Category</option><option disabled>──────────</option>';
		echo '<option value="">No filter</option>';
    foreach($data as $cat)
    {
      echo '<option value="' . $cat[1] . '">' . $cat[1] . '</option>';
    }

  echo '</select><select name="size"><option disabled>Size</option><option disabled>──────────</option>'
  . '<option value="0">No limit</option>'
  . '<option value="5">5</option>'
  .  '<option value="10">10</option>'
  .  '<option value="50">50</option>'
  .  '<option value="100">100</option>'
  . '</select>'
  . '<input type="submit" name="filter" value="Filter">'
  . '</form>';
  echo '</div>';
}

function	show_products($category = "", $limit = 15)
{
	if ($category === "")
		$category = NULL;
	$data = ft_fetch_products($category, FALSE, $limit);
	$button = "";
	foreach($data as $prod)
	{
		$button = '<form action="action_panier.php" method="POST">'
			. '<input name="ID" type="hidden" value="' . $prod[0] . '">'
      . '<input class="add_panier_in" type="number" name="size" min="1" value="1">'
      . '<input class="add_panier" type="submit" value="Add">'
			. '</form>';
		echo '<div class="product">'
			. '<div style="display:flex; position: relative; ">'
      . '<p style="margin-top: 0px;"><b>' . ucfirst($prod[1]) . "</b><br>Price: <b>" . $prod[2] . '$</b></p>'
      . '<p style="margin-top: 0px; margin-left:50px; margin-right: 60px; overflow:auto; max-height:100px;"><i>Description:</i><br>' . $prod[3] . "</p>"
      . '</div>'
      . $button
			. "</div>";
	}
}
?>
