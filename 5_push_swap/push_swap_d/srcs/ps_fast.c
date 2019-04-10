/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:03:21 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/19 19:34:40 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ps_swap_less(char *cmd, t_data *data, int less, t_list *n)
{
	int		e;

	e = 0;
	if (n && n->next)
		e = ps_get_content(n) - ps_get_content(n->next);
	if (ps_size_lst_max(data->a, data->max) \
			< less && ps_size_lst(data->a) > 1 && e > -12 && e < 12)
	{
		if (data->b && data->b->next && ps_get_content(data->b) \
				< ps_get_content(data->b->next))
			cmd = ft_realloc(cmd, ps_add_sb(data));
		if (data->a && data->a->next && ps_get_content(data->a) > \
				ps_get_content(data->a->next))
			cmd = ft_realloc(cmd, ps_add_sa(data));
	}
	return (cmd);
}

char	*ps_test_r1(t_list **n, t_data *data, char *cmd)
{
	ps_lstaddfront(n, (data->max - ps_getmin(data->a)) / 2 \
			+ ps_getmin(data->a));
	while (ps_check_min(ps_get_content(*n), data->a, data->min) == 0)
	{
		cmd = ps_swap_less(cmd, data, 8, *n);
		if (ps_get_content(data->a) <= ps_get_content(*n))
			cmd = ft_realloc(cmd, ps_add_pb(data));
		else
			cmd = ft_realloc(cmd, ps_add_ra(data));
		cmd = ps_swap_less(cmd, data, 8, *n);
	}
	while (data->size != data->max - data->min - 1
			&& ps_get_content(ft_lstlast(data->a)) < data->max)
		cmd = ft_realloc(cmd, ps_add_rra(data));
	return (cmd);
}

char	*ps_test_r2(t_list **n, t_data *data, char *cmd)
{
	int		save;

	if (*n && ps_getmax_qs(data->b) - ps_get_content(*n) > 2)
	{
		save = ps_get_content(*n);
		ps_lstaddfront(n, (ps_getmax_qs(data->b) - save) / 2 + save);
		while (*n && ps_check_max(ps_get_content(*n), data->b) == 0)
		{
			cmd = ps_swap_less(cmd, data, 8, *n);
			if (ps_get_content(data->b) > ps_get_content(*n))
				cmd = ft_realloc(cmd, ps_add_pa(data));
			else
				cmd = ft_realloc(cmd, ps_add_rb(data));
			cmd = ps_swap_less(cmd, data, 8, *n);
		}
		while (n && ps_get_content(ft_lstlast(data->b)) >= save)
			cmd = ft_realloc(cmd, ps_add_rrb(data));
	}
	return (cmd);
}

char	*ps_test_r3(t_list **n, t_data *data, char *cmd)
{
	if (*n == NULL)
	{
		ps_lstaddfront(n, ps_medval(data->b));
		while (ps_check_max(ps_get_content(*n), data->b) == 0)
		{
			if (ps_get_content(data->b) > ps_get_content(*n))
				cmd = ft_realloc(cmd, ps_add_pa(data));
			else
				cmd = ft_realloc(cmd, ps_add_rb(data));
		}
	}
	return (cmd);
}

char	*ps_test(t_data *data, char *cmd)
{
	t_list	*n;

	n = NULL;
	ps_getmed(data);
	data->max++;
	ps_lstaddfront(&n, (data->max - ps_getmin(data->a)) / 2 \
			+ ps_getmin(data->a));
	while (ps_size_lst(data->b) > 2 || data->b == NULL)
	{
		while (ps_pile_a_sorted(data->a))
			cmd = ps_test_r1(&n, data, cmd);
		if (data->a)
			data->max = ps_get_content(data->a);
		ps_lstdelfront(&n);
		cmd = ps_test_r2(&n, data, cmd);
		cmd = ps_test_r3(&n, data, cmd);
	}
	while (data->b)
		cmd = ft_realloc(cmd, ps_add_pa(data));
	if (ps_get_content(data->a) > ps_get_content(data->a->next))
		cmd = ft_realloc(cmd, ps_add_sa(data));
	ps_destroy_list(n);
	return (cmd);
}
