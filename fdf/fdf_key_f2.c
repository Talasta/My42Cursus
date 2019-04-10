/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_f2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:01:58 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/06 15:06:31 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	move_right(t_mlx mlx)
{
	mlx.cnf.x += 2;
	return (mlx);
}

t_mlx	move_left(t_mlx mlx)
{
	mlx.cnf.x -= 2;
	return (mlx);
}

t_mlx	move_up(t_mlx mlx)
{
	mlx.cnf.y -= 2;
	return (mlx);
}

t_mlx	move_down(t_mlx mlx)
{
	mlx.cnf.y += 2;
	return (mlx);
}

t_mlx	rev_iso(t_mlx mlx)
{
	mlx.cnf.cst1 *= -1;
	mlx.cnf.cst2 *= -1;
	return (mlx);
}
