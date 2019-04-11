/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:43:58 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/07 10:32:17 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		actions(int key_hook, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	*mlx = execute_action(key_hook, *mlx);
	*mlx = fdf_map_to_img(*mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	if (key_hook == 53)
	{
		ft_putstr("\033\143");
		mlx->map = free_map(mlx->map);
		mlx_destroy_image(mlx, mlx->img.img);
		mlx_destroy_window(mlx, mlx->win);
		exit(1);
	}
	return (0);
}

int		refresh(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (mlx->cnf.rot == 1)
		mlx->cnf.a_x++;
	if (mlx->cnf.rot == 3)
		mlx->cnf.a_y++;
	*mlx = fdf_map_to_img(*mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	return (0);
}

void	refresh_term(t_mlx mlx)
{
	ft_putendl("\033\143");
	ft_putendl(" _____ _  _        _         ______");
	ft_putendl("|  ____(_) |      | |       |  ____|");
	ft_putendl("| |__   _| |    __| | ___   | |__ ___ _ __");
	ft_putendl("|  __| | | |   / _  |/ _ \\  |  __/ _ \\ '__|");
	ft_putendl("| |    | | |  | (_| |  __/  | | |  __/ |");
	ft_putendl("|_|    |_|_|   \\__,_|\\___|  |_|  \\___|_|\n");
	term_putmap_name(mlx.cnf.argv[mlx.cnf.current]);
	term_putsize_map((int)mlx.map.x, (int)mlx.map.y,
			mlx.cnf.z_max - mlx.cnf.z_min);
	term_options();
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;

	map = fdf_map_init();
	if ((fdf_store_map(argv[1], &map)) == 0)
	{
		map = free_map(map);
		return (0);
	}
	mlx = fdf_init(2000, 1300, "FdF", map);
	mlx = fdf_multimap_init(mlx, argv, argc);
	mlx.map = map;
	mlx = fdf_map_to_img(mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	refresh_term(mlx);
	mlx_hook(mlx.win, 2, (1L << 0), actions, &mlx);
	mlx_loop_hook(mlx.mlx, refresh, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
