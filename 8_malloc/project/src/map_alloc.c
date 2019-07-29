/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:11:09 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/10 15:57:51 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <unistd.h>
#include "malloc.h"

t_chunk		*g_region[3] = {NULL, NULL, NULL};

static void		addregion(t_chunk **head, t_chunk *region)
{
	t_chunk	*chunk;

	chunk = *head;
	if (chunk)
	{
		while (chunk->next)
			chunk = chunk->next;
		chunk->next = region;
	}
	else
		*head = region;
}

static size_t	fillsize(size_t size, t_chunk ***addr)
{
	if (size <= M_TINY_CHUNK)
	{
		*addr = g_region;
		return (M_TINY_CHUNK);
	}
	if (size <= M_SMALL_CHUNK)
	{
		*addr = g_region + 1;
		return (M_SMALL_CHUNK);
	}
	*addr = g_region + 2;
	return (size);
}

static void		initchunk(unsigned char *addr, t_chunk *next,
		size_t size, int begin)
{
	t_chunk			*chunk;

	chunk = (t_chunk*)(uintptr_t)addr;
	chunk->chunk_size = size;
	chunk->begin = begin;
	chunk->free = 0;
	chunk->next = next;
}

static void		initregion(unsigned char *memzone, size_t size)
{
	size_t			i;
	unsigned char	*addr;
	t_chunk			*next;
	int				begin;

	addr = memzone;
	i = 0;
	if (size <= M_SMALL_CHUNK)
	{
		while (++i < M_REGION_SIZE)
		{
			next = (t_chunk*)((uintptr_t)addr + (size + sizeof(t_chunk)));
			begin = addr == memzone ? 1 : 0;
			initchunk(addr, next, size, begin);
			addr = (unsigned char*)next;
		}
	}
	next = NULL;
	begin = addr == memzone ? 1 : 0;
	initchunk(addr, next, size, begin);
}

int				allocate_region(size_t size)
{
	t_chunk			**region;
	unsigned char	*memzone;
	size_t			len;
	size_t			ps;

	ps = (size_t)getpagesize();
	region = NULL;
	size = fillsize(size, &region);
	len = size > M_SMALL_CHUNK ? ((size + sizeof(t_chunk) + 1) / ps) * ps + ps
			: (M_REGION_SIZE * (size + sizeof(t_chunk) + 1) / ps) * ps + ps;
	if ((memzone = (unsigned char*)mmap(0, len, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (-1);
	initregion(memzone, size);
	addregion(region, (t_chunk*)(uintptr_t)memzone);
	return (1);
}
