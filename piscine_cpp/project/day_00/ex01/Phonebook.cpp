/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:10:19 by cmaxime           #+#    #+#             */
/*   Updated: 2019/03/25 15:10:22 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"

Phonebook::Phonebook( void ) : _len(8) {
	return;
}

Phonebook::~Phonebook( void ) {
	return;
}

void    Phonebook::addContact( void ) {
    int   id;

    id = this->getSize();
    if (id < this->_len) {
        this->_list[id].setInstance();
    } else {
        std::cout << "Too many contacts in PhoneBook." << std::endl;
        std::cout << "Please contact your administrator." << std::endl;
    }
    return;
}

void    Phonebook::showAllContact( void ) {
    int i;
    char buff[512];

    std::cout << "|Index     |First_name|Last_name |Nickname  |" << std::endl;
    i = -1;
    while (++i < this->getSize())
        this->_list[i].showInfo(i);

    std::cout << "Select the [id] of the contact you want to look at: ";
    std::cin.getline(buff, 512);
	if (std::cin.eof()) {
		std::cout << std::endl;
		std::exit(1);
	}
    if (!(*buff)) {
        std::cout << "Wrong index..." << std::endl;
        return;
    }
    i = -1;
    while (buff[++i]) {
        if (buff[i] < '0' || buff[i] > '9') {
            std::cout << "Wrong index..." << std::endl;
            return;
        }
    }
    this->showContact(std::atoi(buff));
    return;
}

void    Phonebook::showContact( int idx ) {
    if (idx < 0 || idx > this->getSize() - 1)
    {
        std::cout << "Wrong index..." << std::endl;
        return;
    }
    this->_list[idx].showAllInfo();
    return;
}

int     Phonebook::getSize( void ) {
    return Contact::_nbInst;
}
