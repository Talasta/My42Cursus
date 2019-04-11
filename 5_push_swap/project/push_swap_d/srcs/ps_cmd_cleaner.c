/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmd_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:37:40 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/15 12:57:05 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ps_clean_ss(char *cmd, int *i)
{
	cmd[*i + 1] = 's';
	cmd[*i + 3] = '\0';
	cmd = ft_realloc(cmd, cmd + *i + 6);
	*i = 0;
	return (cmd);
}

char	*ps_clean_p(char *cmd, int *i)
{
	cmd[*i] = '\0';
	cmd = ft_realloc(cmd, cmd + *i + 6);
	*i = 0;
	return (cmd);
}

char	*ps_clean_rrr(char *cmd, int *i)
{
	cmd[*i + 2] = 'r';
	cmd[*i + 4] = '\0';
	cmd = ft_realloc(cmd, cmd + *i + 8);
	return (cmd);
}

char	*ps_clean_cmd(char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == 's' && cmd[i + 3] == 's' && (cmd[i + 1] == \
					cmd[i + 4] + 1 || cmd[i + 1] == cmd[i + 4] - 1))
			cmd = ps_clean_ss(cmd, &i);
		if (cmd[i] == 'p' && cmd[i + 3] == 'p' && (cmd[i + 1] == \
					cmd[i + 4] + 1 || cmd[i + 1] == cmd[i + 4] - 1))
			cmd = ps_clean_p(cmd, &i);
		if (cmd[i] == 'r' && cmd[i + 4] == 'r' && cmd[i + 1] == 'r'
				&& cmd[i + 5] == 'r' && (cmd[i + 2] == cmd[i + 6] + 1
					|| cmd[i + 2] == cmd[i + 6] - 1))
			cmd = ps_clean_rrr(cmd, &i);
		i++;
	}
	return (cmd);
}
