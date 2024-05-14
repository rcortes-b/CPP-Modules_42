#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_wpon.getType() << std::endl;
}

/* La razon por la que HumanA tiene una referencia a weapon es porque siempre va a ser inicializado con una weapon por lo tanto,
se puede inicializar directamente en el constructor (las referencias siempre han de ser inicializadas en su desclaracion) */

HumanA::HumanA(std::string name, Weapon &wpon) : _wpon(wpon)
{
	std::cout << "Constructor of HumanA !" << std::endl;
	this->_name = name;
}

HumanA::~HumanA()
{
	std::cout << "Destructor of HumanA !" << std::endl;
}
