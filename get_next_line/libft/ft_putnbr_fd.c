/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:06:40 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/14 15:57:06 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		buff;

	n = (long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			n = 147483648;
		}
		else
			n = -1 * n;
	}
	if (n > 9)
	{
		buff = n % 10 + 48;
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(buff, fd);
	}
	else
	{
		buff = n + 48;
		ft_putchar_fd(buff, fd);
	}
}
