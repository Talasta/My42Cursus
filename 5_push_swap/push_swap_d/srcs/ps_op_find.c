/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:18:57 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/19 18:49:51 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ps_repush_b(t_data *data, char *cmd)
{
	while (data->b)
	{
		cmd = ft_realloc(cmd, "pa\n");
		ps_push_a(data);
	}
	return (cmd);
}

char	*ps_second_round(t_data *data, char *cmd)
{
	int		med;

	med = (data->max - data->min) / 2;
	while (med + 10 < data->max)
		med += 10;
	while (med > data->min - 10 || (data->a && data->b
				&& ps_get_content(data->a) < ps_get_content(data->b)))
	{
		while (data->b && ps_get_content(data->b) > med)
			cmd = ft_realloc(cmd, ps_get_next_op2(data));
		while (ps_pile_a_sorted(data->a))
		{
			while (data->b && ps_get_content(data->b) > med)
				cmd = ft_realloc(cmd, ps_get_next_op2(data));
			while (ps_pile_a_sorted(data->a))
				cmd = ft_realloc(cmd, ps_get_next_op1(data));
		}
		med -= 10;
	}
	return (cmd);
}

char	*ps_shell_sort(t_data *data, char *cmd)
{
	if (ps_pile_a_sorted(data->a))
		cmd = ps_first_round(data, cmd, 1);
	cmd = ps_second_round(data, cmd);
	cmd = ps_repush_b(data, cmd);
	while (ps_pile_a_sorted(data->a))
	{
		while (ps_pile_a_sorted(data->a))
		{
			while (ps_pile_a_sorted(data->a))
				cmd = ft_realloc(cmd, ps_get_next_op1(data));
			if (ps_pile_b_sorted(data->b))
				cmd = ft_realloc(cmd, ps_get_next_op2(data));
			if (data->b)
				cmd = ft_realloc(cmd, ps_add_pa(data));
		}
		cmd = ps_repush_b(data, cmd);
	}
	return (cmd);
}

char	*ps_op_find(t_data *data)
{
	char	*cmd;

	cmd = NULL;
	if (ps_pile_a_sorted(data->a))
	{
		ps_getmed(data);
		if (data->status == 0)
		{
			if (ps_size_lst(data->a) > 15)
				cmd = ps_test(data, cmd);
			else if (ps_size_lst(data->a) > 3)
				cmd = ps_low(data, cmd);
			else
				cmd = ps_rlow(data, cmd);
		}
		else if (data->status == 1)
			cmd = ps_radix_sort(data, cmd);
		else if (data->status == 2)
			cmd = ps_shell_sort(data, cmd);
		cmd = ps_clean_cmd(cmd);
	}
	return (cmd);
}
