/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
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
	msg = (uint8_t*)ft_memalloc((len + 256) * sizeof(uint8_t));
	msg = ft_memcpy(msg, str, len);
	msg[len++] = 0x80;
	while (len % 128 != 112)
	{
		msg[len] = 0x00;
		len++;
	}
	len += 8;
	while (len % 128)
	{
		msg[len] = (orig >> (8 * (15 - (len - 112) % 16))) & 0xff;
		len++;
	}
	return (msg);
}

static uint8_t	*getnextpart(uint64_t *x, uint8_t *msg)
{
	size_t	i;

	i = 0;
	while (i < 16)
	{
		x[i] = ((uint64_t)msg[0] << 56) | ((uint64_t)msg[1] << 48)
			| ((uint64_t)msg[2] << 40) | ((uint64_t)msg[3] << 32)
			| ((uint64_t)msg[4] << 24) | ((uint64_t)msg[5] << 16)
			| ((uint64_t)msg[6] << 8) | ((uint64_t)msg[7]);
		msg += 8;
		i++;
	}
	while (i < 80)
	{
		x[i] = 0;
		i++;
	}
	return (msg);
}

static void		prepareblocks(uint64_t *x)
{
	size_t	t;

	t = 16;
	while (t < 80)
	{
		x[t] = sha512_s1(x[t - 2]) + x[t - 7]
			+ sha512_s0(x[t - 15]) + x[t - 16];
		t++;
	}
}

static t_sha512	hash(t_sha512 mem, uint64_t *w, size_t idx)
{
	uint64_t	t1;
	uint64_t	t2;

	t1 = mem.h + sha512_e1(mem.e) + sha512_ch(mem.e, mem.f, mem.g)
		+ sha512_const_k(idx) + w[idx];
	t2 = sha512_e0(mem.a) + sha512_maj(mem.a, mem.b, mem.c);
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

void			sha384(uint8_t *str, size_t len)
{
	t_sha512	mem;
	t_sha512	buff;
	size_t		i;
	uint64_t	x[80];
	uint8_t		*msg;

	mem = initsha384();
	buff = initsha384();
	str = preprocess(str, len);
	msg = str;
	while (msg - str <= (long)(len + 16) && (msg = getnextpart(x, msg)))
	{
		buff = sha512_memcopy(buff, mem);
		prepareblocks(x);
		i = 0;
		while (i < 80)
		{
			mem = hash(mem, x, i);
			i++;
		}
		mem = sha512_memadd(mem, buff);
	}
	free(str);
	sha384_print(mem);
}
