/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:58:47 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/04 19:20:34 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(int o_color, double delta, t_color c_color)
{
	int		color;
	t_color	old;

	color = 0x00000000;
	old = get_converted_color(o_color);
	color = color | (old.r - (int)(c_color.r * delta));
	color = color << 8;
	color = color | (old.g - (int)(c_color.g * delta));
	color = color << 8;
	color = color | (old.b - (int)(c_color.b * delta));
	return (color);
}

t_img	line_x(t_img img, t_pos p1, t_pos p2, t_color c_color)
{
	t_line	l;
	int		i;
	int		color;

	l.xi = (p2.x - p1.x > 0) ? 1 : -1;
	l.yi = (p2.y - p1.y > 0) ? 1 : -1;
	l.dx = (p2.x - p1.x) * l.xi;
	l.dy = (p2.y - p1.y) * l.yi;
	i = -1;
	l.e = l.dx / 2;
	while (++i <= l.dx)
	{
		color = get_color(p1.color, (double)i / (double)l.dx, c_color);
		img = set_img_pxl(img, p1.x, p1.y, color);
		p1.x += l.xi;
		l.e += l.dy;
		if (l.e > l.dx)
		{
			l.e -= l.dx;
			p1.y += l.yi;
		}
	}
	return (img);
}

t_img	line_y(t_img img, t_pos p1, t_pos p2, t_color c_color)
{
	t_line	l;
	int		i;
	int		color;

	l.xi = (p2.x - p1.x > 0) ? 1 : -1;
	l.yi = (p2.y - p1.y > 0) ? 1 : -1;
	l.dx = (p2.x - p1.x) * l.xi;
	l.dy = (p2.y - p1.y) * l.yi;
	i = -1;
	l.e = l.dy / 2;
	while (++i <= l.dy)
	{
		color = get_color(p1.color, (double)i / (double)l.dy, c_color);
		img = set_img_pxl(img, p1.x, p1.y, color);
		p1.y += l.yi;
		l.e += l.dx;
		if (l.e > l.dy)
		{
			l.e -= l.dy;
			p1.x += l.xi;
		}
	}
	return (img);
}

t_img	line(t_img img, t_pos p1, t_pos p2)
{
	t_line	l;
	t_color	c_color;

	c_color = get_color_diff(p1.color, p2.color);
	l.xi = (p2.x - p1.x > 0) ? 1 : -1;
	l.yi = (p2.y - p1.y > 0) ? 1 : -1;
	l.dx = (p2.x - p1.x) * l.xi;
	l.dy = (p2.y - p1.y) * l.yi;
	if (l.dx > l.dy)
		img = line_x(img, p1, p2, c_color);
	else
		img = line_y(img, p1, p2, c_color);
	return (img);
}

t_mlx	set_line(t_mlx mlx, t_pos p1, t_pos p2)
{
	mlx.img = line(mlx.img,
			mlx.cnf.setp((double)p1.x, (double)p1.y,
				(double)mlx.map.map[p1.y][p1.x], mlx.cnf),
			mlx.cnf.setp((double)p2.x, (double)p2.y,
				(double)mlx.map.map[p2.y][p2.x], mlx.cnf));
	return (mlx);
}
