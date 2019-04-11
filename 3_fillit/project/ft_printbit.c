/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:52:27 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 17:02:00 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_printbit(unsigned long oct)
{
	size_t	i;
	size_t	nb;

	i = 0;
	while (i < 64)
	{
		nb = oct / ft_powl(2, 64 - i - 1);
		oct = oct % ft_powl(2, 64 - i - 1);
		ft_putchar(nb + 48);
		i++;
	}
}
