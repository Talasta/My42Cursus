/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:29:02 by cmaxime           #+#    #+#             */
/*   Updated: 2018/01/24 21:08:57 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

void	ps_rotate_a(t_data *data)
{
	t_list	*buff1;

	if (data->a && data->a->next)
	{
		buff1 = data->a;
		data->a = buff1->next;
		buff1->next = NULL;
		ps_lstpushback(&data->a, buff1);
	}
}

void	ps_rotate_b(t_data *data)
{
	t_list	*buff1;

	if (data->b && data->b->next)
	{
		buff1 = data->b;
		data->b = buff1->next;
		buff1->next = NULL;
		ps_lstpushback(&data->b, buff1);
	}
}

void	ps_rotate_ab(t_data *data)
{
	ps_rotate_a(data);
	ps_rotate_b(data);
}
