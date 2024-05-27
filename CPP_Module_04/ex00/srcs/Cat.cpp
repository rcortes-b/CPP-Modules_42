#include "../includes/Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor !" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat &obj) : Animal(obj)
{
	std::cout << "Cat default copy constructor !" << std::endl;
	this->_type = obj._type;
}

Cat &Cat::operator=(Cat &obj)
{
	std::cout << "Cat default copy operator !" << std::endl;
	//if (*this != obj)
		this->_type = obj._type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat default destructor !" << std::endl;
}

void	Cat::makeSound(void)
{
	std::cout << "Miau !" << std::endl;
}

std::string	Cat::getType(void)
{
	return (this->_type);
}