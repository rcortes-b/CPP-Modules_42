#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter Default Constructor" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &obj)
{
	std::cout << "ScalarConverter Copy Constructor" << std::endl;
	(void)obj;
}

ScalarConverter const &ScalarConverter::operator=(ScalarConverter const &obj)
{
	std::cout << "ScalarConverter Copy Assignment" << std::endl;
	(void)obj;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter Default Destructor" << std::endl;
}
