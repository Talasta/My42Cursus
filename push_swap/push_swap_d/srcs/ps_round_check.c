/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_round_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 02:40:06 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/15 12:02:42 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ps_first_round(t_data *data, char *cmd, int mult)
{
	int		size;
	int		med;

	med = ps_getmed(data);
	size = data->size;
	if (size > 30)
	{
		while (size > 0)
		{
			size = data->size - (mult - 1) * 20;
			cmd = ps_first_round_red(data, cmd, mult, size);
			mult++;
		}
	}
	return (cmd);
}

char	*ps_get_next_op1(t_data *data)
{
	if (data->b && data->b->next && ps_chk_sb(data) == 1)
		return ("sb\n");
	if (data->b && data->b->next && ps_chk_rb(data) == 1)
		return ("rb\n");
	if (data->a && data->a->next && ps_chk_sa(data) == 1)
		return ("sa\n");
	if (data->a && data->a->next && ps_chk_rra(data) == 1)
		return ("rra\n");
	if (ps_chk_pb(data) == 1)
		return ("pb\n");
	return ("");
}

char	*ps_get_next_op2(t_data *data)
{
	if (data->a && data->a->next && ps_chk_sa(data) == 1)
		return ("sa\n");
	if (data->a && data->a->next && ps_chk_ra(data) == 1)
		return ("ra\n");
	if (data->b && data->b->next && ps_chk_sb(data) == 1)
		return ("sb\n");
	if (data->b && data->b->next && ps_chk_rrb(data) == 1)
		return ("rrb\n");
	if (ps_chk_pa(data) == 1)
		return ("pa\n");
	return ("");
}

char	*ps_get_next_op3(t_data *data)
{
	if (data->b && data->b->next && ps_get_content(data->b) \
			< ps_get_content(data->b->next))
	{
		if (data->a && data->a->next && ps_get_content(data->a) \
				> ps_get_content(data->a->next))
			return (ps_add_ss(data));
		return (ps_add_sb(data));
	}
	if (data->a && data->a->next && ps_get_content(data->a) \
			> ps_get_content(data->a->next))
		return (ps_add_sa(data));
	return (ps_add_pb(data));
}

char	*ps_get_next_op4(t_data *data)
{
	if (data->a && data->a->next && ps_get_content(data->a) \
			> ps_get_content(data->a->next))
	{
		if (data->b && data->b->next && ps_get_content(data->b) \
				< ps_get_content(data->b->next))
			return (ps_add_ss(data));
		return (ps_add_sa(data));
	}
	if (data->b && data->b->next && ps_get_content(data->b) \
			< ps_get_content(data->b->next))
		return (ps_add_sb(data));
	return (ps_add_pa(data));
}
