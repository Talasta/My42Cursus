/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:55:54 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/28 13:55:56 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA2_H
# define SHA2_H

# include <stddef.h>
# include <stdint.h>

/*
** Memory structure for SHA256 hashing operations
*/
typedef struct	s_sha256
{
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		e;
	uint32_t		f;
	uint32_t		g;
	uint32_t		h;
}				t_sha256;

/*
** Printing function for SHA256
*/
void			sha256_print(t_sha256 mem);

/*
** Acces constant by index
*/
uint32_t		sha256_const_k(size_t idx);

/*
** Binary operations for SHA256
*/
uint32_t		sha256_e0(uint32_t x);
uint32_t		sha256_e1(uint32_t x);
uint32_t		sha256_s0(uint32_t x);
uint32_t		sha256_s1(uint32_t x);
uint32_t		sha256_ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t		sha256_maj(uint32_t x, uint32_t y, uint32_t z);

/*
** Operations on SHA256 memory
*/
t_sha256		sha256_memadd(t_sha256 mem, t_sha256 buff);
t_sha256		sha256_memcopy(t_sha256 mem, t_sha256 buff);
t_sha256		initsha256(void);

/*
** Memory structure for SHA256 hashing operations
*/
typedef struct	s_sha512
{
	uint64_t		a;
	uint64_t		b;
	uint64_t		c;
	uint64_t		d;
	uint64_t		e;
	uint64_t		f;
	uint64_t		g;
	uint64_t		h;
}				t_sha512;

/*
** Printing function for SHA512
*/
void			sha512_print(t_sha512 mem);
void			sha384_print(t_sha512 mem);

/*
** Acces constant by index
*/
uint64_t		sha512_const_k(size_t idx);

/*
** Binary operations for SHA512
*/
uint64_t		sha512_e0(uint64_t x);
uint64_t		sha512_e1(uint64_t x);
uint64_t		sha512_s0(uint64_t x);
uint64_t		sha512_s1(uint64_t x);
uint64_t		sha512_ch(uint64_t x, uint64_t y, uint64_t z);
uint64_t		sha512_maj(uint64_t x, uint64_t y, uint64_t z);

/*
** Operations on SHA512 memory
*/
t_sha512		sha512_memadd(t_sha512 mem, t_sha512 buff);
t_sha512		sha512_memcopy(t_sha512 mem, t_sha512 buff);
t_sha512		initsha512(void);
t_sha512		initsha384(void);

/*
** SHA2 PROTOTYPE
*/
void			sha256(uint8_t *str, size_t len);
void			sha512(uint8_t *str, size_t len);
void			sha384(uint8_t *str, size_t len);

#endif
