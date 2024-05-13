#include "class.hpp"

static int	check_input(std::string instruction, PhoneBook *book)
{
	if (instruction.compare("ADD") == 0)
		book->add_contact();
	else if (instruction.compare("SEARCH") == 0)
			book->search();
	else if (instruction.compare("EXIT") == 0)
	{
		std::cout << "Thanks for using Notkia! See you soon." <<std::endl;
		return (0);
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

	
	std::cout << "Welcome to Notkia!" << std::endl;
	book.init_index();
	while (1)
	{
		do_menu();
		std::cin >> instruction;
		if (!check_input(instruction, &book))
			break ;
	}
	return (0);
}