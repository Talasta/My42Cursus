/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:01:29 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 13:08:53 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_powl(int nb, int power)
{
	long	result;

	result = 1;
	if (power == 0)
		return (result);
	while (power--)
		result = result * nb;
	return (result);
}
