/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:11:15 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 16:52:13 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_resetpos(int **pos, size_t size)
{
	int **new;

	ft_memdel((void**)&pos);
	if (!(pos = ft_mlcpos(size)))
		return (0);
	return (pos);
}
