/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:00:35 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/17 17:00:37 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_putusage(void)
{
	write(1, "usage: ./fillit filename\n", 25);
	return (0);
}

int		ft_puterror(void)
{
	write(1, "error\n", 6);
	return (0);
}
