/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:18:11 by cmaxime           #+#    #+#             */
/*   Updated: 2018/01/29 18:04:34 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

void	ps_push_b(t_data *data)
{
	t_list	*buff1;
	t_list	*buff2;

	if (data->a)
	{
		buff1 = data->a;
		data->a = buff1->next;
		buff2 = data->b;
		data->b = buff1;
		buff1->next = buff2;
	}
}

void	ps_push_a(t_data *data)
{
	t_list	*buff1;
	t_list	*buff2;

	if (data->b)
	{
		buff1 = data->b;
		data->b = buff1->next;
		buff2 = data->a;
		data->a = buff1;
		buff1->next = buff2;
	}
}
