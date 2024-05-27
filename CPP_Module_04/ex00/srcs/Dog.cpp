#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor !" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog &obj) : Animal(obj)
{
	std::cout << "Dog default copy constructor !" << std::endl;
	this->_type = obj._type;
}

Dog &Dog::operator=(Dog &obj)
{
	std::cout << "Dog default copy operator !" << std::endl;
	//if (*this != obj)
		this->_type = obj._type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog default destructor !" << std::endl;
}

void	Dog::makeSound(void)
{
	std::cout << "Woof woof !" << std::endl;
}

std::string	Dog::getType(void)
{
	return (this->_type);
}