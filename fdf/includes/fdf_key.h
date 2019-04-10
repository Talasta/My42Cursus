/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:48:19 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/06 11:34:09 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_KEY_H
# define FDF_KEY_H

# include "fdf.h"

t_mlx	move_right(t_mlx mlx);
t_mlx	move_left(t_mlx mlx);
t_mlx	move_up(t_mlx mlx);
t_mlx	move_down(t_mlx mlx);
t_mlx	rev_iso(t_mlx mlx);
t_mlx	scale_plus(t_mlx mlx);
t_mlx	scale_moins(t_mlx mlx);
t_mlx	alt_plus(t_mlx mlx);
t_mlx	alt_moins(t_mlx mlx);
t_mlx	proj_para(t_mlx mlx);
t_mlx	proj_isom(t_mlx mlx);
t_mlx	proj_coni(t_mlx mlx);
t_mlx	next_map(t_mlx mlx);
t_mlx	color_1(t_mlx mlx);
t_mlx	color_2(t_mlx mlx);
t_mlx	color_3(t_mlx mlx);
t_mlx	color_4(t_mlx mlx);
t_mlx	color_5(t_mlx mlx);
t_mlx	auto_rot(t_mlx mlx);

#endif
