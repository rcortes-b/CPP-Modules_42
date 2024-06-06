#include "../includes/Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Default Cure constructor has been called !" << std::endl;
	this->_type = "cure";
}

Cure::Cure(Cure const &obj) : AMateria(obj)
{
	std::cout << "Default Cure copy constructor" << std::endl;
	this->_type = obj._type;
}

Cure	&Cure::operator=(Cure &obj)
{
	//if (*this != obj)
		this->_type = obj._type;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "Default Cure destructor has been called !" << std::endl;
}

AMateria	*Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals ";
	std::cout << target.getName();
	std::cout << "'s wound *" << std::endl;
}