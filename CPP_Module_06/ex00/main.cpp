#include "includes/Converter.hpp"

int main(int argc, char **argv) /*El main va a ser un try && catch*/
{
	if (argc != 2)
	{
		std::cerr << "Error: Only one argument is valid."<< std::endl;
		return (1);
	}
	std::string arg = argv[1];
	Converter input(arg);
	std::cout << std::endl;
	try {
		input.check_input(arg);
		std::cout << "\nType is: " << input.getStrType() << std::endl << std::endl;
		input.handle_error();
		input.convertType(input.getStrType());
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}