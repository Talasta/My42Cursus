/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_binrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:57:10 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/28 14:01:11 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha2.h"

static uint64_t	shr(uint64_t x, uint64_t n)
{
	return (((x) >> (n)) | ((x) << (64 - (n))));
}

uint64_t		sha512_e0(uint64_t x)
{
	return (shr(x, 28) ^ shr(x, 34) ^ shr(x, 39));
}

uint64_t		sha512_e1(uint64_t x)
{
	return (shr(x, 14) ^ shr(x, 18) ^ shr(x, 41));
}

uint64_t		sha512_s0(uint64_t x)
{
	return (shr(x, 1) ^ shr(x, 8) ^ (x >> 7));
}

uint64_t		sha512_s1(uint64_t x)
{
	return (shr(x, 19) ^ shr(x, 61) ^ (x >> 6));
}
