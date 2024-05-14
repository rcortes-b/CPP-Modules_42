#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <stdbool.h>

#define MAX_NUM_OF_CONTACTS 8

class Contact {
private:
		int			_index;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_dsecret;
public:
		void		set_index(int index);
		bool		set_first_name();
		bool		set_last_name();
		bool		set_nickname();
		bool		set_phone_number();
		bool		set_dsecret();
		int			get_index();
		std::string	get_fname();
		std::string	get_lname();
		std::string	get_nickname();
		std::string	get_phone_number();
		std::string	get_dsecret();

};

#endif