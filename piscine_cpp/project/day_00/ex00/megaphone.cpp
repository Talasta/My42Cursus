/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:13:36 by cmaxime           #+#    #+#             */
/*   Updated: 2019/03/25 10:22:05 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	upper_case_render(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] += 'A' - 'a';
	}
	std::cout << str;
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac >= 2)
	{
		while (av[++i])
			upper_case_render(av[i]);
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
