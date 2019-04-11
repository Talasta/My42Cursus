/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetribit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:52:23 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 16:34:40 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long	*ft_tetribit(int **pos)
{
	size_t			i;
	unsigned long	*tetri;
	unsigned long	buf;

	i = 0;
	buf = 0x8000000000000000;
	tetri = (unsigned long*)ft_memalloc(sizeof(unsigned long) * 4);
	if (!tetri)
		return (tetri);
	while (i < 4)
	{
		tetri[pos[i][1]] = tetri[pos[i][1]] | buf >> pos[i][0];
		i++;
	}
	return (tetri);
}
