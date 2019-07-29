/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:35:02 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/10 15:30:12 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_chunk	*getregion(size_t size)
{
	if (size <= M_TINY_CHUNK)
		return (g_region[0]);
	if (size <= M_SMALL_CHUNK)
		return (g_region[1]);
	return (g_region[2]);
}

static t_chunk	*searchfree(t_chunk *chunk)
{
	while (chunk)
	{
		if (chunk->free == 0)
			return (chunk);
		chunk = chunk->next;
	}
	return (chunk);
}

t_chunk			*searchunk(void *ptr)
{
	size_t	idx;
	t_chunk	*chunk;

	idx = 0;
	while (idx < 3)
	{
		chunk = g_region[idx];
		while (chunk && (uintptr_t)chunk + sizeof(t_chunk) != (uintptr_t)ptr)
			chunk = chunk->next;
		if (chunk)
		{
			return (chunk);
		}
		idx++;
	}
	return (NULL);
}

t_chunk			*getchunk(size_t size)
{
	t_chunk	*chunk;

	chunk = searchfree(getregion(size));
	if (!chunk)
	{
		if ((allocate_region(size)) < 0)
			return (NULL);
		chunk = getchunk(size);
	}
	return (chunk);
}
