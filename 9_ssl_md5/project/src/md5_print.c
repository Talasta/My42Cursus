/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:13:09 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/27 13:32:05 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"
#include "libft.h"

static void	encode(uint32_t *mem, unsigned char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		str[j] = (unsigned char)(mem[i] & 0xff);
		str[j + 1] = (unsigned char)((mem[i] >> 8) & 0xff);
		str[j + 2] = (unsigned char)((mem[i] >> 16) & 0xff);
		str[j + 3] = (unsigned char)((mem[i] >> 24) & 0xff);
		j += 4;
		i++;
	}
}

void		md5_print(t_md5 mem)
{
	unsigned char	str[16];
	uint32_t		input[4];
	size_t			i;

	input[0] = mem.a;
	input[1] = mem.b;
	input[2] = mem.c;
	input[3] = mem.d;
	encode(input, str);
	i = 0;
	while (i < 16)
	{
		ft_printf("%02x", str[i]);
		i++;
	}
}
