/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_argparser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:25:54 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/28 09:08:31 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "ssl.h"
#include "parser.h"

static char		*readfile(char *file, size_t *size)
{
	int		fd;
	char	buff[512];
	char	*str;
	int		ret;

	str = (char*)ft_memalloc(sizeof(char));
	if (!file)
		fd = 0;
	else if ((fd = open(file, O_RDONLY)) < 0)
	{
		free(str);
		return (NULL);
	}
	while ((ret = (int)read(fd, buff, 512)) > 0)
	{
		str = ft_realloc_mem(str, buff, *size, (size_t)ret);
		*size += (size_t)ret;
	}
	return (str);
}

static void		processhash(char *arg, size_t size, t_argparse *parser)
{
	char		c[2];
	char		*str;

	c[0] = parser->mask & SSL_STR ? '\"' : '\0';
	c[1] = '\0';
	if ((parser->mask & SSL_DONE || parser->mask & SSL_STR)
			&& !(parser->mask & SSL_QUIET) && !(parser->mask & SSL_REV))
	{
		str = ft_stoupper(ft_strdup(parser->hashname));
		ft_printf("%s (%s%s%s) = ", str, c, parser->arg, c);
		free(str);
	}
	parser->hash((uint8_t*)arg, size);
	if (parser->mask & SSL_REV
			&& (parser->mask & SSL_DONE || parser->mask & SSL_STR))
		ft_printf(" %s%s%s", c, parser->arg, c);
	ft_putchar('\n');
}

static int		hashfile(char *file, t_argparse *parser)
{
	char	*str;
	size_t	size;

	size = 0;
	if (!(str = readfile(file, &size)))
	{
		ft_printf("ft_ssl: %s: %s: no such file or directory\n",
				parser->hashname, file);
		return (0);
	}
	if (!file && parser->mask & SSL_ECHO)
		write(1, str, size);
	processhash(str, size, parser);
	free(str);
	if (!(parser->mask & SSL_ECHO))
		parser->mask |= SSL_DONE;
	parser->mask |= SSL_STRB;
	parser->mask &= 0x36;
	return (1);
}

static int		evaluate_arg(char *av[], int ac, int *i, t_argparse *parser)
{
	parser->arg = av[*i];
	if (*av[*i] != '-' || parser->mask & SSL_DONE)
		hashfile(av[*i], parser);
	if (SSL_ECHO & parser->mask)
		hashfile(NULL, parser);
	if (SSL_STR & parser->mask && ++(*i) < ac)
	{
		parser->mask |= SSL_STRB;
		parser->arg = av[*i];
		processhash(av[*i], ft_strlen(av[*i]), parser);
		parser->mask &= 0x36;
	}
	return (1);
}

int				argparser(int ac, char *av[])
{
	t_argparse	parser;
	int			i;

	parser = argparser_init();
	parser = load_hash(av[1], parser);
	if (!parser.hash)
		return (-SSL_ERR1);
	i = 1;
	while (++i < ac)
	{
		read_arg(av[i], &parser);
		if (parser.mask & SSL_ERR)
			return (-SSL_ERR2);
		if (!(evaluate_arg(av, ac, &i, &parser)))
			return (-SSL_ERR3);
	}
	if (!(parser.mask & SSL_DONE) && !(parser.mask & SSL_STRB))
		hashfile(NULL, &parser);
	return (0);
}
