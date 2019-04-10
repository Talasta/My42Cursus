/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:13:27 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/06 15:05:50 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_scale(int x, int y, int s_x, int s_y)
{
	x = (s_x / x) * (2.0 / 3.0);
	y = (s_y / y) * (2.0 / 3.0);
	return (x = x > y ? y : x);
}

int		get_minz(t_map map)
{
	size_t	x;
	size_t	y;
	int		min;

	min = map.map[0][0];
	y = 0;
	while (y < map.y)
	{
		x = 0;
		while (x < map.x)
		{
			if (min > map.map[y][x])
				min = map.map[y][x];
			x++;
		}
		y++;
	}
	return (min);
}

int		get_maxz(t_map map)
{
	size_t	x;
	size_t	y;
	int		max;

	max = map.map[0][0];
	y = 0;
	while (y < map.y)
	{
		x = 0;
		while (x < map.x)
		{
			if (max < map.map[y][x])
				max = map.map[y][x];
			x++;
		}
		y++;
	}
	return (max);
}

t_mlx	cnf_init(t_mlx mlx, t_map map)
{
	mlx.cnf.scale = get_scale(mlx.map.x, mlx.map.y,
			mlx.img.size_line / 4, mlx.img.size_column);
	if (mlx.cnf.scale == 0)
		mlx.cnf.scale = 1;
	mlx.cnf.mid_x = map.x / 2;
	mlx.cnf.mid_y = map.y / 2;
	mlx.cnf.max_xy = (map.x > map.y) ? (double)map.x : (double)map.y;
	mlx.cnf.z_min = get_minz(map);
	mlx.cnf.z_max = get_maxz(map);
	return (mlx);
}

t_mlx	fdf_init(int size_x, int size_y, char *name, t_map map)
{
	t_mlx	mlx;

	mlx.map = map;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, size_x, size_y, name);
	mlx.img.img = mlx_new_image(mlx.mlx, size_x, size_y);
	mlx.img.size_column = size_y;
	mlx.img.data = (int*)mlx_get_data_addr(mlx.img.img, &mlx.img.bpp, \
			&mlx.img.size_line, &mlx.img.endian);
	mlx.cnf.x = size_x / 2;
	mlx.cnf.y = size_y / 2;
	mlx.cnf.cst1 = -0.75;
	mlx.cnf.cst2 = -0.75;
	mlx.cnf.z = -0.1;
	mlx.cnf.a_x = 0;
	mlx.cnf.a_y = 0;
	mlx.cnf.rot = 0;
	mlx.cnf.setc = setc_rg;
	mlx.cnf.setp = setp_isometrique;
	mlx = cnf_init(mlx, map);
	return (mlx);
}
