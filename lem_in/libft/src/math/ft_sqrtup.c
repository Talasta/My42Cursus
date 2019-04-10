/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:51:20 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/01/12 17:15:04 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrtup(int nb)
{
	int i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}
