/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_binop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:13:30 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/20 14:13:39 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

uint32_t		md5_f(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x) & (y)) | ((~x) & (z)));
}

uint32_t		md5_g(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x) & (z)) | ((y) & (~z)));
}

uint32_t		md5_h(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x) ^ (y) ^ (z));
}

uint32_t		md5_i(uint32_t x, uint32_t y, uint32_t z)
{
	return ((y) ^ ((x) | (~z)));
}

uint32_t		md5_rotateleft(uint32_t nb, uint32_t s)
{
	return ((nb << s) | (nb >> (32 - s)));
}
