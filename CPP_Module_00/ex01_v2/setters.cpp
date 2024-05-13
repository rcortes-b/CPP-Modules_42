#include "class.hpp"

void	Contact::set_index(int index)
{
	this->_index = index;
}

void	Contact::set_first_name()
{
	std::string	str;

	std::cout << "First Name: ";
	std::cin >> str;
	this->_first_name = str;
}

void	Contact::set_last_name()
{
	std::string	str;

	std::cout << "Last Name: ";
	std::cin >> str;
	this->_last_name = str;
}

void	Contact::set_nickname()
{
	std::string	str;

	std::cout << "Nickname: ";
	std::cin >> str;
	this->_nickname = str;
}

void	Contact::set_phone_number()
{
	std::string	str;

	std::cout << "Phone Number: ";
	std::cin >> str;
	this->_phone_number = str;
}

void	Contact::set_dsecret()
{
	std::string	str;

	std::cout << "Your Darkest Secret: ";
	std::cin >> str;
	this->_dsecret = str;
}

void	PhoneBook::init_index()
{
	this->_max_contacts = 0;
}

void	PhoneBook::increment_index()
{
	this->_max_contacts++;
}
