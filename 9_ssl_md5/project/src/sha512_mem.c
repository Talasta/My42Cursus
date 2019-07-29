/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:57:48 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/28 13:57:55 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha2.h"

t_sha512	sha512_memadd(t_sha512 mem, t_sha512 buff)
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

t_sha512	sha512_memcopy(t_sha512 mem, t_sha512 buff)
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

t_sha512	initsha512(void)
{
	t_sha512		mem;

	mem.a = 0x6a09e667f3bcc908;
	mem.b = 0xbb67ae8584caa73b;
	mem.c = 0x3c6ef372fe94f82b;
	mem.d = 0xa54ff53a5f1d36f1;
	mem.e = 0x510e527fade682d1;
	mem.f = 0x9b05688c2b3e6c1f;
	mem.g = 0x1f83d9abfb41bd6b;
	mem.h = 0x5be0cd19137e2179;
	return (mem);
}

t_sha512	initsha384(void)
{
	t_sha512		mem;

	mem.a = 0xcbbb9d5dc1059ed8;
	mem.b = 0x629a292a367cd507;
	mem.c = 0x9159015a3070dd17;
	mem.d = 0x152fecd8f70e5939;
	mem.e = 0x67332667ffc00b31;
	mem.f = 0x8eb44a8768581511;
	mem.g = 0xdb0c2e0d64f98fa7;
	mem.h = 0x47b5481dbefa4fa4;
	return (mem);
}
