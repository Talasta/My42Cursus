/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:44:31 by cmaxime           #+#    #+#             */
/*   Updated: 2018/01/24 18:55:25 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

t_list	*ft_lstlast(t_list *elem)
{
	t_list	*current;

	current = elem;
	if (current)
	{
		while (current->next)
			current = current->next;
		return (current);
	}
	return (NULL);
}

t_list	*ft_lstprevlast(t_list *elem)
{
	t_list	*current;

	current = elem;
	if (current && current->next)
	{
		while (current->next->next)
			current = current->next;
		return (current);
	}
	return (NULL);
}
