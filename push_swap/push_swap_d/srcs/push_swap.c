/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:18:20 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/15 16:42:24 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_usage_p(t_data *data)
{
	ft_putendl("\nUsage: ./push_swap [num1 num2 ...] -v[v_arg]\n");
	ft_putendl("- [num] : Has to be integer and only different numbers\n");
	ft_putendl("- [v_arg] NULL : quick-sort");
	ft_putendl("-            1 : radix-sort");
	ft_putendl("             2 : shell-sort");
	ps_destroy_data(data);
	return (-1);
}

int		main(int ac, char **av)
{
	t_data	data;
	int		ret;
	char	*cmd;

	data = ps_init_data();
	ret = 1;
	if (ac <= 1)
		return (ps_usage_p(&data));
	else
		ret = ps_fetch_pile(av, &data);
	if (ret != -1 && data.a != NULL && data.status > -1 && data.status < 3)
	{
		cmd = ps_op_find(&data);
		ft_putstr(cmd);
		free(cmd);
	}
	else
		return (ps_usage_p(&data));
	ps_destroy_data(&data);
	return (0);
}
