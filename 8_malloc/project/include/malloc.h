/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:53:53 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/10 15:51:20 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <errno.h>

# define M_REGION_SIZE 100
# define M_TINY_CHUNK 64
# define M_SMALL_CHUNK 1024

typedef struct	s_chunk
{
	size_t			chunk_size;
	int				begin;
	int				free;
	struct s_chunk	*next;
}				t_chunk;

extern t_chunk	*g_region[3];

/*
** mmap manager functions
*/
int				allocate_region(size_t size);
t_chunk			*getchunk(size_t size);
t_chunk			*searchunk(void *ptr);

/*
** C functions
*/
void			*malloc(size_t size);
void			free(void *ptr);
void			*realloc(void *ptr, size_t size);

/*
** Print function
*/
void			show_alloc_mem(void);
void			m_putchar(char c);
void			m_putstr(char *str);
void			m_putnbase(size_t nbr, size_t base, int pad);

#endif
