/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:23:42 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/19 17:59:16 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ps_main.h"

char	*ps_rlow(t_data *data, char *cmd);
char	*ps_low(t_data *data, char *cmd);
char	*ps_test(t_data *data, char *cmd);
int		ps_getmed(t_data *data);
char	*ps_op_find(t_data *data);
char	*ps_repush_b(t_data *data, char	*cmd);
char	*ps_first_round(t_data *data, char *cmd, int mult);
char	*ps_get_next_op1(t_data *data);
char	*ps_get_next_op2(t_data *data);
char	*ps_get_next_op3(t_data *data);
char	*ps_get_next_op4(t_data *data);
char	*ps_clean_cmd(char *cmd);
char	*ps_first_round_red(t_data *data, char *cmd, int mult, int size);

int		ps_check_min(int n, t_list *elem, int min);
int		ps_check_max(int n, t_list *elem);
int		ps_ismin(int min, t_list *elem);
int		ps_in_lst(int n, t_list *elem);
int		ps_medval(t_list *elem);
int		ps_medval_a(t_list *elem, int min);
int		ps_size_lst(t_list *elem);
void	ps_lstaddfront(t_list **n, int val);
void	ps_lstdelfront(t_list **n);
int		ps_getmax_qs(t_list *elem);
int		ps_getmax2_qs(t_list *elem, int max);
int		ps_getway_qs(t_list *elem, int max);
char	*ps_selection_sort_b(t_data *data, char *cmd);
int		ps_size_lst_qs(t_list *elem, int min);
char	*ps_pushback_qs(t_data *data, char *cmd);
int		ps_getmin(t_list *elem);
int		ps_size_lst_max(t_list *elem, int max);

char	*ps_radix_sort(t_data *data, char *cmd);
char	*ps_shell_sort(t_data *data, char *cmd);
char	*ps_quick_sort(t_data *data, char *cmd);

int		ps_pile_a_sorted(t_list *elem);
int		ps_pile_b_sorted(t_list *elem);

int		ps_chk_rra(t_data *data);
int		ps_chk_rrb(t_data *data);
int		ps_chk_sa(t_data *data);
int		ps_chk_sb(t_data *data);
int		ps_chk_pb(t_data *data);
int		ps_chk_pa(t_data *data);
int		ps_chk_rb(t_data *data);
int		ps_chk_ra(t_data *data);

char	*ps_add_rrb(t_data *data);
char	*ps_add_rra(t_data *data);
char	*ps_add_rr(t_data *data);
char	*ps_add_ra(t_data *data);
char	*ps_add_rb(t_data *data);
char	*ps_add_pb(t_data *data);
char	*ps_add_pa(t_data *data);
char	*ps_add_sa(t_data *data);
char	*ps_add_sb(t_data *data);
char	*ps_add_ss(t_data *data);

#endif
