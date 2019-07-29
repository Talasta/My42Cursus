/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opadd1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:40:01 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/07 14:55:01 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ps_add_rr(t_data *data)
{
	ps_rotate_ab(data);
	return ("rr\n");
}

char	*ps_add_ra(t_data *data)
{
	ps_rotate_a(data);
	return ("ra\n");
}

char	*ps_add_rb(t_data *data)
{
	ps_rotate_b(data);
	return ("rb\n");
}

char	*ps_add_pb(t_data *data)
{
	ps_push_b(data);
	return ("pb\n");
}

char	*ps_add_pa(t_data *data)
{
	ps_push_a(data);
	return ("pa\n");
}
