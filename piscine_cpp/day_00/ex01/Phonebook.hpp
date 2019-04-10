/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:10:29 by cmaxime           #+#    #+#             */
/*   Updated: 2019/03/25 15:10:32 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


# include "Contact.hpp"

class Phonebook {

public:

	Phonebook( void );
	~Phonebook( void );

    void   addContact( void );
    void   showContact( int );
    void   showAllContact( void );
    int    getSize( void );

private:

	int const	_len;
    Contact     _list[8];

};

#endif
