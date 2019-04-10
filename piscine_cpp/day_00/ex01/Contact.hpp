/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:09:45 by cmaxime           #+#    #+#             */
/*   Updated: 2019/03/25 15:10:09 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# define CONTACT_FIELD_LEN 42

class Contact {

public:

	static int	_nbInst;

	Contact( void );
	~Contact( void );

	void    readParam( char* , const char[] , char* );
	void 	setInstance( void ) ;

	void	formatAttr( const char* , char * );
	void	showAllInfo( void ) ;

    void	formatShortAttr( char* );
	void	showInfo( int ) ;

private:

	size_t 		_len;

	char		_first_name[CONTACT_FIELD_LEN]; // const ici ?
	char       	_last_name[CONTACT_FIELD_LEN];
	char       	_nickname[CONTACT_FIELD_LEN];
	char       	_login[CONTACT_FIELD_LEN];
	char       	_postal_address[CONTACT_FIELD_LEN];
	char       	_email_address[CONTACT_FIELD_LEN];
	char       	_phone_number[CONTACT_FIELD_LEN];
	char       	_birthday_date[CONTACT_FIELD_LEN];
	char       	_favorite_meal[CONTACT_FIELD_LEN];
	char       	_underwear_color[CONTACT_FIELD_LEN];
	char       	_darkest_secret[CONTACT_FIELD_LEN];

};

#endif
