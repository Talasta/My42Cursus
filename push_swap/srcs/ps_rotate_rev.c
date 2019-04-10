/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:42:56 by cmaxime           #+#    #+#             */
/*   Updated: 2018/01/24 18:56:36 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

void	ps_rotate_rev_a(t_data *data)
{
	t_list	*buff1;
	t_list	*buff2;

	if (data->a && data->a->next)
	{
		buff2 = data->a;
		buff1 = ft_lstprevlast(data->a);
		data->a = buff1->next;
		buff1->next = NULL;
		data->a->next = buff2;
	}
}

void	ps_rotate_rev_b(t_data *data)
{
	t_list	*buff1;
	t_list	*buff2;

	if (data->b && data->b->next)
	{
		buff2 = data->b;
		buff1 = ft_lstprevlast(data->b);
		data->b = buff1->next;
		buff1->next = NULL;
		data->b->next = buff2;
	}
}

void	ps_rotate_rev_ab(t_data *data)
{
	ps_rotate_rev_a(data);
	ps_rotate_rev_b(data);
}
