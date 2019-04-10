/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 08:30:09 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/20 08:30:11 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	**setpos(int **pos, int x, int y)
{
	(*pos)[1] = y;
	(*pos)[0] = x;
	return (pos);
}

int			**ft_upmapsize(int *size, t_ulist *list, unsigned long *map,
		int **pos)
{
	ft_memdel((void**)&map);
	map = ft_newmap(++(*size));
	pos = ft_resetptr(pos, ft_ulsttsize(list) - ft_ulstsize(list));
	return (ft_findmap(size, ft_ulstset_head(list), map, pos));
}

int			**ft_findmap(int *size, t_ulist *list, unsigned long *map,
		int **pos)
{
	int		y;
	int		x;

	y = -1;
	if (!list)
		return (pos);
	while (++y < *size)
	{
		x = -1;
		while (++x < *size)
		{
			if (ft_checkpos(map, list->content, x, y))
			{
				pos = setpos(pos, x, y);
				map = ft_addtetri(map, list->content, x, y);
				if ((ft_findmap(size, list->next, map, pos + 1)))
					return (pos);
				map = ft_mapbackup(map, list->content, x, y);
			}
		}
	}
	if (list != ft_ulstset_head(list))
		return (0);
	return (ft_upmapsize(size, list, map, pos));
}
