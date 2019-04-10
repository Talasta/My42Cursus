/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstupdate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:44:18 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 20:13:04 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_freedata(int **data)
{
	size_t	i;

	if (data)
	{
		i = 0;
		while (i < 4)
		{
			free(data[i]);
			i++;
		}
		free(data);
		data = 0;
	}
}

void			ft_lstconvertbit(t_ulist *elem)
{
	unsigned long	*bit_data;
	int				**data;

	data = elem->content;
	bit_data = ft_tetribit(data);
	ft_freedata(data);
	elem->content = (unsigned long*)bit_data;
}

void			ft_lstupdate(t_ulist *list)
{
	while (list)
	{
		ft_lstconvertbit(list);
		list = list->next;
	}
}
