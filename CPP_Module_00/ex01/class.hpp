#ifndef CLASS_HPP
# define CLASS_HPP

#include <iostream>
#include <string>

#define MAX_NUM_OF_CONTACTS 8

class Contact {
public:
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	d_secret;
};

class PhoneBook {
public:
	Contact user[MAX_NUM_OF_CONTACTS];
	int		max_contacts;
};

void	add_contact(PhoneBook *book);

void	print_contacts(PhoneBook *book);

#endif