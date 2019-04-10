/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inittracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:13:14 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 21:15:49 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_inittracking(t_ulist *list, int *size)
{
	unsigned long	*map;
	int				**pos;

	if (!(pos = ft_mlcpos(ft_ulstsize(list))))
		return (0);
	*size = ft_sqrtup(ft_ulstsize(list) * 4);
	map = ft_newmap(*size);
	return (ft_findmap(size, list, map, pos));
}
