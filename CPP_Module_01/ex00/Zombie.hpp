#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <stdbool.h>

class Zombie
{
	public :
			Zombie();
			void	name_setter_s(std::string name);
			void	announce(void);
			static  Zombie*	newZombie( std::string name );
			void	randomChump( std::string name );
			~Zombie();

	private :
			std::string	_name;

};

#endif