/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 00:07:20 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/15 19:23:25 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_MAIN_H
# define PS_MAIN_H

# include "libft.h"
# include <limits.h>

typedef struct	s_data
{
	t_list	*a;
	t_list	*b;
	int		min;
	int		max;
	int		size;
	int		status;
	int		error;
}				t_data;

typedef struct	s_op
{
	char	*cmd;
	void	(*op)(t_data *data);
}				t_op;

int				ps_get_content(t_list *elem);
t_data			ps_init_data(void);
void			ps_destroy_data(t_data *data);
int				ps_lstpushback(t_list **alst, t_list *new);
int				ps_isint(char *str, int *n);
int				ps_fetch_pile(char **av, t_data *data);
void			ps_free_elem(t_list *elem);
char			**ft_realloc_strtab(char **dst, char **src);
void			ps_destroy_list(t_list *elem);
void			ps_print_pile(t_data data, char *op);

void			ps_swap_a(t_data *data);
void			ps_swap_b(t_data *data);
void			ps_swap_ab(t_data *data);
void			ps_push_a(t_data *data);
void			ps_push_b(t_data *data);
void			ps_rotate_a(t_data *data);
void			ps_rotate_b(t_data *data);
void			ps_rotate_ab(t_data *data);
void			ps_rotate_rev_a(t_data *data);
void			ps_rotate_rev_b(t_data *data);
void			ps_rotate_rev_ab(t_data *data);

void			ft_lstpushback(t_list **alst, t_list *new);
t_list			*ft_lstlast(t_list *elem);
t_list			*ft_lstprevlast(t_list *elem);
intmax_t		ft_atointmax(const char *str);
int				ft_strisdigit(char *str);

#endif
