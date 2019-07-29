/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:37:25 by cmaxime           #+#    #+#             */
/*   Updated: 2018/01/29 17:37:29 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_chk_pa(t_data *data)
{
	if (data->b->next == NULL
			|| (ps_get_content(data->b) > ps_get_content(data->b->next)
			&& ps_get_content(data->b) >
			ps_get_content(ft_lstlast(data->b))))
	{
		ps_push_a(data);
		return (1);
	}
	return (0);
}

int		ps_chk_rb(t_data *data)
{
	if (ps_get_content(data->b) < ps_get_content(ft_lstlast(data->b))
			&& ps_get_content(data->b) < ps_get_content(data->b->next))
	{
		ps_rotate_b(data);
		return (1);
	}
	return (0);
}

int		ps_chk_ra(t_data *data)
{
	if (ps_get_content(data->a) > ps_get_content(ft_lstlast(data->a))
			&& ps_get_content(data->a) > ps_get_content(data->a->next))
	{
		ps_rotate_b(data);
		return (1);
	}
	return (0);
}
