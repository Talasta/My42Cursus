/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:45:31 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/06 11:06:13 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate(double *y, double *z, int angle)
{
	double	a;

	a = (double)angle;
	a = (a * M_PI) / 180;
	*y = *y * cos(a) - *z * sin(a);
	*z = *y * sin(a) + *z * cos(a);
}

t_pos		setp_parallele(double x, double y, double z, t_cnf c)
{
	t_pos	p;

	p.color = c.setc(z, c.z_min, c.z_max);
	x = x - c.mid_x;
	y = y - c.mid_y;
	p.x = (int)(c.scale * (x + c.cst1 * z * c.z * -1.0) + c.x);
	p.y = (int)(c.scale * (y + 2 / c.cst1 * z * c.z * -1.0) + c.y);
	return (p);
}

t_pos		setp_isometrique(double x, double y, double z, t_cnf c)
{
	t_pos	p;

	p.color = c.setc(z, c.z_min, c.z_max);
	x = x - c.mid_x;
	y = y - c.mid_y;
	p.x = (int)(c.scale * (x * c.cst1 * -1.0 + y * c.cst2) + c.x);
	x = x * (double)c.cst1 / 2.0 * -1.0;
	y = y * (double)c.cst2 / 2.0 * -1.0;
	p.y = (int)(c.scale * ((float)z * c.z + x + y) + c.y);
	x = x * (double)c.cst1 / 2.0;
	return (p);
}

t_pos		setp_conique(double x, double y, double z, t_cnf c)
{
	t_pos	p;
	double	v;

	x = x - c.mid_x;
	y = y - c.mid_y;
	v = c.max_xy;
	p.color = c.setc(z, c.z_min, c.z_max);
	z = (double)c.z * z * -1.0;
	rotate(&y, &z, c.a_x);
	rotate(&x, &z, c.a_y);
	v = 100.0 / (3.5 * v + z) + (double)c.scale;
	p.x = (int)(x * v + (double)c.x);
	p.y = (int)(y * v + (double)c.y);
	return (p);
}
