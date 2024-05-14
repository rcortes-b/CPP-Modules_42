#include "PhoneBook.hpp"

void	Contact::set_index(int index)
{
	this->_index = index;
}

bool	Contact::set_first_name()
{
	std::string	str;

	std::cout << "First Name: ";
	std::getline(std::cin, str);
	if (!str[0])
		return (false);
	this->_first_name = str;
	return (true);
}

bool	Contact::set_last_name()
{
	std::string	str;

	std::cout << "Last Name: ";
	std::getline(std::cin, str);
	if (!str[0])
		return (false);
	this->_last_name = str;
	return (true);

}

bool	Contact::set_nickname()
{
	std::string	str;

	std::cout << "Nickname: ";
	std::getline(std::cin, str);
	if (!str[0])
		return (false);
	this->_nickname = str;
	return (true);
}

bool	Contact::set_phone_number()
{
	std::string	str;

	std::cout << "Phone Number: ";
	std::getline(std::cin, str);
	if (!str[0])
		return (false);
	for (int l = 0; str[l]; l++)
	{
		if (str[l] == '+' && l > 0)
			return (false);
		else if (!std::isdigit(str[l]) && str[l] != '+')
			return (false);
	}
	this->_phone_number = str;
	return (true);
}

bool	Contact::set_dsecret()
{
	std::string	str;

	std::cout << "Your Darkest Secret: ";
	std::getline(std::cin, str);
	while (!str[0])
		std::getline(std::cin, str);
	this->_dsecret = str;
	return (true);
}

void	PhoneBook::init_index()
{
	this->_max_contacts = 0;
}

void	PhoneBook::increment_index()
{
	this->_max_contacts++;
}
