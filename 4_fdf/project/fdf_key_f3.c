/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_f3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:11:48 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/06 15:08:04 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	proj_para(t_mlx mlx)
{
	mlx.cnf.setp = setp_parallele;
	return (mlx);
}

t_mlx	proj_isom(t_mlx mlx)
{
	mlx.cnf.setp = setp_isometrique;
	return (mlx);
}

t_mlx	proj_coni(t_mlx mlx)
{
	mlx.cnf.a_x = 0;
	mlx.cnf.a_y = 0;
	mlx.cnf.rot = 1;
	mlx.cnf.setp = setp_conique;
	return (mlx);
}
