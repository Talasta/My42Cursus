/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isquadra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:32:02 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/17 16:32:26 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_isquadra(char *buf)
{
	int		start;
	int		end;
	int		i;
	char	c;

	start = 0;
	end = 19;
	while (start <= end && (buf[start] == '.' || buf[start] == '\n'))
		start++;
	while (end >= start && (buf[end] == '.' || buf[end] == '\n'))
		end--;
	i = 0;
	while (start <= end)
	{
		c = buf[start];
		if (c != '\n')
			buf[i++] = c;
		start++;
	}
	buf[i] = '\0';
	return (ft_reco(buf));
}
