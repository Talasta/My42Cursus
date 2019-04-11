/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_p3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:51:44 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/15 12:13:53 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_getmax2_qs(t_list *elem, int max)
{
	int		n;

	n = ps_get_content(elem);
	while (elem)
	{
		if (ps_get_content(elem) > n && ps_get_content(elem) != max)
			n = ps_get_content(elem);
		elem = elem->next;
	}
	return (n);
}

int		ps_getway_qs(t_list *elem, int max)
{
	int		med;
	int		i;

	i = 0;
	med = ps_size_lst(elem) / 2;
	while (elem && ps_get_content(elem) != max)
	{
		elem = elem->next;
		i++;
	}
	if (i < med)
		return (1);
	return (0);
}

char	*ps_selection_sort_b_p1(t_data *data, char *cmd, int max2)
{
	if (ps_get_content(data->b) < ps_get_content(data->b->next))
		cmd = ft_realloc(cmd, ps_add_sb(data));
	if (ps_get_content(data->b) == max2)
		cmd = ft_realloc(cmd, ps_add_pa(data));
	return (cmd);
}

char	*ps_selection_sort_b(t_data *data, char *cmd)
{
	int		max;
	int		max2;
	int		way;

	while (data->b && data->b->next)
	{
		max = ps_getmax_qs(data->b);
		if (data->b->next)
			max2 = ps_getmax2_qs(data->b, max);
		way = ps_getway_qs(data->b, max);
		while (ps_get_content(data->b) != max)
		{
			if (way == 1)
				cmd = ft_realloc(cmd, ps_add_rb(data));
			else
				cmd = ft_realloc(cmd, ps_add_rrb(data));
			cmd = ps_selection_sort_b_p1(data, cmd, max2);
		}
		cmd = ft_realloc(cmd, ps_add_pa(data));
		if (ps_get_content(data->a->next) == max2)
			cmd = ft_realloc(cmd, ps_add_sa(data));
	}
	cmd = ft_realloc(cmd, ps_add_pa(data));
	return (cmd);
}

int		ps_size_lst_qs(t_list *elem, int min)
{
	int		size;

	size = 0;
	while (elem && ps_get_content(elem) > min)
	{
		elem = elem->next;
		size++;
	}
	return (size);
}
