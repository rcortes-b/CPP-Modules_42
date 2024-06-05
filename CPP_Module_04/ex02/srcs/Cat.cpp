#include "../includes/Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor !" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat &obj) : Animal(obj)
{
	std::cout << "Cat default copy constructor !" << std::endl;
	this->_type = obj._type;
	this->_brain = new Brain();
}

Cat &Cat::operator=(Cat &obj)
{
	std::cout << "Cat default copy operator !" << std::endl;
	//if (*this != obj)
		this->_type = obj._type;
		this->_brain = new Brain();
	return (*this);
}

Cat::~Cat(void)
{
	delete this->_brain;
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

void	Cat::setType(std::string type)
{
	this->_type = type;
}

Brain	*Cat::getBrain(void)
{
	return (this->_brain);
}
