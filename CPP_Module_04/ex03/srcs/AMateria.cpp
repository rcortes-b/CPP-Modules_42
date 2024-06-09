#include "../includes/AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "Default AMateria constructor" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
	std::cout << "Default AMateria param constructor" << std::endl;
}

AMateria::AMateria(AMateria const &obj)
{
	this->_type = obj._type;
	std::cout << "Default AMateria copy constructor" << std::endl;
}

AMateria &AMateria::operator=(AMateria &obj)
{
	//if (*this != obj)
		this->_type = obj._type;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "Default AMateria destructor has been called !" << std::endl;
}

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

