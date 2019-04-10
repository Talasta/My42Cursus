/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_low.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:07:46 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/20 10:29:22 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ps_rlow(t_data *data, char *cmd)
{
	while (ps_pile_a_sorted(data->a))
	{
		if (ps_get_content(data->a) > ps_get_content(data->a->next)
				&& ps_get_content(ft_lstlast(data->a)) <= \
				ps_get_content(data->a))
			cmd = ft_realloc(cmd, ps_add_ra(data));
		else if (ps_get_content(data->a) >= ps_get_content(ft_lstlast(data->a))
				&& ps_get_content(ft_lstlast(data->a)) <= \
				ps_get_content(data->a->next))
			cmd = ft_realloc(cmd, ps_add_rra(data));
		else
			cmd = ft_realloc(cmd, ps_add_sa(data));
	}
	return (cmd);
}

char	*ps_low(t_data *data, char *cmd)
{
	while (ps_pile_a_sorted(data->a))
	{
		while (ps_pile_a_sorted(data->a))
			cmd = ft_realloc(cmd, ps_get_next_op1(data));
		while (ps_pile_b_sorted(data->b))
			cmd = ft_realloc(cmd, ps_get_next_op2(data));
		if (data->b)
			cmd = ft_realloc(cmd, ps_add_pa(data));
	}
	cmd = ps_repush_b(data, cmd);
	return (cmd);
}
