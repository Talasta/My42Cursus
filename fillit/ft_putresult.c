/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putresult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:38:46 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/17 20:16:34 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_putresult(t_ulist *list, int **pos, int size)
{
	char	**tab;

	if (!(tab = (char**)ft_newmatrix(size, size, sizeof(char))))
		return (0);
	tab = ft_addelem(tab, pos, list);
	ft_puttab(tab, size);
	ft_memdel((void**)tab);
	return (1);
}
