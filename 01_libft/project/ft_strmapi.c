/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:17:56 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/13 17:10:20 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	size_t	i;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	new = ft_strnew(size);
	if (!new)
		return (new);
	while (i < size)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}
