/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fetch_pile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:41:59 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/19 19:37:16 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

void	ps_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		ps_check_opt(char **tab, t_data *data, char **av)
{
	if (ft_strcmp("-v1", av[0]) == 0
				|| ft_strcmp("-v2", av[0]) == 0
				|| ft_strcmp("-v3", av[0]) == 0)
	{
		data->status = av[0][2] - '0';
		ps_free_tab(tab);
		return (0);
	}
	ps_free_tab(tab);
	return (-1);
}

char	**ps_split_av(char **av)
{
	char	**buff;
	char	**ret;
	int		i;

	ret = (char**)ft_memalloc(sizeof(char*));
	ret[0] = 0;
	i = 0;
	while (av[i])
	{
		buff = ft_strsplit(av[i], ' ');
		ret = ft_realloc_strtab(ret, buff);
		free(buff);
		i++;
	}
	return (ret);
}

int		ps_fetch_pile(char **av, t_data *data)
{
	int		i;
	int		num;
	int		ret;
	t_list	*elem;
	char	**tab;

	i = 1;
	ret = 1;
	data->status = 0;
	tab = ps_split_av(av);
	while (ret != -1 && tab[i])
	{
		if (ft_strncmp(tab[i], "-v", 2) == 0
				|| ft_strisdigit(tab[i]) == 0 || ps_isint(tab[i], &num) == 0)
			return (ps_check_opt(tab, data, tab + i));
		elem = ft_lstnew(&num, sizeof(int));
		if (data->a == NULL)
			data->a = elem;
		else
			ret = ps_lstpushback(&data->a, elem);
		i++;
	}
	ps_free_tab(tab);
	return (ret);
}
