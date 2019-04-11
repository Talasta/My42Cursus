/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_cpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:01:58 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/30 11:41:50 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	fdf_map_cpy(t_map map)
{
	t_map	new;
	size_t	i;
	size_t	j;

	new.map = (int**)ft_newmatrix(map.x, map.y, sizeof(int*));
	if (!(new.map))
		return (new);
	new.x = map.x;
	new.y = map.y;
	i = 0;
	while (i < map.y)
	{
		j = 0;
		while (j < map.x)
		{
			new.map[i][j] = map.map[i][j];
			j++;
		}
		i++;
	}
	return (new);
}
