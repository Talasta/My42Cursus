/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:21:56 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 21:18:24 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_ulist	*list;
	int		**pos;
	int		*size;
	void	*f;

	list = 0;
	if (ac != 2)
		return (ft_putusage());
	if (!(ft_readfile(av[1], &list)))
		return (ft_puterror());
	ft_lstupdate(list);
	if (!(size = (int*)ft_memalloc(sizeof(int))))
		return (ft_puterror());
	if (!(pos = ft_inittracking(list, size)))
		return (ft_puterror());
	ft_putresult(list, pos, *size);
	f = ft_tetridel;
	ft_ulstdel(&list, f);
	return (0);
}
