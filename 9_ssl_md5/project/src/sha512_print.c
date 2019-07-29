/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:58:02 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/28 13:59:55 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha2.h"
#include "libft.h"

static void	encode(uint64_t *mem, unsigned char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < 8)
	{
		str[j] = (unsigned char)((mem[i] >> 56) & 0xff);
		str[j + 1] = (unsigned char)((mem[i] >> 48) & 0xff);
		str[j + 2] = (unsigned char)((mem[i] >> 40) & 0xff);
		str[j + 3] = (unsigned char)((mem[i] >> 32) & 0xff);
		str[j + 4] = (unsigned char)((mem[i] >> 24) & 0xff);
		str[j + 5] = (unsigned char)((mem[i] >> 16) & 0xff);
		str[j + 6] = (unsigned char)((mem[i] >> 8) & 0xff);
		str[j + 7] = (unsigned char)((mem[i]) & 0xff);
		j += 8;
		i++;
	}
}

void		sha512_print(t_sha512 mem)
{
	unsigned char	str[64];
	uint64_t		input[8];
	size_t			i;

	input[0] = mem.a;
	input[1] = mem.b;
	input[2] = mem.c;
	input[3] = mem.d;
	input[4] = mem.e;
	input[5] = mem.f;
	input[6] = mem.g;
	input[7] = mem.h;
	encode(input, str);
	i = 0;
	while (i < 64)
	{
		ft_printf("%02x", str[i]);
		i++;
	}
}

void		sha384_print(t_sha512 mem)
{
	unsigned char	str[64];
	uint64_t		input[8];
	size_t			i;

	input[0] = mem.a;
	input[1] = mem.b;
	input[2] = mem.c;
	input[3] = mem.d;
	input[4] = mem.e;
	input[5] = mem.f;
	input[6] = mem.g;
	input[7] = mem.h;
	encode(input, str);
	i = 0;
	while (i < 48)
	{
		ft_printf("%02x", str[i]);
		i++;
	}
}
