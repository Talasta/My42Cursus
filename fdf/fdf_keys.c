/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:47:08 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/06 12:52:33 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_key.h"

static t_keyfunct	*init_keys(void)
{
	static t_keyfunct	new[19] = {
		{69, &scale_plus},
		{78, &scale_moins},
		{123, &move_left},
		{124, &move_right},
		{125, &move_down},
		{126, &move_up},
		{82, &rev_iso},
		{47, &alt_plus},
		{43, &alt_moins},
		{18, &proj_para},
		{19, &proj_isom},
		{20, &proj_coni},
		{71, &next_map},
		{83, &color_1},
		{84, &color_2},
		{85, &color_3},
		{86, &color_4},
		{87, &color_5},
		{67, &auto_rot}
	};

	return (new);
}

t_mlx				execute_action(int key, t_mlx mlx)
{
	t_keyfunct	*list_action;
	int			i;

	list_action = init_keys();
	i = 0;
	while (i < 19)
	{
		if (key == list_action[i].key)
		{
			mlx = list_action[i].fct(mlx);
			return (mlx);
		}
		i++;
	}
	return (mlx);
}
