/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:43:03 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/05 15:35:13 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_red(int color)
{
	return ((color & 0x00FF0000) >> 16);
}

static int	get_green(int color)
{
	return ((color & 0x0000FF00) >> 8);
}

static int	get_blue(int color)
{
	return (color & 0x000000FF);
}

t_color		get_converted_color(int color)
{
	t_color new;

	new.r = get_red(color);
	new.g = get_green(color);
	new.b = get_blue(color);
	return (new);
}

t_color		get_color_diff(int color1, int color2)
{
	t_color	diff;

	diff.r = get_red(color1) - get_red(color2);
	diff.g = get_green(color1) - get_green(color2);
	diff.b = get_blue(color1) - get_blue(color2);
	return (diff);
}
