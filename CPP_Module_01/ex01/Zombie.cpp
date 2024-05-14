#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie default constructor" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie default destructor" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::name_setter(std::string name)
{
	this->_name = name;
}
