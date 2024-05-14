#include "Zombie.hpp"

int main(void)
{
	Zombie	*zmb;

	zmb = NULL;
	zmb = Zombie::zombieHorde(5, "Paco");
	delete [] zmb;
}