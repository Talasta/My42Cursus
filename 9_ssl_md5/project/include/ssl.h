/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:37:50 by cmaxime           #+#    #+#             */
/*   Updated: 2019/05/28 13:56:06 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H
# define SSL_H

# define SSL_ERR1 1
# define SSL_ERR2 2
# define SSL_ERR3 3

# include <stddef.h>
# include <stdint.h>

void	sha384(uint8_t *str, size_t len);
void	sha512(uint8_t *str, size_t len);
void	sha256(uint8_t *str, size_t len);
void	md5(uint8_t *str, size_t len);
int		argparser(int ac, char *av[]);

#endif
