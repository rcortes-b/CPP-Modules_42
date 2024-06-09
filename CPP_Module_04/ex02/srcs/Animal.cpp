#include "../includes/Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor !" << std::endl;
	this->_type = "DefaultAnimal";
}

Animal::Animal(Animal &obj)
{
	std::cout << "Animal default copy constructor !" << std::endl;
	this->_type = obj._type;
}

Animal &Animal::operator=(Animal &obj)
{
	std::cout << "Animal default copy operator !" << std::endl;
	//if (*this != obj)
		this->_type = obj._type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal default destructor !" << std::endl;
}

std::string	Animal::getType(void)
{
	return (this->_type);
}
