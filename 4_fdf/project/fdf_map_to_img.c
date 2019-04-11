/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:54:55 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/06 15:06:46 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	reset_img(t_img img)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	while (i < img.size_column)
	{
		j = 0;
		while (j < img.size_line / 4)
		{
			color = img.data[i * img.size_line / 4 + j];
			color = 0;
			img = set_img_pxl(img, j, i, color);
			j++;
		}
		i++;
	}
	return (img);
}

t_pos	set_t_pos(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

t_mlx	fdf_map_to_img(t_mlx mlx)
{
	size_t	x;
	size_t	y;

	mlx.img = reset_img(mlx.img);
	y = 0;
	while (y < mlx.map.y)
	{
		x = 0;
		while (x < mlx.map.x)
		{
			if (x + 1 < mlx.map.x)
				mlx = set_line(mlx, set_t_pos(x, y), set_t_pos(x + 1, y));
			if (y + 1 < mlx.map.y)
				mlx = set_line(mlx, set_t_pos(x, y), set_t_pos(x, y + 1));
			x++;
		}
		y++;
	}
	return (mlx);
}
