/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversemap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:38:28 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/16 11:43:06 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long	*ft_reversemap(unsigned long *new, unsigned long *blank)
{
	size_t	i;

	i = 0;
	while (i < 64)
	{
		new[i] = new[i] ^ blank[i];
		i++;
	}
	return (new);
}
