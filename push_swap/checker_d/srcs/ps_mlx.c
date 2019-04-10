/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 02:51:17 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/15 16:07:58 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_size_window(t_data *data, size_t *x, size_t *y)
{
	int		min;
	int		max;
	int		nb;
	t_list	*elem;

	elem = data->a;
	min = ps_get_content(elem);
	max = min;
	nb = 1;
	while (elem->next)
	{
		nb++;
		elem = elem->next;
		if (max < ps_get_content(elem))
			max = ps_get_content(elem);
		if (min > ps_get_content(elem))
			min = ps_get_content(elem);
	}
	data->min = min;
	data->max = max;
	data->size = max - min;
	*x = 2 * (max - min) * 2 + 10 * 4 + 1;
	*y = (data->size < 200) ? 5 * nb + 40 : 2 * nb + 40;
}

t_mlx	ps_mlx_init(t_data *data, t_list *cmd)
{
	t_mlx	mlx;
	size_t	size_x;
	size_t	size_y;

	size_x = 0;
	size_y = 0;
	mlx.status = 0;
	mlx.count = 0;
	ps_size_window(data, &size_x, &size_y);
	mlx.mlx = mlx_init();
	mlx.data = data;
	mlx.cmd = cmd;
	mlx.img.size_column = size_y;
	mlx.win = mlx_new_window(mlx.mlx, size_x, size_y, "Push_Swap");
	mlx.img.img = mlx_new_image(mlx.mlx, size_x, size_y);
	mlx.img.data = (int*)mlx_get_data_addr(mlx.img.img, &mlx.img.bpp, \
			&mlx.img.size_line, &mlx.img.endian);
	return (mlx);
}
