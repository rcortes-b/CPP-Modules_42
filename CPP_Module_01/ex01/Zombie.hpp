#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <stdbool.h>

class Zombie
{
	public :
			Zombie();
			static Zombie* zombieHorde( int N, std::string name );
			void	announce(void);
			void	name_setter(std::string name);
			~Zombie();

	private :
			std::string	_name;

};

#endif