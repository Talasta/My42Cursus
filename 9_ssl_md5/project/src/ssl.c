/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:38:43 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/28 13:58:26 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ssl.h"

static void	usage(void)
{
	ft_putendl("usage: ./ft_ssl [hash] [-pqr] [-s string] [files ...]\n");
	ft_putendl("  s : Print a checksum of the given string.");
	ft_putendl("  p : Echo stdin to stdout and append the checksum to stdout.");
	ft_putendl("  q : Quiet mode - only the checksum is printed out.");
	ft_putendl("      (Overrides the -r option)");
	ft_putendl("  r : Reverses the format of the output.");
	ft_putendl("      (Does nothing when combined with the -p options)\n");
	ft_putendl("Standard commands:\n");
	ft_putendl("Message Digest commands:");
	ft_putendl("md5");
	ft_putendl("sha256");
	ft_putendl("sha512");
	ft_putendl("sha384");
	ft_putendl("\nCipher commands:");
}

static int	errorinfo(int err)
{
	if (err == -SSL_ERR1)
		ft_printf("ft_ssl: hash function not available\n");
	else if (err == -SSL_ERR2)
		ft_printf("ft_ssl: invalid option\n");
	usage();
	return (err);
}

int			main(int ac, char *av[])
{
	int		ret;

	if (ac > 1)
	{
		ret = argparser(ac, av);
		if (ret < 0)
			return (errorinfo(ret));
	}
	else
	{
		usage();
	}
	return (0);
}
