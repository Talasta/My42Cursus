/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:22:05 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 21:22:41 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "unistd.h"
# include "fcntl.h"

# define NL ft_putchar('\n')
# define STR(str) ft_putstr(str); NL
# define PM(map) ft_printmap(map); NL
# define NB(nb) ft_putnbr(nb); NL
# define D STR("OK")

int				**ft_findmap(int *size, t_ulist *list, unsigned long *map, \
		int **pos);
int				**ft_inittracking(t_ulist *list, int *size);
int				ft_putresult(t_ulist *list, int **pos, int size);
int				**ft_tetratl(int **tetra);
int				ft_putusage(void);
int				ft_puterror(void);
int				ft_readfile(char *filename, t_ulist **list);
int				**ft_newtetra(char *buf);
int				**ft_mlctetra(void);
int				ft_testcount(char *buf);
int				ft_isquadra(char *buf);
int				ft_reco(char *str);
int				**ft_resetpos(int **pos, size_t size);
int				**ft_resetptr(int **pos, size_t size);
int				**ft_mlcpos(size_t size);
int				**ft_resetpos(int **pos, size_t size);
int				**ft_inittracking(t_ulist *list, int *size);
char			**ft_addelem(char **tab, int **offset, t_ulist *list);
void			ft_puttab(char **tab, size_t size);
void			**ft_newmatrix(size_t x, size_t y, size_t size);
int				**ft_resetptr(int **pos, size_t size);
int				**ft_newtetra(char *buf);
void			ft_lstupdate(t_ulist *list);
int				**ft_bittotab(unsigned long *tetri);
unsigned long	*ft_newmap(size_t size);
unsigned long	*ft_tetribit(int **pos);
void			ft_tetridel(unsigned long *tetri, size_t size);
unsigned long	*ft_addtetri(unsigned long *map, unsigned long *tetri, \
		int x, int y);
unsigned long	*ft_reversemap(unsigned long *new, unsigned long *blank);
unsigned long	*ft_mapbackup(unsigned long *map, unsigned long *tetri, \
		int x, int y);
int				ft_comparemap(unsigned long *map1, unsigned long *map2);
int				ft_checkpos(unsigned long *map, unsigned long *elem, \
		int x, int y);

long			ft_powl(int nb, int power);
void			ft_printbit(unsigned long oct);
void			ft_printmap(unsigned long *map);

#endif
