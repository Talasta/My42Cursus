/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:29:16 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/06 11:10:21 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		setc_rg(int z, int min, int max)
{
	(void)min;
	(void)max;
	(void)z;
	return (0x00FFFFFF);
}

int		setc_rgdegrade(int z, int min, int max)
{
	int		color;
	double	delta;
	t_color	diff;

	diff = get_color_diff(0x00FF0000, 0x0000FF00);
	delta = (double)(z - min) / (double)(max - min);
	color = get_color(0x00FF0000, delta, diff);
	return (color);
}

int		setc_orangepurpledegrade(int z, int min, int max)
{
	int		color;
	double	delta;
	t_color	diff;

	diff = get_color_diff(0x00CC00CC, 0x00FFA500);
	delta = (double)(z - min) / (double)(max - min);
	color = get_color(0x00CC00CC, delta, diff);
	return (color);
}

int		setc_realistique(int z, int min, int max)
{
	(void)min;
	if (z <= 0)
		return (0x002F2F9F);
	if (z > 0 && (double)z < (double)max / 16.0)
		return (0x00FCDC90);
	if ((double)z >= (double)max / 16.0
			&& (double)z < (double)max * 5.0 / 8.0)
		return (0x00006625);
	if ((double)z >= (double)max * 5.0 / 8.0
			&& (double)z < (double)max * 7.0 / 8.0)
		return (0x00463431);
	return (0x00FFFFFF);
}

int		setc_ultrarealistique(int z, int min, int max)
{
	double	delta;

	if (z <= 0 && z >= min)
	{
		delta = (double)(z - min) / (double)(0 - min);
		return (get_color(0x000A0A3B, delta,
					get_color_diff(0x000A0A3B, 0x002F2F9F)));
	}
	if (z > 0 && (double)z < (double)max / 16.0)
		return (0x00FCDC90);
	if ((double)z >= (double)max / 16.0
			&& (double)z < (double)max * 5.0 / 8.0)
	{
		delta = ((double)z - (double)max / 16.0) /
			((double)max * 5.0 / 8.0 - (double)max / 16.0);
		return (get_color(0x00006625, delta,
					get_color_diff(0x00006625, 0x001C4232)));
	}
	if ((double)z >= (double)max * 5.0 / 8.0
			&& (double)z < (double)max * 7.0 / 8.0)
		return (0x00463431);
	return (0x00FFFFFF);
}
