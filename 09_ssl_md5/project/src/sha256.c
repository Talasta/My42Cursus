/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:56:23 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/28 14:00:25 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha2.h"
#include "libft.h"

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
		msg[len] = (orig >> (8 * (7 - (len - 56) % 8))) & 0xff;
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
		x[i] = ((uint32_t)msg[0] << 24) | ((uint32_t)msg[1] << 16)
			| ((uint32_t)msg[2] << 8) | ((uint32_t)msg[3]);
		msg += 4;
		i++;
	}
	while (i < 64)
	{
		x[i] = 0;
		i++;
	}
	return (msg);
}

static void		prepareblocks(uint32_t *x)
{
	size_t	t;

	t = 16;
	while (t < 64)
	{
		x[t] = sha256_s1(x[t - 2]) + x[t - 7]
			+ sha256_s0(x[t - 15]) + x[t - 16];
		t++;
	}
}

static t_sha256	hash(t_sha256 mem, uint32_t *w, size_t idx)
{
	uint32_t	t1;
	uint32_t	t2;

	t1 = mem.h + sha256_e1(mem.e) + sha256_ch(mem.e, mem.f, mem.g)
		+ sha256_const_k(idx) + w[idx];
	t2 = sha256_e0(mem.a) + sha256_maj(mem.a, mem.b, mem.c);
	mem.h = mem.g;
	mem.g = mem.f;
	mem.f = mem.e;
	mem.e = mem.d + t1;
	mem.d = mem.c;
	mem.c = mem.b;
	mem.b = mem.a;
	mem.a = t1 + t2;
	return (mem);
}

void			sha256(uint8_t *str, size_t len)
{
	t_sha256	mem;
	t_sha256	buff;
	size_t		i;
	uint32_t	x[64];
	uint8_t		*msg;

	mem = initsha256();
	buff = initsha256();
	str = preprocess(str, len);
	msg = str;
	while (msg - str <= (long)(len + 8) && (msg = getnextpart(x, msg)))
	{
		buff = sha256_memcopy(buff, mem);
		prepareblocks(x);
		i = 0;
		while (i < 64)
		{
			mem = hash(mem, x, i);
			i++;
		}
		mem = sha256_memadd(mem, buff);
	}
	free(str);
	sha256_print(mem);
}
