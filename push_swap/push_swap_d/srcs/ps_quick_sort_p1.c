/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_p1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:52:22 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/15 13:44:51 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_check_min(int n, t_list *elem, int min)
{
	while (elem)
	{
		if (ps_get_content(elem) <= n && ps_get_content(elem) >= min)
			return (0);
		elem = elem->next;
	}
	return (1);
}

int		ps_check_max(int n, t_list *elem)
{
	while (elem)
	{
		if (ps_get_content(elem) > n)
			return (0);
		elem = elem->next;
	}
	return (1);
}

int		ps_ismin(int min, t_list *elem)
{
	int		n;

	if (elem)
	{
		n = ps_get_content(elem);
		while (elem)
		{
			if (ps_get_content(elem) < n && ps_get_content(elem) > min)
				return (0);
			elem = elem->next;
		}
	}
	return (1);
}

int		ps_in_lst(int n, t_list *elem)
{
	while (elem)
	{
		if (n == ps_get_content(elem))
			return (1);
		elem = elem->next;
	}
	return (0);
}

int		ps_medval(t_list *elem)
{
	int		max;
	int		min;

	max = ps_get_content(elem);
	min = ps_get_content(elem);
	elem = elem->next;
	while (elem)
	{
		if (max < ps_get_content(elem))
			max = ps_get_content(elem);
		else if (min > ps_get_content(elem))
			min = ps_get_content(elem);
		elem = elem->next;
	}
	return (max - ((max - min) / 2));
}
