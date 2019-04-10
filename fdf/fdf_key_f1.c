/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_f1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:57:44 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/06 15:05:20 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	scale_plus(t_mlx mlx)
{
	mlx.cnf.scale++;
	return (mlx);
}

t_mlx	scale_moins(t_mlx mlx)
{
	if (mlx.cnf.scale > 1)
		mlx.cnf.scale--;
	return (mlx);
}

t_mlx	alt_plus(t_mlx mlx)
{
	mlx.cnf.z -= 0.1;
	return (mlx);
}

t_mlx	alt_moins(t_mlx mlx)
{
	mlx.cnf.z += 0.1;
	return (mlx);
}

t_mlx	next_map(t_mlx mlx)
{
	mlx = fdf_loadnext_map(mlx);
	return (mlx);
}
