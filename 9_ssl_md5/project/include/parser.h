/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:27:02 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/28 09:09:09 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define SSL_ECHO 0x1
# define SSL_QUIET 0x2
# define SSL_REV 0x4
# define SSL_STR 0x8
# define SSL_DONE 0x10
# define SSL_STRB 0x20
# define SSL_ERR 0x80

# include <stddef.h>
# include <stdint.h>

typedef struct	s_argparse
{
	char	*hashname;
	void	(*hash)(uint8_t*, size_t);
	char	*arg;
	size_t	len;
	uint8_t	mask;
	char	pad[7];
}				t_argparse;

typedef struct	s_readarg
{
	char	*arg;
	void	(*f)(t_argparse*);
}				t_readarg;

typedef struct	s_hash
{
	char	*name;
	void	(*function)(uint8_t*, size_t);
}				t_hash;

int				argparser(int ac, char *av[]);

t_argparse		argparser_init(void);
t_argparse		load_hash(char *hashfunc, t_argparse parser);
void			read_arg(char *arg, t_argparse *parser);

void			read_echo_arg(t_argparse *parser);
void			read_quiet_arg(t_argparse *parser);
void			read_rev_arg(t_argparse *parser);
void			read_str_arg(t_argparse *parser);
void			read_error(t_argparse *parser);

#endif
