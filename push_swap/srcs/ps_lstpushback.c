/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:36:57 by cmaxime           #+#    #+#             */
/*   Updated: 2018/01/29 18:04:06 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

void	ps_free_elem(t_list *elem)
{
	free(elem->content);
	elem->content = NULL;
	free(elem);
	elem = NULL;
}

int		ps_lsterror(t_list *elem)
{
	ps_free_elem(elem);
	return (-1);
}

int		ps_lstpushback(t_list **alst, t_list *new)
{
	t_list	*current;
	int		*nb1;
	int		*nb2;

	nb1 = new->content;
	if (alst)
	{
		current = *alst;
		while (current->next != NULL)
		{
			nb2 = current->content;
			if (*nb1 == *nb2)
				return (ps_lsterror(new));
			current = current->next;
		}
		nb2 = current->content;
		if (*nb1 == *nb2)
			return (ps_lsterror(new));
		current->next = new;
	}
	return (1);
}

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list	*current;

	if (*alst)
	{
		current = *alst;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
	}
}
