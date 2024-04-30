#include "class.hpp"

void	PhoneBook::add_contact()
{
	std::cout << "Remember, You can have up to 8 contacts!\n" << std::endl;
	if (this->_max_contacts == MAX_NUM_OF_CONTACTS)
		std::cout << "You already have 8 contacts. ";
		std::cout << "If you add another one your oldest contact will be overwritten." << std::endl;
	std::cout << "First Name: ";
	this->_user[this->_max_contacts].set_first_name();
	//Repeat

}