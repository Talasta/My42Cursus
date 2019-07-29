/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:58:02 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/28 13:59:55 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha2.h"
#include "libft.h"

static void	encode(uint32_t *mem, unsigned char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < 8)
	{
		str[j] = (unsigned char)((mem[i] >> 24) & 0xff);
		str[j + 1] = (unsigned char)((mem[i] >> 16) & 0xff);
		str[j + 2] = (unsigned char)((mem[i] >> 8) & 0xff);
		str[j + 3] = (unsigned char)((mem[i]) & 0xff);
		j += 4;
		i++;
	}
}

void		sha256_print(t_sha256 mem)
{
	unsigned char	str[32];
	uint32_t		input[8];
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
	while (i < 32)
	{
		ft_printf("%02x", str[i]);
		i++;
	}
}
