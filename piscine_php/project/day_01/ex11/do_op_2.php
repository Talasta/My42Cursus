#!/usr/bin/php
<?PHP
function	ft_error()
{
	exit("Syntax Error\n");
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
			ft_error();
	}
	else
		ft_error();
}

function	ft_split_op($arg)
{
	$tab = NULL;
	$op_list = ["+", "-", "*", "/", "%"];
	foreach($op_list as $op)
	{
		$tab = explode($op, $arg);
		if (count($tab) == 2)
			return array(trim($tab[0], " "), $op, trim($tab[1], " "));
	}
	ft_error();
}

if ($argc == 2)
{
	$tab = ft_split_op($argv[1]);
	ft_operation($tab);
}
else
	ft_error();
?>
