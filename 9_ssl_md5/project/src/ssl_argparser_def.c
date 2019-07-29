/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_argparser_def.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:26:33 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/27 14:28:21 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_argparse	argparser_init(void)
{
	t_argparse	parser;

	parser.hashname = NULL;
	parser.mask = 0;
	parser.len = 0;
	return (parser);
}

void		read_arg(char *arg, t_argparse *parser)
{
	int					i;
	static t_readarg	args[5] = {
		{"p", &read_echo_arg},
		{"q", &read_quiet_arg},
		{"r", &read_rev_arg},
		{"s", &read_str_arg},
		{"", &read_error}
	};

	if (*arg != '-' || parser->mask & SSL_DONE)
	{
		parser->mask |= SSL_DONE;
		return ;
	}
	i = 0;
	while (i < 4)
	{
		if (ft_strcmp(args[i].arg, arg + 1) == 0)
			break ;
		i++;
	}
	args[i].f(parser);
}
