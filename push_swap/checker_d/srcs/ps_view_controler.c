/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_view_controler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:09:58 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/19 19:36:00 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ps_execute_action(t_mlx *mlx)
{
	int		r;
	t_op	*lst_op;
	t_list	*buff;

	if (mlx->cmd)
	{
		lst_op = ps_get_op_lst();
		r = 0;
		while (r < 11 && ft_strcmp(mlx->cmd->content, lst_op[r].cmd))
			r++;
		if (r == 11)
			return (-1);
		buff = mlx->cmd;
		mlx->cmd = mlx->cmd->next;
		ps_free_cmd(buff);
		lst_op[r].op(mlx->data);
		mlx->count++;
		return (0);
	}
	return (-1);
}

void	ps_get_statusinfo(t_mlx *mlx)
{
	char	*str;

	str = ft_itoa(mlx->count);
	mlx_string_put(mlx->mlx, mlx->win, 10, 5, 0x00FFFFFF, str);
	free(str);
	if (mlx->cmd)
	{
		str = ft_strdup(mlx->cmd->content);
		mlx_string_put(mlx->mlx, mlx->win, mlx->img.size_line / 4 - 40, \
				5, 0x00FFFFFF, str);
		free(str);
	}
}

int		refresh(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (mlx->status == 0)
	{
		usleep(10000);
		mlx->status = ps_execute_action(mlx);
		*mlx = ps_data_to_img(*mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
		ps_get_statusinfo(mlx);
	}
	return (0);
}

int		actions(int key_hook, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (key_hook == 53)
	{
		mlx_destroy_image(mlx, mlx->img.img);
		mlx_destroy_window(mlx, mlx->win);
		exit(1);
	}
	return (0);
}
