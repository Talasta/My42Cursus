/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bittotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:57:49 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 16:44:09 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_bittotab(unsigned long *tetri)
{
	int				**content;
	unsigned long	buff;
	size_t			i;
	size_t			j;
	int				set;

	if (!(content = (int**)ft_newmatrix(2, 4, sizeof(int))))
		return (NULL);
	i = -1;
	set = 0;
	while (++i < 4)
	{
		j = -1;
		buff = tetri[i];
		while (++j < 4)
		{
			if (buff / ft_powl(2, 64 - j - 1) == 1)
			{
				content[set][0] = j;
				content[set++][1] = i;
			}
			buff = buff % ft_powl(2, 64 - j - 1);
		}
	}
	return (content);
}
