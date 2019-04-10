/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opadd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:24:00 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/09 18:53:36 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ps_add_rrb(t_data *data)
{
	ps_rotate_rev_b(data);
	return ("rrb\n");
}

char	*ps_add_rra(t_data *data)
{
	ps_rotate_rev_a(data);
	return ("rra\n");
}

char	*ps_add_sa(t_data *data)
{
	ps_swap_a(data);
	return ("sa\n");
}

char	*ps_add_sb(t_data *data)
{
	ps_swap_b(data);
	return ("sb\n");
}

char	*ps_add_ss(t_data *data)
{
	ps_swap_ab(data);
	return ("ss\n");
}
