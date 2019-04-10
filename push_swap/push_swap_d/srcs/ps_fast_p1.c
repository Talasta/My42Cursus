/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fast_p1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:06:02 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/19 19:33:48 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_size_lst_max(t_list *elem, int max)
{
	int		size;

	size = 0;
	while (elem && ps_get_content(elem) < max)
	{
		size++;
		elem = elem->next;
	}
	return (size);
}

int		ps_getmin(t_list *elem)
{
	int		min;

	min = ps_get_content(elem);
	while (elem)
	{
		if (ps_get_content(elem) < min)
			min = ps_get_content(elem);
		elem = elem->next;
	}
	return (min);
}

int		ps_getmed(t_data *data)
{
	int		min;
	int		max;
	t_list	*elem;

	elem = data->a;
	min = ps_get_content(elem);
	max = min;
	while (elem->next)
	{
		elem = elem->next;
		if (min > ps_get_content(elem))
			min = ps_get_content(elem);
		if (max < ps_get_content(elem))
			max = ps_get_content(elem);
	}
	data->size = max - min;
	data->min = min;
	data->max = max;
	return ((max + min) / 2);
}

char	*ps_first_round_red(t_data *data, char *cmd, int mult, int size)
{
	int		n;
	int		med;

	med = (data->max + data->min) / 2;
	n = 0;
	while (size-- > -1 && n < 20)
	{
		if (ps_get_content(data->a) == data->max)
			cmd = ft_realloc(cmd, ps_add_ra(data));
		if (ps_get_content(data->a) > (med - mult * 10)
				&& ps_get_content(data->a) <= (med + mult * 10 - 1))
		{
			n++;
			cmd = ft_realloc(cmd, ps_add_pb(data));
			if (ps_get_content(data->b) <= med)
				cmd = ft_realloc(cmd, ps_add_rb(data));
		}
		else
			cmd = ft_realloc(cmd, ps_add_ra(data));
	}
	return (cmd);
}

char	*ps_pushback_qs(t_data *data, char *cmd)
{
	while (ps_ismin(data->min, data->a)
			&& data->b == NULL && ps_pile_a_sorted(data->a))
	{
		data->min = ps_get_content(data->a);
		cmd = ft_realloc(cmd, ps_add_ra(data));
	}
	return (cmd);
}
