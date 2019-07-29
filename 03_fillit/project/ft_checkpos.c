/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:53:37 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 16:29:01 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkpos(unsigned long *map, unsigned long *tetri, int x, int y)
{
	int				l;
	unsigned long	buf;

	l = 0;
	while (l < 4)
	{
		buf = (map[l + y] | tetri[l] >> x) ^ (tetri[l] >> x);
		if (buf != map[l + y])
			return (0);
		l++;
	}
	return (1);
}
