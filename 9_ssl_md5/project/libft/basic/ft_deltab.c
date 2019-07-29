/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:38:04 by cmaxime           #+#    #+#             */
/*   Updated: 2019/01/22 12:38:39 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deltab(char **tab)
{
	int		i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
}