#ifndef CLASS_HPP
# define CLASS_HPP

#include <iostream>
#include <string>

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
		void	set_index(int index);
		void	set_first_name();
		void	set_last_name();
		void	set_nickname();
		void	set_phone_number();
		void	set_dsecret();
};

class PhoneBook {
private:
	
		Contact _user[MAX_NUM_OF_CONTACTS];
		int		_max_contacts;

public:
		void 	add_contact(void);
		void 	search(void);
		void	init_index();
		void	increment_index();
};

void	add_contact(PhoneBook *book);

void	print_contacts(PhoneBook *book);

#endif