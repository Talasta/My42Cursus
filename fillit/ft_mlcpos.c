/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlcpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:08:36 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 18:13:29 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_mlcpos(size_t size)
{
	int		**pos;
	size_t	l;

	l = 0;
	if (!(pos = (int**)ft_memalloc(sizeof(int*) * size)))
		return (0);
	while (l < size)
	{
		if (!(pos[l] = (int*)ft_memalloc(sizeof(int) * 2)))
			return (0);
		l++;
	}
	return (pos);
}
