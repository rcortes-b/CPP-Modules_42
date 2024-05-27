#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal default constructor !" << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal &obj)
{
	std::cout << "WrongAnimal default copy constructor !" << std::endl;
	this->_type = obj._type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &obj)
{
	std::cout << "WrongAnimal default copy operator !" << std::endl;
	//if (*this != obj)
		this->_type = obj._type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal default destructor !" << std::endl;
}

void	WrongAnimal::makeSound(void)
{
	std::cout << "Wrong Default Animal Sound !" << std::endl;
}

std::string	WrongAnimal::getType(void)
{
	return (this->_type);
}