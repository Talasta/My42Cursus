/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:55:35 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 17:03:21 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

unsigned long	*ft_newmap(size_t size)
{
	unsigned long	*map;
	size_t			i;
	unsigned long	min_long;
	unsigned long	max_long;

	map = ft_memalloc(sizeof(unsigned long) * 64);
	if (!map || size == 64)
		return (map);
	i = 0;
	min_long = 0x0000000000000000;
	max_long = 0xFFFFFFFFFFFFFFFF;
	while (i <= 64)
	{
		if (i < size)
			map[i] = ((min_long << size) | max_long) >> size;
		else
			map[i] = max_long;
		i++;
	}
	return (map);
}
