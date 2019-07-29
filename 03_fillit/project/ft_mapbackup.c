/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapbackup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:34:50 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/17 18:14:18 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long	*ft_mapbackup(unsigned long *map, unsigned long *tetri, \
		int x, int y)
{
	int		l;

	l = 0;
	while (l < 4)
	{
		map[l + y] = map[l + y] ^ (tetri[l] >> x);
		l++;
	}
	return (map);
}
