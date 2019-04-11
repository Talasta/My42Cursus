/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_strtab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:49:40 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/15 12:50:31 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

int		ft_tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**ft_realloc_strtab(char **dst, char **src)
{
	char	**new;
	int		i;
	int		j;
	int		size;

	size = ft_tablen(dst) + ft_tablen(src) + 1;
	i = 0;
	new = (char**)ft_memalloc(sizeof(char*) * size);
	while (dst[i])
	{
		new[i] = dst[i];
		i++;
	}
	j = 0;
	while (src[j])
	{
		new[i + j] = src[j];
		j++;
	}
	new[i + j] = 0;
	free(dst);
	return (new);
}
