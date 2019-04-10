/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:38:50 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/15 16:36:38 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

int		ps_isint(char *str, int *n)
{
	intmax_t	nb;

	nb = ft_atointmax(str);
	if (nb <= INT_MAX && nb >= INT_MIN)
		*n = (int)nb;
	else
		return (0);
	return (1);
}
