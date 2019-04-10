/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:36:23 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 17:02:47 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	**ft_newmatrix(size_t x, size_t y, size_t size)
{
	unsigned char	**tab;

	if (!(tab = (unsigned char**)ft_memalloc(sizeof(unsigned char*) * y)))
		return (NULL);
	while ((int)y >= 0)
	{
		y--;
		if (!(tab[y] = (unsigned char*)ft_memalloc(size * x)))
			return (NULL);
	}
	return ((void**)tab);
}
