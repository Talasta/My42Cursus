/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:44:49 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/15 19:04:46 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_check_sort(t_data data)
{
	int		n;
	t_list	*cur;

	if (data.b)
		ft_putendl("KO");
	else
	{
		cur = data.a;
		n = ps_get_content(cur);
		while (cur && cur->next)
		{
			cur = cur->next;
			if (n > ps_get_content(cur))
			{
				ft_putendl("KO");
				exit(3);
			}
			n = ps_get_content(cur);
		}
		ft_putendl("OK");
	}
}

int		ps_error(void)
{
	ft_putendl("Error");
	return (-1);
}

int		ps_usage(int mode)
{
	if (mode == 1)
		ft_putendl("Error");
	ft_putendl("\nUsage: ./checker [num1 num2 ...] -v[v_arg]\n");
	ft_putendl("- [num] : Has to be integer and only different numbers\n");
	ft_putendl("- [v_arg] 1 : shell-viewer");
	ft_putendl("          2 : graphic-viewer");
	return (-1);
}

int		main(int ac, char **av)
{
	t_data	data;
	int		ret;

	data = ps_init_data();
	ret = 1;
	if (ac <= 1)
		return (ps_usage(0));
	else
		ret = ps_fetch_pile(av, &data);
	if (ret != -1 && data.a != NULL && data.status > -1 && data.status < 3)
	{
		if (data.status == 2)
			ret = ps_opexe_view(&data);
		else
			ret = ps_opexe(&data);
	}
	else
		ps_usage(1);
	if (ret != -1 && data.a != NULL)
		ps_check_sort(data);
	ps_destroy_data(&data);
	return (0);
}
