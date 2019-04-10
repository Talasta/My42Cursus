/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_image_drawer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:05:33 by cmaxime           #+#    #+#             */
/*   Updated: 2018/01/30 16:29:46 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_img	reset_img(t_img img)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	while (i < img.size_column)
	{
		j = 0;
		while (j < img.size_line / 4)
		{
			color = img.data[i * img.size_line / 4 + j];
			color = 0;
			img = set_img_pxl(img, j, i, color);
			j++;
		}
		i++;
	}
	return (img);
}

t_img	ps_draw_pile_a(t_img img, t_data *data, int x, int y)
{
	int		cur_y;
	t_list	*elem;

	elem = data->a;
	cur_y = y + 1;
	while (elem)
	{
		line(img, set_t_pos(x, cur_y), \
				set_t_pos(x - (ps_get_content(elem) - data->min) * 2, \
				cur_y), 0x0000FF00);
		if (data->size < 200)
		{
			cur_y++;
			line(img, set_t_pos(x, cur_y), \
					set_t_pos(x - (ps_get_content(elem) - data->min) * 2, \
					cur_y), 0x0000FF00);
			cur_y += 4;
		}
		else
			cur_y += 2;
		elem = elem->next;
	}
	return (img);
}

t_img	ps_draw_pile_b(t_img img, t_data *data, int x, int y)
{
	int		cur_y;
	t_list	*elem;

	elem = data->b;
	cur_y = y + 1;
	while (elem)
	{
		line(img, set_t_pos(x, cur_y), \
				set_t_pos(x + (ps_get_content(elem) - data->min) * 2, \
				cur_y), 0x0000FF00);
		if (data->size < 200)
		{
			cur_y++;
			line(img, set_t_pos(x, cur_y), \
					set_t_pos(x + (ps_get_content(elem) - data->min) * 2, \
					cur_y), 0x0000FF00);
			cur_y += 4;
		}
		else
			cur_y += 2;
		elem = elem->next;
	}
	return (img);
}

t_mlx	ps_data_to_img(t_mlx mlx)
{
	int		x;
	int		y;

	x = mlx.img.size_line / 8;
	y = 30;
	mlx.img = reset_img(mlx.img);
	mlx.img = line(mlx.img, set_t_pos(x, y), \
		set_t_pos(x, mlx.img.size_column - 10), 0x00FFFFFF);
	mlx.img = ps_draw_pile_a(mlx.img, mlx.data, x - 2, y);
	mlx.img = ps_draw_pile_b(mlx.img, mlx.data, x + 2, y);
	return (mlx);
}
