#include "includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Only one argument is valid."<< std::endl;
		return (1);
	}

	std::string arg = argv[1];
	ScalarConverter::convert(arg);
	
	return (0);
}
