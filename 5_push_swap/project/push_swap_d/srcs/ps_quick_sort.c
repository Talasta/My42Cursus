/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:31:30 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/15 12:04:45 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ps_quick_sort_r1(t_list **n, t_data *data, char *cmd)
{
	ps_lstaddfront(n, ps_medval_a(data->a, data->min));
	while (ps_check_min(ps_get_content(*n), data->a, data->min) == 0)
	{
		if (ps_get_content(data->a) <= ps_get_content(*n))
			cmd = ft_realloc(cmd, ps_add_pb(data));
		else
			cmd = ft_realloc(cmd, ps_add_ra(data));
	}
	return (cmd);
}

char	*ps_quick_sort_r2(t_list **n, t_data *data, char *cmd)
{
	int		med;

	med = ps_medval_a(data->a, data->min) + 1;
	while (ps_get_content(data->a) > data->min)
	{
		cmd = ft_realloc(cmd, ps_add_pb(data));
		if (ps_get_content(data->b) <= med)
			cmd = ft_realloc(cmd, ps_add_rb(data));
	}
	ps_lstaddfront(n, med);
	return (cmd);
}

char	*ps_quick_sort_r3(t_list **n, t_data *data, char *cmd)
{
	while (ps_size_lst(data->b) > 4)
	{
		if (ps_get_content(*n) != ps_medval(data->b))
			ps_lstaddfront(n, ps_medval(data->b));
		while (ps_check_max(ps_get_content(*n), data->b) == 0)
		{
			if (ps_get_content(data->b) > ps_get_content(*n))
				cmd = ft_realloc(cmd, ps_add_pa(data));
			else
				cmd = ft_realloc(cmd, ps_add_rb(data));
		}
	}
	cmd = ps_selection_sort_b(data, cmd);
	cmd = ps_pushback_qs(data, cmd);
	ps_lstdelfront(n);
	while (*n && ps_check_min(ps_get_content(*n), data->a, data->min) == 0)
		cmd = ft_realloc(cmd, ps_add_pb(data));
	return (cmd);
}

char	*ps_quick_sort(t_data *data, char *cmd)
{
	t_list	*n;

	n = NULL;
	ps_getmed(data);
	data->min--;
	while (ps_size_lst_qs(data->a, data->min) > 4)
	{
		if (data->max - (data->min + 1) == data->size)
			cmd = ps_quick_sort_r1(&n, data, cmd);
		else
			cmd = ps_quick_sort_r2(&n, data, cmd);
		while (ps_size_lst(n) > 0)
			cmd = ps_quick_sort_r3(&n, data, cmd);
	}
	while (data->a && ps_get_content(data->a) > data->min)
		cmd = ft_realloc(cmd, ps_add_pb(data));
	cmd = ps_selection_sort_b(data, cmd);
	cmd = ps_pushback_qs(data, cmd);
	return (cmd);
}
