/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:54:17 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/10 15:31:22 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static size_t	sizechunk(size_t size)
{
	if (size <= M_TINY_CHUNK)
		return (M_TINY_CHUNK);
	else if (size <= M_SMALL_CHUNK)
		return (M_SMALL_CHUNK);
	return (size);
}

static void		*newregion(void *ptr, size_t oldsize, size_t size)
{
	void	*new;
	size_t	i;

	if ((new = malloc(size)))
	{
		i = 0;
		while (i < size && i < oldsize)
		{
			((unsigned char*)new)[i] = ((unsigned char *)ptr)[i];
			i++;
		}
	}
	free(ptr);
	return (new);
}

void			*realloc(void *ptr, size_t size)
{
	t_chunk	*chunk;

	if (!size)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(size));
	if ((chunk = searchunk(ptr)) == NULL)
		return (NULL);
	if (size > sizechunk(chunk->chunk_size))
		ptr = newregion(ptr, chunk->chunk_size, size);
	else
		chunk->chunk_size = size;
	return (ptr);
}
