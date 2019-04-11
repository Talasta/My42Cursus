/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opexe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:58:06 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/15 19:04:44 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_op	*ps_get_op_lst(void)
{
	static t_op	lst[11] = {
		{"sa", &ps_swap_a},
		{"sb", &ps_swap_b},
		{"ss", &ps_swap_ab},
		{"pa", &ps_push_a},
		{"pb", &ps_push_b},
		{"ra", &ps_rotate_a},
		{"rb", &ps_rotate_b},
		{"rr", &ps_rotate_ab},
		{"rra", &ps_rotate_rev_a},
		{"rrb", &ps_rotate_rev_b},
		{"rrr", &ps_rotate_rev_ab}
	};

	return (lst);
}

t_list	*ps_read_cmd(void)
{
	t_list	*cmd;
	char	*line;

	cmd = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (cmd == NULL)
			cmd = ft_lstnew(line, sizeof(char*));
		else
			ft_lstpushback(&cmd, ft_lstnew(line, sizeof(char*)));
		free(line);
	}
	free(line);
	return (cmd);
}

void	ps_free_cmd(t_list *elem)
{
	free(elem->content);
	free(elem);
	elem = NULL;
}

int		ps_opexe_view(t_data *data)
{
	t_list	*cmd;
	t_mlx	mlx;

	cmd = ps_read_cmd();
	mlx = ps_mlx_init(data, cmd);
	mlx = ps_data_to_img(mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_hook(mlx.win, 2, (1L << 0), actions, &mlx);
	mlx_loop_hook(mlx.mlx, refresh, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

int		ps_opexe(t_data *data)
{
	int		r;
	char	*line;
	t_op	*lst_op;

	lst_op = ps_get_op_lst();
	if (data->status == 1)
		ps_print_pile(*data, "start");
	while (get_next_line(0, &line) > 0)
	{
		r = 0;
		while (r < 11 && ft_strcmp(line, lst_op[r].cmd))
			r++;
		free(line);
		if (r == 11)
			return (ps_error());
		lst_op[r].op(data);
		if (data->status == 1)
		{
			usleep(100000);
			ps_print_pile(*data, lst_op[r].cmd);
		}
	}
	free(line);
	return (0);
}
