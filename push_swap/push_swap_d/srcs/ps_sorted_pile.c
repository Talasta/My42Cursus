/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorted_pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:02:38 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/07 14:54:33 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_pile_a_sorted(t_list *elem)
{
	int		n;

	if (elem)
	{
		n = ps_get_content(elem);
		while (elem)
		{
			elem = elem->next;
			if (elem)
			{
				if (n > ps_get_content(elem))
					return (1);
				n = ps_get_content(elem);
			}
		}
	}
	return (0);
}

int		ps_pile_b_sorted(t_list *elem)
{
	int		n;

	if (elem)
	{
		n = ps_get_content(elem);
		while (elem)
		{
			elem = elem->next;
			if (elem)
			{
				if (n < ps_get_content(elem))
					return (1);
				n = ps_get_content(elem);
			}
		}
	}
	return (0);
}
