#include "Weapon.hpp"

const std::string&	Weapon::getType() const
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

Weapon::Weapon(std::string type)
{
	std::cout << "Constructor of Weapon !" << std::endl;
	this->setType(type);
}

Weapon::~Weapon()
{
	std::cout << "Destructor of Weapon !" << std::endl;
}
