/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetratl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:30:43 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/17 16:31:06 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_tetratl(int **tetra)
{
	int		l;
	int		x;
	int		y;

	x = 3;
	y = 3;
	l = 0;
	while (l < 4)
	{
		x = tetra[l][0] > x ? x : tetra[l][0];
		y = tetra[l][1] > y ? y : tetra[l][1];
		l++;
	}
	while (--l >= 0)
	{
		tetra[l][0] -= x;
		tetra[l][1] -= y;
	}
	return (tetra);
}
