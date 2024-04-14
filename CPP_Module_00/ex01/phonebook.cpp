#include "class.hpp"

static int	ft_strcmp(std::string instruction, const char *s2)
{
	int	i;

	i = 0;
	while (instruction[i] == s2[i] && instruction[i] != '\0' && s2[i] != '\0')
		i++;
	return (instruction[i] - s2[i]);
}

static int	check_input(std::string instruction, PhoneBook *book)
{
	if (instruction[0] == 'A')
	{
		if (ft_strcmp(instruction, "ADD") == 0)
			add_contact(book);
	}
	else if (instruction[0] == 'S')
	{
		if (ft_strcmp(instruction, "SEARCH") == 0)
			print_contacts(book);
	}
	else if (instruction[0] == 'E')
	{
		if (ft_strcmp(instruction, "EXIT") == 0)
		{
			std::cout << "Thanks for using Notkia!" <<std::endl;
			return (0);
		}
	}
	else
		std::cout << "The instruction is incorrect. Please, type it again.\n" << std::endl;
	return (1);
}

static void	do_menu(void)
{
	std::cout << "Choose an option:\n" << std::endl;
	std::cout << "1- Type \"ADD\" to save a contact." << std::endl;
	std::cout << "2- Type \"SEARCH\" to display the contacts." << std::endl;
	std::cout << "3- Type \"EXIT\" to leave from Notkia.\n" << std::endl;
}

int	main(void)
{
	PhoneBook	book;
	std::string	instruction;

	book.max_contacts = 0;
	std::cout << "Welcome to Notkia!" << std::endl;
	while (1)
	{
		do_menu();
		std::cin >> instruction;
		if (!check_input(instruction, &book))
			break ;
	}
	return (0);
}