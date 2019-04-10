/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:07:18 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/17 21:23:06 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_readfile(char *filename, t_ulist **list)
{
	char	*buf;
	int		f;
	t_ulist	*new;
	int		**tetra;

	if ((f = open(filename, O_RDONLY)) == -1 || \
			!(buf = (char*)ft_memalloc(22)))
		return (0);
	while (read(f, buf, 20))
	{
		if (!(tetra = ft_newtetra(buf)) || \
				!(new = ft_ulstnew(tetra, 30)))
			return (0);
		ft_bzero(buf, 20);
		ft_ulstadd_tail(list, new);
		if (read(f, buf, 1))
		{
			if (buf[0] != '\n')
				return (0);
		}
	}
	if (!ft_strcmp(buf, "\n"))
		return (0);
	ft_memdel((void**)&buf);
	return (*list != 0 && ft_ulstsize(*list) <= 26);
}

int		ft_testcount(char *buf)
{
	return (ft_strccount(buf, '.') == 12 &&\
		ft_strccount(buf, '#') == 4 &&\
			ft_strccount(buf, '\n') == 4);
}
