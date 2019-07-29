/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_binrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:57:10 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/28 14:01:11 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha2.h"

static uint32_t	shr(uint32_t x, uint32_t n)
{
	return (((x) >> (n)) | ((x) << (32 - (n))));
}

uint32_t		sha256_e0(uint32_t x)
{
	return (shr(x, 2) ^ shr(x, 13) ^ shr(x, 22));
}

uint32_t		sha256_e1(uint32_t x)
{
	return (shr(x, 6) ^ shr(x, 11) ^ shr(x, 25));
}

uint32_t		sha256_s0(uint32_t x)
{
	return (shr(x, 7) ^ shr(x, 18) ^ (x >> 3));
}

uint32_t		sha256_s1(uint32_t x)
{
	return (shr(x, 17) ^ shr(x, 19) ^ (x >> 10));
}
