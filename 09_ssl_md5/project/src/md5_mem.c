/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:13:43 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/20 14:13:51 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

t_md5	md5_memcopy(t_md5 mem, t_md5 buff)
{
	mem.a = buff.a;
	mem.b = buff.b;
	mem.c = buff.c;
	mem.d = buff.d;
	return (mem);
}

t_md5	md5_memadd(t_md5 mem, t_md5 buff)
{
	mem.a += buff.a;
	mem.b += buff.b;
	mem.c += buff.c;
	mem.d += buff.d;
	return (mem);
}

t_md5	md5_memrotate(t_md5 mem)
{
	uint32_t	tmp;

	tmp = mem.d;
	mem.d = mem.c;
	mem.c = mem.b;
	mem.b = mem.a;
	mem.a = tmp;
	return (mem);
}
