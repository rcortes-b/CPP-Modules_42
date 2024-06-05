#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor !" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog &obj) : Animal(obj)
{
	std::cout << "Dog default copy constructor !" << std::endl;
	this->_type = obj._type;
	this->_brain = new Brain();
}

Dog &Dog::operator=(Dog &obj)
{
	std::cout << "Dog default copy operator !" << std::endl;
	//if (*this != obj)
		this->_type = obj._type;
		this->_brain = new Brain();
	return (*this);
}

Dog::~Dog(void)
{
	delete this->_brain;
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

void	Dog::setType(std::string type)
{
	this->_type = type;
}

Brain	*Dog::getBrain(void)
{
	return (this->_brain);
}
