/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:20:30 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/16 11:34:46 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *s1, char const *s2)
{
	size_t	size;
	char	*new;

	if (s1)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		new = ft_strnew(size);
		ft_memcpy(new, s1, ft_strlen(s1));
		ft_strncat(new, s2, size);
		ft_strdel(&s1);
		return (new);
	}
	else
	{
		if (s2)
			return (strdup(s2));
	}
	return (NULL);
}
