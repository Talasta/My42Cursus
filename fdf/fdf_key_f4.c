/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_f4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:17:53 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/06 09:53:36 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	color_1(t_mlx mlx)
{
	mlx.cnf.setc = setc_rg;
	return (mlx);
}

t_mlx	color_2(t_mlx mlx)
{
	mlx.cnf.setc = setc_rgdegrade;
	return (mlx);
}

t_mlx	color_3(t_mlx mlx)
{
	mlx.cnf.setc = setc_orangepurpledegrade;
	return (mlx);
}

t_mlx	color_4(t_mlx mlx)
{
	mlx.cnf.setc = setc_realistique;
	return (mlx);
}

t_mlx	color_5(t_mlx mlx)
{
	mlx.cnf.setc = setc_ultrarealistique;
	return (mlx);
}
