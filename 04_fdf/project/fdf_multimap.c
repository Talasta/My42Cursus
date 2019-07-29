/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_multimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:45:09 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/06 12:26:27 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	free_map(t_map map)
{
	size_t	i;

	i = 0;
	while (i < map.y)
	{
		free(map.map[i]);
		i++;
	}
	free(map.map);
	map.map = NULL;
	map.x = 0;
	map.y = 0;
	return (map);
}

t_mlx	fdf_multimap_init(t_mlx mlx, char **argv, int argc)
{
	mlx.cnf.argv = argv;
	mlx.cnf.argc = argc;
	mlx.cnf.current = 1;
	return (mlx);
}

t_map	fdf_map_init(void)
{
	t_map	new;

	new.map = NULL;
	new.x = 0;
	new.y = 0;
	return (new);
}

t_mlx	fdf_loadnext_map(t_mlx mlx)
{
	int		current;
	t_map	map;

	mlx.cnf.current = (mlx.cnf.current + 1) % mlx.cnf.argc;
	if (mlx.cnf.current == 0)
		mlx.cnf.current = 1;
	current = mlx.cnf.current;
	mlx.map = free_map(mlx.map);
	map = mlx.map;
	while ((fdf_store_map(mlx.cnf.argv[current], &map)) == 0)
	{
		ft_putstr(mlx.cnf.argv[current]);
		ft_putendl(" is a bad map!");
		current = (current + 1) % mlx.cnf.argc;
		if (current == 0)
			current = 1;
		map = free_map(map);
	}
	mlx.map = map;
	mlx.cnf.current = current;
	mlx = cnf_init(mlx, map);
	refresh_term(mlx);
	return (mlx);
}
