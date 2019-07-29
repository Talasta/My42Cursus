/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 11:24:24 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/10 12:11:32 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <unistd.h>

void	m_putchar(char c)
{
	write(1, &c, 1);
}

void	m_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i++])
		;
	write(1, str, i);
}

void	m_putnbase(size_t nbr, size_t base, int pad)
{
	static char	bbase[16] = "0123456789ABCDEF";

	if (base > 16 || base < 1 || pad == 0)
		return ;
	pad--;
	if (nbr >= base && (pad > 0 || pad < 0))
		m_putnbase(nbr / base, base, pad);
	m_putchar(bbase[nbr % base]);
}
