/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:14:45 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/06 15:55:30 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		term_bad_map(void)
{
	ft_putendl("Error: Bad map in input");
	return (0);
}

int		term_prog_usage(void)
{
	ft_putendl("usage: ./fdf [ map ]");
	return (0);
}

void	term_putmap_name(char *name)
{
	ft_putstr("Map : ");
	ft_putendl(name);
}

void	term_putsize_map(int x, int y, int z)
{
	ft_putstr("\nsize x = ");
	ft_putnbr(x);
	ft_putstr("\nsize y = ");
	ft_putnbr(y);
	ft_putstr("\nsize z = ");
	ft_putnbr(z);
	ft_putstr("\n");
}

void	term_options(void)
{
	ft_putendl("\n\n  Controls :\n");
	ft_putendl("you can use the arrows to change the position");
	ft_putendl("\n  Key Board :");
	ft_putendl("[<] [>] to increse or decrese z coef");
	ft_putendl("[1,2,3] to change the projection of the map");
	ft_putendl("'1' =  paralelle\n'2' = isometrique\n'3' = 3D");
	ft_putendl("\n  Numerique Pad :");
	ft_putendl("[clear] to go to the next map");
	ft_putendl("[*] in projection 3D to launche a rotation");
	ft_putendl("[0] to reverse the map in projection para/iso");
	ft_putendl("[1,2,3,4,5] to change the color of the map");
	ft_putstr("'1' = white\n'2' = red/green\n'3' = orange/purple\n");
	ft_putendl("'4' = realistic\n'5' = ultra realistic");
}
