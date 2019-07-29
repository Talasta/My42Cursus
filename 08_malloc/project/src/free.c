/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:54:11 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/13 10:29:14 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <sys/mman.h>

static void	fregion_large(t_chunk *chunk)
{
	t_chunk		*buff;

	buff = g_region[2];
	if (chunk && buff)
	{
		if (buff == chunk)
			g_region[2] = chunk->next;
		else
		{
			while (buff->next && buff->next != chunk)
				buff = buff->next;
			if (!buff || !buff->next)
				return ;
			buff->next = buff->next->next;
		}
		munmap((void*)chunk, chunk->chunk_size + sizeof(t_chunk));
	}
}

void		free(void *ptr)
{
	t_chunk	*chunk;

	if (!ptr)
		return ;
	chunk = searchunk(ptr);
	if (chunk && chunk->free)
	{
		chunk->free = 0;
		if (chunk->chunk_size > M_SMALL_CHUNK)
			fregion_large(chunk);
	}
}
