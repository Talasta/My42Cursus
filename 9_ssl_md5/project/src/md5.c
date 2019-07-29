/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:12:17 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/20 14:17:22 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"
#include "libft.h"

static t_md5	init(void)
{
	t_md5	mem;

	mem.a = 0x67452301;
	mem.b = 0xefcdab89;
	mem.c = 0x98badcfe;
	mem.d = 0x10325476;
	return (mem);
}

static uint8_t	*preprocess(uint8_t *str, size_t len)
{
	uint8_t	*msg;
	size_t	orig;

	orig = len * 8;
	msg = (uint8_t*)ft_memalloc((len + 128) * sizeof(uint8_t));
	msg = ft_memcpy(msg, str, len);
	msg[len++] = 0x80;
	while (len % 64 != 56)
	{
		msg[len] = 0x00;
		len++;
	}
	while (len % 64)
	{
		msg[len] = (orig >> (8 * (len % 64 - 56))) & 0xff;
		len++;
	}
	return (msg);
}

static uint8_t	*getnextpart(uint32_t *x, uint8_t *msg)
{
	size_t	i;

	i = 0;
	while (i < 16)
	{
		x[i] = ((uint32_t)msg[3] << 24) | ((uint32_t)msg[2] << 16)
			| ((uint32_t)msg[1] << 8) | ((uint32_t)msg[0]);
		msg += 4;
		i++;
	}
	return (msg);
}

static t_md5	hash(t_md5 mem, uint32_t *x, size_t i)
{
	static uint32_t	(*mask[4])(uint32_t, uint32_t, uint32_t) = {
		&md5_f, &md5_g, &md5_h, &md5_i
	};

	mem.a += mask[i / 16](mem.b, mem.c, mem.d) + x[md5_const_k(i)]
			+ ((uint32_t)(md5_const_t(i) & 0xffffffff));
	mem.a = md5_rotateleft(mem.a, (uint32_t)md5_const_s(i)) & 0xffffffff;
	mem.a += mem.b;
	return (mem);
}

void			md5(uint8_t *str, size_t len)
{
	t_md5		mem;
	t_md5		buff;
	size_t		i;
	uint32_t	x[16];
	uint8_t		*msg;

	mem = init();
	buff = init();
	str = preprocess(str, len);
	msg = str;
	while (msg - str <= (long)(len + 8) && (msg = getnextpart(x, msg)))
	{
		buff = md5_memcopy(buff, mem);
		i = 0;
		while (i < 64)
		{
			mem = hash(mem, x, i);
			mem = md5_memrotate(mem);
			i++;
		}
		mem = md5_memadd(mem, buff);
	}
	free(str);
	md5_print(mem);
}
