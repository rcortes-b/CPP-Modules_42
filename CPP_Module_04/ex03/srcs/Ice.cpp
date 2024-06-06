#include "../includes/Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Default Ice constructor has been called !" << std::endl;
	this->_type = "ice";
}

Ice::Ice(Ice const &obj) : AMateria(obj)
{
	std::cout << "Default Ice copy constructor" << std::endl;
	this->_type = obj._type;
}

Ice	&Ice::operator=(Ice &obj)
{
	//if (*this != obj)
		this->_type = obj._type;
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "Default Ice destructor has been called !" << std::endl;	
}

AMateria	*Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at ";
	std::cout << target.getName();
	std::cout << " *" << std::endl;
}
