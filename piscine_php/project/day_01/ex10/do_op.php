#!/usr/bin/php
<?PHP
function	ft_error($msg)
{
	exit($msg);
}

function	ft_mul($a, $b)
{
	echo $a * $b;
	echo "\n";
}

function	ft_div($a, $b)
{
	echo $a / $b;
	echo "\n";
}

function	ft_mod($a, $b)
{
	echo $a % $b;
	echo "\n";
}

function	ft_add($a, $b)
{
	echo $a + $b;
	echo "\n";
}

function	ft_sub($a, $b)
{
	echo $a - $b;
	echo "\n";
}

function	ft_operation($tab)
{
	$op_list = array(
			["+", "ft_add"], 
			["*", "ft_mul"], 
			["-", "ft_sub"], 
			["/", "ft_div"],
			["%", "ft_mod"]
		);
	$bool = FALSE;
	if (is_numeric($tab[0]) && is_numeric($tab[2]))
	{
		foreach ($op_list as $op)
		{
			if ($tab[1] === $op[0])
			{
				$fct = $op[1];
				$fct($tab[0], $tab[2]);
				$bool = TRUE;
				break 1;
			}
		}
		if ($bool == FALSE)
			ft_error("");
	}
	else
		ft_error("");
}

if ($argc == 4)
{
	$tab = NULL;
	$i = 1;
	while ($i < 4)
	{
		$tab[] = trim($argv[$i], " \t");
		$i++;
	}
	ft_operation($tab);
}
else
	ft_error("Incorrect Parameters\n");
?>
