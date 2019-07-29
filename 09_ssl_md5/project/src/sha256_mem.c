/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:57:48 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/28 13:57:55 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha2.h"

t_sha256	sha256_memadd(t_sha256 mem, t_sha256 buff)
{
	mem.a += buff.a;
	mem.b += buff.b;
	mem.c += buff.c;
	mem.d += buff.d;
	mem.e += buff.e;
	mem.f += buff.f;
	mem.g += buff.g;
	mem.h += buff.h;
	return (mem);
}

t_sha256	sha256_memcopy(t_sha256 mem, t_sha256 buff)
{
	mem.a = buff.a;
	mem.b = buff.b;
	mem.c = buff.c;
	mem.d = buff.d;
	mem.e = buff.e;
	mem.f = buff.f;
	mem.g = buff.g;
	mem.h = buff.h;
	return (mem);
}

t_sha256	initsha256(void)
{
	t_sha256		mem;

	mem.a = 0x6a09e667;
	mem.b = 0xbb67ae85;
	mem.c = 0x3c6ef372;
	mem.d = 0xa54ff53a;
	mem.e = 0x510e527f;
	mem.f = 0x9b05688c;
	mem.g = 0x1f83d9ab;
	mem.h = 0x5be0cd19;
	return (mem);
}
