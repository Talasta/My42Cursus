/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:28:13 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/17 20:01:14 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_newtetra(char *buf)
{
	int		l;
	int		**tetra;
	int		x;
	char	*new;

	new = ft_strndup(buf, 20);
	if (!ft_testcount(new) || !(ft_isquadra(new)) ||
			!(tetra = (int**)ft_newmatrix(2, 4, sizeof(int))))
		return (0);
	l = 0;
	x = 0;
	while (l < 21)
	{
		if (buf[l] == '#')
		{
			tetra[x][0] = l % 5;
			tetra[x][1] = l / 5;
			x++;
		}
		l++;
	}
	tetra = ft_tetratl(tetra);
	ft_memdel((void**)&new);
	return (tetra);
}
