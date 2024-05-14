#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	Zombie	*zmb;

	zmb = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zmb[i].name_setter(name);
		zmb[i].announce();
	}
	return (zmb);
}