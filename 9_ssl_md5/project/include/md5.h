/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:37:50 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/20 14:11:28 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include <stddef.h>
# include <stdint.h>

/*
** Memory structure for MD5 hashing operations
*/
typedef struct		s_md5
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
}					t_md5;

/*
** Printing function for MD5
*/
void				md5_print(t_md5 mem);

/*
** Binary operations for MD5
*/
uint32_t			md5_rotateleft(uint32_t nb, uint32_t s);
uint32_t			md5_i(uint32_t x, uint32_t y, uint32_t z);
uint32_t			md5_h(uint32_t x, uint32_t y, uint32_t z);
uint32_t			md5_g(uint32_t x, uint32_t y, uint32_t z);
uint32_t			md5_f(uint32_t x, uint32_t y, uint32_t z);

/*
** Acces constant by index
*/
uint64_t			md5_const_t(size_t idx);
size_t				md5_const_k(size_t idx);
size_t				md5_const_s(size_t idx);

/*
** Operations on MD5 memory
*/
t_md5				md5_memcopy(t_md5 mem, t_md5 buff);
t_md5				md5_memadd(t_md5 mem, t_md5 buff);
t_md5				md5_memrotate(t_md5 mem);

/*
** MD5 PROTOTYPE
*/
void				md5(uint8_t *str, size_t len);

#endif
