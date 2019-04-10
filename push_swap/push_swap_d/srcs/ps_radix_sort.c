/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:13:38 by cmaxime           #+#    #+#             */
/*   Updated: 2018/01/30 17:46:38 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_linearise_data(t_data *data)
{
	t_list			*elem;
	unsigned int	val;
	int				*ptr;

	ps_getmed(data);
	elem = data->a;
	while (elem)
	{
		val = (unsigned int)(ps_get_content(elem) - data->min);
		ptr = elem->content;
		*ptr = val;
		elem = elem->next;
	}
}

int		ps_getbase_2_inc(unsigned int size)
{
	int		i;

	i = 0;
	while (size > 0)
	{
		size = size / 2;
		i++;
	}
	return (i);
}

int		ps_pow(int inc)
{
	int		n;

	n = 2;
	if (inc <= 0)
		return (1);
	while (--inc > 0)
	{
		n *= 2;
	}
	return (n);
}

char	*ps_radix_sort(t_data *data, char *cmd)
{
	int		inc;
	int		size;
	int		i;

	i = 1;
	ps_linearise_data(data);
	ps_getmed(data);
	inc = ps_getbase_2_inc(data->size);
	while (inc > 0)
	{
		size = data->size;
		while (size-- > -1)
		{
			if ((ps_get_content(data->a) % ps_pow(i)) / ps_pow(i - 1) == 0)
				cmd = ft_realloc(cmd, ps_add_pb(data));
			else
				cmd = ft_realloc(cmd, ps_add_ra(data));
		}
		while (data->b)
			cmd = ft_realloc(cmd, ps_add_pa(data));
		inc--;
		i++;
	}
	return (cmd);
}
