/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:37:59 by cmaxime           #+#    #+#             */
/*   Updated: 2018/01/29 17:38:00 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_chk_rra(t_data *data)
{
	if (ps_get_content(data->a) > ps_get_content(ft_lstlast(data->a))
			&& (ps_get_content(data->a->next) >
			ps_get_content(ft_lstlast(data->a))
			|| data->a->next == ft_lstlast(data->a)))
	{
		ps_rotate_rev_a(data);
		return (1);
	}
	return (0);
}

int		ps_chk_rrb(t_data *data)
{
	if (ps_get_content(data->b) < ps_get_content(ft_lstlast(data->b))
			&& (ps_get_content(data->b->next) <
			ps_get_content(ft_lstlast(data->b))
			|| data->b->next == ft_lstlast(data->b)))
	{
		ps_rotate_rev_b(data);
		return (1);
	}
	return (0);
}

int		ps_chk_sa(t_data *data)
{
	if (ps_get_content(data->a) > ps_get_content(data->a->next)
			&& (ps_get_content(data->a->next) <
			ps_get_content(ft_lstlast(data->a))
			|| data->a->next == ft_lstlast(data->a)))
	{
		ps_swap_a(data);
		return (1);
	}
	return (0);
}

int		ps_chk_sb(t_data *data)
{
	if (ps_get_content(data->b) < ps_get_content(data->b->next)
			&& (ps_get_content(data->b->next) >
			ps_get_content(ft_lstlast(data->b)) ||
			data->b->next == ft_lstlast(data->b)))
	{
		ps_swap_b(data);
		return (1);
	}
	return (0);
}

int		ps_chk_pb(t_data *data)
{
	if (ps_get_content(data->a) < ps_get_content(data->a->next)
			&& ps_get_content(data->a) <
			ps_get_content(ft_lstlast(data->a)))
	{
		ps_push_b(data);
		return (1);
	}
	return (0);
}
