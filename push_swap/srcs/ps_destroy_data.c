/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_destroy_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:03:29 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/19 17:35:10 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

void	ps_destroy_list(t_list *elem)
{
	t_list	*cur;

	cur = elem;
	while (cur)
	{
		elem = cur;
		cur = cur->next;
		ps_free_elem(elem);
	}
}

void	ps_destroy_data(t_data *data)
{
	t_list	*elem;
	t_list	*cur;

	while (data->b)
		ps_push_a(data);
	cur = data->a;
	while (cur)
	{
		elem = cur;
		cur = cur->next;
		ps_free_elem(elem);
	}
}

t_data	ps_init_data(void)
{
	t_data	data;

	data.a = NULL;
	data.b = NULL;
	data.error = 0;
	data.status = 0;
	return (data);
}

int		ps_get_content(t_list *elem)
{
	int		*n;

	n = elem->content;
	return (*n);
}
