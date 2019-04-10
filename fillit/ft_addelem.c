/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addelem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:22:16 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/17 20:13:42 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_addelem(char **tab, int **offset, t_ulist *list)
{
	size_t	i;
	size_t	j;
	int		**content;

	j = 0;
	while (list)
	{
		content = ft_bittotab(list->content);
		i = 0;
		while (i < 4)
		{
			tab[(*offset)[1] + content[i][1]][(*offset)[0]
				+ content[i][0]] = 'A' + j;
			i++;
		}
		offset++;
		list = list->next;
		j++;
	}
	return (tab);
}
