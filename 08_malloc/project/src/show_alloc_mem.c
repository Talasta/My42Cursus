/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 09:56:06 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/10 12:13:30 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

static int		cmpaddr(t_chunk *prev, t_chunk *buff, t_chunk *curr)
{
	if (((uintptr_t)curr < (uintptr_t)buff || buff == NULL)
			&& (uintptr_t)curr > (uintptr_t)prev)
	{
		return (1);
	}
	return (0);
}

static t_chunk	*getnext_chunk(t_chunk *prev)
{
	size_t	i;
	t_chunk	*buff;
	t_chunk	*chunk;

	i = 0;
	buff = NULL;
	while (i < 3)
	{
		chunk = g_region[i];
		buff = cmpaddr(prev, buff, chunk) ? chunk : buff;
		while (chunk)
		{
			if (chunk->begin == 1)
			{
				buff = cmpaddr(prev, buff, chunk) ? chunk : buff;
			}
			chunk = chunk->next;
		}
		i++;
	}
	return (buff);
}

static void		printchunk(t_chunk *chunk)
{
	uintptr_t	addr;

	addr = (uintptr_t)chunk + sizeof(t_chunk);
	m_putstr("0x");
	m_putnbase(addr, 16, 5);
	m_putstr(" - 0x");
	m_putnbase(addr + chunk->chunk_size, 16, 5);
	m_putstr(" : ");
	m_putnbase(chunk->chunk_size, 10, -1);
	m_putstr(" octets\n");
}

static size_t	printregion(t_chunk *chunk)
{
	size_t		total;

	total = 0;
	if (chunk && chunk->chunk_size > M_SMALL_CHUNK)
		m_putstr("LARGE : 0x");
	else if (chunk && chunk->chunk_size > M_TINY_CHUNK)
		m_putstr("SMALL : 0x");
	else
		m_putstr("TINY : 0x");
	m_putnbase((uintptr_t)chunk, 16, 5);
	m_putstr("\n");
	while (chunk)
	{
		if (chunk->free == 1)
		{
			printchunk(chunk);
			total += chunk->chunk_size;
		}
		chunk = chunk->next;
		if (!chunk || chunk->begin == 1)
			return (total);
	}
	return (total);
}

void			show_alloc_mem(void)
{
	t_chunk	*chunk;
	size_t	total;

	total = 0;
	chunk = NULL;
	while ((chunk = getnext_chunk(chunk)) != NULL)
		total += printregion(chunk);
	m_putstr("Total : ");
	m_putnbase(total, 10, -1);
	m_putstr(" octets\n");
}
