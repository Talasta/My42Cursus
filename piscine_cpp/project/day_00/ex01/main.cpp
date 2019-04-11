/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:55:10 by cmaxime           #+#    #+#             */
/*   Updated: 2019/03/25 15:09:57 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"

int		main( void )
{
	Phonebook	p;
	char 		buff[512];

 	while (1) {
		std::cout << "Please select an action [ADD|SEARCH|EXIT]: ";
		if (std::cin.getline(buff, 512) == NULL)
			break;
		if (std::cin.eof()) {
	        std::cout << std::endl;
	        std::exit(1);
	    }
		if (std::strcmp(buff, "ADD") == 0) {
			p.addContact();
		} else if (std::strcmp(buff, "SEARCH") == 0) {
			p.showAllContact();
		} else if (std::strcmp(buff, "EXIT") == 0) {
			break;
		}
	}
	return 0;
}
