/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:54:04 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/10 15:30:33 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc(size_t size)
{
	t_chunk	*chunk;
	void	*addr;

	if (!(chunk = getchunk(size)))
		return (NULL);
	chunk->free = 1;
	chunk->chunk_size = size;
	addr = (void*)((uintptr_t)chunk + sizeof(t_chunk));
	return (addr);
}
