/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:06:22 by cmaxime           #+#    #+#             */
/*   Updated: 2018/01/24 21:06:27 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

void	ps_swap_a(t_data *data)
{
	t_list	*buff1;
	t_list	*buff2;

	if (data->a && data->a->next)
	{
		buff1 = data->a;
		buff2 = buff1->next;
		buff1->next = buff2->next;
		buff2->next = buff1;
		data->a = buff2;
	}
}

void	ps_swap_b(t_data *data)
{
	t_list	*buff1;
	t_list	*buff2;

	if (data->b && data->b->next)
	{
		buff1 = data->b;
		buff2 = buff1->next;
		buff1->next = buff2->next;
		buff2->next = buff1;
		data->b = buff2;
	}
}

void	ps_swap_ab(t_data *data)
{
	ps_swap_a(data);
	ps_swap_b(data);
}
