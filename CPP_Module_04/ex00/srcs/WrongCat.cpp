#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat default constructor !" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << "WrongCat default copy constructor !" << std::endl;
	this->_type = obj._type;
}

WrongCat &WrongCat::operator=(WrongCat &obj)
{
	std::cout << "WrongCat default copy operator !" << std::endl;
	//if (*this != obj)
		this->_type = obj._type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat default destructor !" << std::endl;
}

void	WrongCat::makeSound(void)
{
	std::cout << "Wrong Miau !" << std::endl;
}

std::string	WrongCat::getType(void)
{
	return (this->_type);
}