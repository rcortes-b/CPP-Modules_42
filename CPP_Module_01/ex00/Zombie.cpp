#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Constructor for Zombie called " << this->_name << std::endl;
}

void	Zombie::name_setter_s(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destructor for Zombie called " << this->_name << std::endl;
}