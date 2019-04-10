/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:04:28 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/26 17:36:55 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strisdigit(const char *str)
{
	while (*str)
	{
		if (*str == '+' || *str == '-')
			str++;
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}
