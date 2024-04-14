#include "class.hpp"

static PhoneBook *sort_contacts(PhoneBook *book)
{
	int			i;

	i = 0;
	while (++i < 8)
	{
		book->user[i - 1] = book->user[i];
		book->user[i - 1].index--;
	}
	return (book);
}

void	add_contact(PhoneBook *book)
{
	Contact	new_contact;

	std::cout << "First Name: ";
	std::cin >> new_contact.first_name;
	std::cout << "Last Name: ";
	std::cin >> new_contact.last_name;
	std::cout << "Nickname: ";
	std::cin >> new_contact.nickname;
	std::cout << "Phone Number: ";
	std::cin >> new_contact.phone_number;
	std::cout << "Your darkest secret: ";
	std::cin >> new_contact.d_secret;
	std::cout << std::endl;
	if (book->max_contacts == MAX_NUM_OF_CONTACTS)
		book = sort_contacts(book);
	book->user[book->max_contacts] = new_contact;
	book->user[book->max_contacts].index = book->max_contacts + 1;
	if (book->max_contacts < 8)
		book->max_contacts++;
}

// index, first name, last and nickname
static int	ft_strlen(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	print_data(std::string str)
{
	int	size;

	size = ft_strlen(str);
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

void	print_contacts(PhoneBook *book)
{
	std::cout << "  " << "INDEX" << "    ";
	std::cout << "  " << "FIRST" << "     ";
	std::cout << "  " << "LAST" << "    ";
	std::cout << " " << "NICKNAME" << "   ";
	std::cout << std::endl;
	for (int i = 0; i < book->max_contacts; i++)
	{
		std::cout << "    " << book->user[i].index << "     | ";
		print_data(book->user[i].first_name);
		print_data(book->user[i].last_name);
		print_data(book->user[i].nickname);
		std::cout << std::endl;
	}
}
