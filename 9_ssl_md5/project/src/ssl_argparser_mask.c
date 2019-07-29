/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_argparser_mask.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:26:38 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/27 14:26:39 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	read_echo_arg(t_argparse *parser)
{
	parser->mask |= SSL_ECHO;
}

void	read_quiet_arg(t_argparse *parser)
{
	parser->mask &= ~SSL_REV;
	parser->mask |= SSL_QUIET;
}

void	read_rev_arg(t_argparse *parser)
{
	if (parser->mask & SSL_QUIET)
		return ;
	parser->mask |= SSL_REV;
}

void	read_str_arg(t_argparse *parser)
{
	parser->mask |= SSL_STR;
}

void	read_error(t_argparse *parser)
{
	parser->mask |= SSL_ERR;
}
