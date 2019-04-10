/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:13:07 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 19:37:57 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long	*ft_addtetri(unsigned long *map, unsigned long *tetri, \
		int x, int y)
{
	size_t			i;

	i = 0;
	while (i < 4)
	{
		map[y + i] = map[y + i] | tetri[i] >> x;
		i++;
	}
	return (map);
}
