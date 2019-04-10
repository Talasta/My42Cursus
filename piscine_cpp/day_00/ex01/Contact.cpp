/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:54:46 by cmaxime           #+#    #+#             */
/*   Updated: 2019/03/25 15:10:04 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact( void ) : _len(CONTACT_FIELD_LEN) {
	return ;
}

Contact::~Contact( void ) {

	Contact::_nbInst -= 1;

	return ;
}

void 	Contact::setInstance( void ) {
	char	buff[512];

	Contact::_nbInst += 1;

	this->readParam(buff, "First name: ", this->_first_name);
	this->readParam(buff, "Last name: ", this->_last_name);
	this->readParam(buff, "Nickname: ", this->_nickname);
	this->readParam(buff, "Login: ", this->_login);
	this->readParam(buff, "Postal address: ", this->_postal_address);
	this->readParam(buff, "Email address: ", this->_email_address);
	this->readParam(buff, "Phone number: ", this->_phone_number);
	this->readParam(buff, "Birthday date: ", this->_birthday_date);
	this->readParam(buff, "Favorite meal: ", this->_favorite_meal);
	this->readParam(buff, "Underwear color: ", this->_underwear_color);
	this->readParam(buff, "Darkest secret: ", this->_darkest_secret);

	return ;
}

void	Contact::formatShortAttr( char * str ) {
	int		i;
	char	buff[11];

	std::strncpy(buff, str, 10);
	if (std::strlen(buff) == 10)
		buff[9] = '.';
	buff[10] = '\0';
	i = 0;
	std::cout << "|";
	while (buff[i] && i < 10)
		i++;
	while (i < 10)
	{
		std::cout << " ";
		i++;
	}
	std::cout << buff;
	return ;
}

void	Contact::showInfo( int idx ) {

	std::cout << "|         " << idx;
	this->formatShortAttr(this->_first_name);
	this->formatShortAttr(this->_last_name);
	this->formatShortAttr(this->_nickname);
	std::cout << "|" << std::endl;

	return ;
}

void	Contact::formatAttr( const char* msg , char * str ) {

	std::cout << msg << str << std::endl;

	return ;
}

void	Contact::showAllInfo( void ) {

	this->formatAttr("First name: ", this->_first_name);
	this->formatAttr("Last name: ", this->_last_name);
	this->formatAttr("Nickname: ", this->_nickname);
	this->formatAttr("Login: ", this->_login);
	this->formatAttr("Postal address: ", this->_postal_address);
	this->formatAttr("Email address: ", this->_email_address);
	this->formatAttr("Phone number: ", this->_phone_number);
	this->formatAttr("Birthday date: ", this->_birthday_date);
	this->formatAttr("Favorite meal: ", this->_favorite_meal);
	this->formatAttr("Underwear color: ", this->_underwear_color);
	this->formatAttr("Darkest secret: ", this->_darkest_secret);

	return ;
}

void 	Contact::readParam( char * buff, const char msg[] , char * dst ) {

	std::cout << msg;
	if (std::cin.getline(buff, 512) == NULL)
		return ;
	if (std::cin.eof()) {
        std::cout << std::endl;
        std::exit(1);
    }
	while (std::strlen(buff) >= this->_len)
	{
		std::cout << "Error, param is too long. max : " << this->_len;
		std::cout << std::endl << msg;
		if (std::cin.getline(buff, 512) == NULL)
			return ;
		if (std::cin.eof()) {
	        std::cout << std::endl;
	        std::exit(1);
	    }
	}

	std::strcpy(dst, buff);
}

int		Contact::_nbInst = 0;
