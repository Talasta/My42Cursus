/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_piles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:04:20 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/15 13:57:35 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

void	ps_print_pile(t_data data, char *op)
{
	t_list	*elem_a;
	t_list	*elem_b;

	elem_a = data.a;
	elem_b = data.b;
	ft_putstr("\033\143Last operation: ");
	ft_putendl(op);
	ft_putendl("Pile A\t|Pile B");
	while (elem_a || elem_b)
	{
		if (elem_a)
		{
			ft_putnbr(ps_get_content(elem_a));
			elem_a = elem_a->next;
		}
		ft_putstr("\t|");
		if (elem_b)
		{
			ft_putnbr(ps_get_content(elem_b));
			elem_b = elem_b->next;
		}
		ft_putendl("");
	}
}
