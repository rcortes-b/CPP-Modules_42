#include "class.hpp"

void	PhoneBook::sort_contacts()
{
	int	i;

	i = 0;
	while (++i < 8)
	{
		this->_user[i - 1] = this->_user[i];
		this->_user[i - 1].set_index(this->_user[i - 1].get_index() - 1);
	}
}

void	PhoneBook::add_contact()
{
	std::string	is_follow;

	std::cout << "Remember, You can have up to 8 contacts!\n" << std::endl;
	if (this->_max_contacts == MAX_NUM_OF_CONTACTS)
	{
		std::cout << "You already have 8 contacts. ";
		std::cout << "If you add another one your oldest contact will be overwritten." << std::endl;
		while (1)
		{
			std::cout << "Type y/n to continue ";
			std::cin >> is_follow;
			if (is_follow.compare("y") == 0)
			{
				this->sort_contacts();
				break ;
			}
			else if (is_follow.compare("n") == 0)
				return ;
		}
	}
	if (this->_max_contacts == MAX_NUM_OF_CONTACTS)
		this->_max_contacts--;
	this->_user[this->_max_contacts].set_index(this->_max_contacts + 1);
	this->_user[this->_max_contacts].set_first_name();
	this->_user[this->_max_contacts].set_last_name();
	this->_user[this->_max_contacts].set_nickname();
	this->_user[this->_max_contacts].set_phone_number();
	this->_user[this->_max_contacts].set_dsecret();
	this->increment_index();
}

static void	print_data(std::string str)
{
	int	size;

	size = str.size();
	if (size > 8)
	{
		for (int j = 0; j < 7; j++)
			std::cout << str[j];
		std::cout << ". | ";
	}
	else
	{
		size = 8 - size;
		std::cout << str;
		for (int j = 0; j < size; j++)
			std::cout << " ";
		std::cout << " | ";
	}
}

void	PhoneBook::search()
{
	int	index;

	std::cout << "  " << "INDEX" << "    ";
	std::cout << "  " << "FIRST" << "     ";
	std::cout << "  " << "LAST" << "    ";
	std::cout << " " << "NICKNAME" << "   ";
	std::cout << std::endl;
	for (int i = 0; i < this->_max_contacts; i++)
	{
		std::cout << "    " << this->_user[i].get_index() << "     | ";
		print_data(this->_user[i].get_fname());
		print_data(this->_user[i].get_lname());
		print_data(this->_user[i].get_nickname());
		std::cout << std::endl;
	}
	std::cout << std::endl;
	while (1)
	{
		std::cout << "Introduce a valid index to display a contact or 0 to exit:";
		std::cin >> index;
		if (index == 0)
			return ;
		if (index < 1 && index > this->_max_contacts)
			std::cout << "Invalid index. Try it again." << std::endl;
		else
			break ;
	}
	std::cout << this->_user[index - 1].get_index() << std::endl;
	std::cout << this->_user[index - 1].get_fname() << std::endl;
	std::cout << this->_user[index - 1].get_lname() << std::endl;
	std::cout << this->_user[index - 1].get_nickname() << std::endl;
	std::cout << this->_user[index - 1].get_phone_number() << std::endl;
	std::cout << this->_user[index - 1].get_dsecret() << "\n" << std::endl;
}
