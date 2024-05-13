#include "class.hpp"

void	PhoneBook::exit_msg()
{
		std::cout << "\n    ";
		std::cout << "\033[1;30mThanks for using Notkia! See you soon.\033[0m\n" <<std::endl;
}

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

bool	PhoneBook::add_contact()
{
	std::string	is_follow;

	std::cout << "\n-----------------------------------------------" << std::endl;
	std::cout << "\n\033[1;31mRemember, You can have up to 8 contacts!\033[0m\n" << std::endl;
	if (this->_max_contacts == MAX_NUM_OF_CONTACTS)
	{
		std::cout << "You already have 8 contacts. ";
		std::cout << "If you add another one your oldest contact will be overwritten." << std::endl;
		while (1)
		{
			std::cout << "Type y/n to continue ";
			std::cin >> is_follow;
			if (!is_follow[0])
				return (false);
			if (is_follow.compare("y") == 0)
			{
				this->sort_contacts();
				break ;
			}
			else if (is_follow.compare("n") == 0)
				return (true);
		}
	}
	if (this->_max_contacts == MAX_NUM_OF_CONTACTS)
		this->_max_contacts--;
	this->_user[this->_max_contacts].set_index(this->_max_contacts + 1);
	if (!this->_user[this->_max_contacts].set_first_name())
		return (false);
	if (!this->_user[this->_max_contacts].set_last_name())
		return (false);
	if (!this->_user[this->_max_contacts].set_nickname())
		return (false);
	if (!this->_user[this->_max_contacts].set_phone_number())
		return (false);
	if (!this->_user[this->_max_contacts].set_dsecret())
		return (false);
	this->increment_index();
	std::cout << std::endl;
	return (true);
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

static void	print_contact(Contact _usr)
{
	std::cout << std::endl;
	std::cout << _usr.get_index() << std::endl;
	std::cout << _usr.get_fname() << std::endl;
	std::cout << _usr.get_lname() << std::endl;
	std::cout << _usr.get_nickname() << std::endl;
	std::cout << _usr.get_phone_number() << std::endl;
	std::cout << _usr.get_dsecret() << "\n" << std::endl;
}

bool	PhoneBook::search()
{
	std::string	index;
	int			ind;

	std::cout << "\n-----------------------------------------------" << std::endl;
	std::cout << "\n\033[1;32mYou have " << this->_max_contacts << " contacts\033[0m\n" <<std::endl;
	std::cout << "  " << "\033[1;32mINDEX" << "    ";
	std::cout << "  " << "FIRST" << "     ";
	std::cout << "  " << "LAST" << "    ";
	std::cout << " " << "NICKNAME\033[0m" << "   ";
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
		std::cout << "Introduce a valid index to display a contact or 0 to exit: ";
		std::cin >> index;
		if (!index[0])
			return (false);
		else if (index.size() > 1)
			std::cout << "\nInvalid index. Try it again.\n" << std::endl;
		else if ((ind = index[0] - '0') && (ind < 1 || ind > this->_max_contacts))
			std::cout << "\nInvalid index. Try it again.\n" << std::endl;
		else
			break ;
		index[0] = '\0';
	}
	print_contact(this->_user[ind - 1]);
	return (true);
}
