/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_p2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:52:28 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/15 13:46:35 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_medval_a(t_list *elem, int min)
{
	int		max;

	max = ps_get_content(elem);
	elem = elem->next;
	while (elem)
	{
		if (max < ps_get_content(elem))
			max = ps_get_content(elem);
		elem = elem->next;
	}
	return (max - ((max - min) / 2));
}

int		ps_size_lst(t_list *elem)
{
	int		i;

	i = 0;
	while (elem)
	{
		elem = elem->next;
		i++;
	}
	return (i);
}

void	ps_lstaddfront(t_list **n, int val)
{
	t_list	*current;
	t_list	*new;
	int		i;

	i = val;
	current = *n;
	new = ft_lstnew(&i, sizeof(int));
	new->next = current;
	*n = new;
}

void	ps_lstdelfront(t_list **n)
{
	t_list	*current;
	t_list	*todel;

	if (*n)
	{
		todel = *n;
		current = todel->next;
		free(todel->content);
		free(todel);
		*n = current;
	}
}

int		ps_getmax_qs(t_list *elem)
{
	int		n;

	n = ps_get_content(elem);
	while (elem)
	{
		if (ps_get_content(elem) > n)
			n = ps_get_content(elem);
		elem = elem->next;
	}
	return (n);
}
