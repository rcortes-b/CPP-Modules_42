#include "../includes/ICharacter.hpp"

ICharacter::ICharacter(void)
{
	std::cout << "ICharacter Default Constructor" << std::endl;
}

ICharacter::ICharacter(ICharacter const &obj)
{
	std::cout << "ICharacter Copy Constructor" << std::endl;
	*this = obj;
}

ICharacter const &ICharacter::operator=(ICharacter const &obj)
{
	std::cout << "ICharacter Copy Assignment Operator" << std::endl;
	(void)obj;
	return (*this);
}
