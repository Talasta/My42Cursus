/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img_pxl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:54:01 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/04 17:27:23 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	set_img_pxl(t_img img, int x, int y, int color)
{
	if (x < img.size_line / 4 && y < img.size_column && x > -1 && y > -1)
		img.data[x + (y * img.size_line / 4)] = color;
	return (img);
}
