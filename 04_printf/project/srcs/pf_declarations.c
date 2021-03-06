/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_declarations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:07:03 by cmaxime           #+#    #+#             */
/*   Updated: 2018/01/15 14:45:11 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**pf_get_list_flag(void)
{
	static char *list[6] = {
		"sSpdDioOuUxXcC%",
		"lhjzL",
		"0123456789",
		".",
		"0123456789",
		"+- #0"
	};

	return (list);
}

t_op	*pf_get_op(void)
{
	static t_op new[9] = {
		{"#", &pf_op_hash},
		{"0", &pf_op_zero},
		{" ", &pf_op_space},
		{"-", &pf_op_min},
		{"+", &pf_op_plus},
		{"0123456789", &pf_op_size},
		{".", &pf_op_precision},
		{"lhjzL", &pf_op_modifier},
		{"", &pf_op_conv}
	};

	return (new);
}

t_cnv	*pf_get_cnv(void)
{
	static t_cnv	new[7] = {
		{"dDi", &pf_arg_int},
		{"oOuUxX", &pf_arg_uint},
		{"sS", &pf_arg_str},
		{"p", &pf_arg_ptr},
		{"cC", &pf_arg_chr},
		{"%", &pf_arg_arg},
		{"", &pf_arg_def}
	};

	return (new);
}
