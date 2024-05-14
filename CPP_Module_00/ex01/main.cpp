#include "PhoneBook.hpp"

static int	check_input(std::string instruction, PhoneBook *book)
{
	if (instruction.compare("ADD") == 0)
	{
		if (!book->add_contact())
		{
			std::cout << std::endl;
			return (book->exit_msg(), 0);
		}
	}
	else if (instruction.compare("SEARCH") == 0)
	{
		if (!book->search())
		{
			std::cout << std::endl;
			return (book->exit_msg(), 0);
		}
	}	
	else if (instruction.compare("EXIT") == 0)
	{
		book->exit_msg();
		return (0);
	}
	else
		std::cout << "\nThe instruction is incorrect. Please, type it again.\n" << std::endl;
	return (1);
}

static void	do_menu(void)
{
	std::cout << "\n\033[1;34mChoose an option:\033[0m\n" << std::endl;
	std::cout << "1- Type \"\033[1;34mADD\033[0m\" to save a contact." << std::endl;
	std::cout << "2- Type \"\033[1;34mSEARCH\033[0m\" to display the contacts." << std::endl;
	std::cout << "3- Type \"\033[1;34mEXIT\033[0m\" to leave from Notkia.\n" << std::endl;
}

int	main(void)
{
	PhoneBook	book;
	std::string	instruction;

	std::cout << "\n-----------------------------------------------" << std::endl;
	std::cout << "\n              ";
	std::cout << "\033[1;30mWelcome to Notkia!\033[0m\n" << std::endl;
	book.init_index();
	while (1)
	{
		std::cout << "-----------------------------------------------" << std::endl;
		do_menu();
		std::cout << "\033[1;34mnotkia>\033[0m ";
		std::getline(std::cin, instruction);
		if (!instruction[0])
		{
			std::cout << std::endl;
			book.exit_msg();
			break ;
		}
		if (!check_input(instruction, &book))
			break ;
	}
	return (0);
}