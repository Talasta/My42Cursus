/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comparemap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:35:11 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 16:29:25 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_comparemap(unsigned long *map1, unsigned long *map2)
{
	size_t	i;

	i = 0;
	while (i < 64)
	{
		if (map1[i] != map2[i])
			return (0);
		i++;
	}
	return (1);
}
