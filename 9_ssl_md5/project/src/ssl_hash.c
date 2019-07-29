/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:26:44 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/27 14:26:46 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "ssl.h"

t_argparse	load_hash(char *hashfunc, t_argparse parser)
{
	size_t			i;
	static t_hash	hashlist[5] = {
		{"md5", &md5},
		{"sha256", &sha256},
		{"sha512", &sha512},
		{"sha384", &sha384},
		{"", NULL}
	};

	i = 0;
	while (i < 4)
	{
		if (ft_strcmp(hashfunc, hashlist[i].name) == 0)
			break ;
		i++;
	}
	parser.hash = hashlist[i].function;
	parser.hashname = hashlist[i].name;
	return (parser);
}
