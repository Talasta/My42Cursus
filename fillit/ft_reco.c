/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reco.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:33:04 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/17 18:53:42 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_undereco(char *str)
{
	int		i;
	char	symbs[9][11];

	ft_strcpy(symbs[1], "#..###");
	ft_strcpy(symbs[2], "#..##..#");
	ft_strcpy(symbs[3], "#..##...#");
	ft_strcpy(symbs[4], "#...###");
	ft_strcpy(symbs[5], "#...##..#");
	ft_strcpy(symbs[6], "#...##...#");
	ft_strcpy(symbs[7], "#...#..##");
	ft_strcpy(symbs[0], "#...#...##");
	ft_strcpy(symbs[8], "#.###");
	i = 0;
	while (i < 9)
	{
		if (ft_strcmp(symbs[i++], str) == 0)
			return (1);
	}
	return (0);
}

int		ft_reco(char *str)
{
	int		i;
	char	symbs[10][14];

	ft_strcpy(symbs[1], "####");
	ft_strcpy(symbs[2], "###.#");
	ft_strcpy(symbs[3], "###..#");
	ft_strcpy(symbs[4], "###...#");
	ft_strcpy(symbs[5], "##.##");
	ft_strcpy(symbs[6], "##..##");
	ft_strcpy(symbs[7], "##..#...#");
	ft_strcpy(symbs[8], "##...##");
	ft_strcpy(symbs[9], "##...#...#");
	ft_strcpy(symbs[0], "#...#...#...#");
	i = 0;
	while (i < 10)
	{
		if (ft_strcmp(symbs[i++], str) == 0)
			return (1);
	}
	return (ft_undereco(str));
}
