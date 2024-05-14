#include "Zombie.hpp"

 Zombie* Zombie::newZombie( std::string name )
 {
	Zombie	*zmb;

	zmb = new Zombie();
	zmb->name_setter_s(name);
	zmb->announce();
	return (zmb);
 }
