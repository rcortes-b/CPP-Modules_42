#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {
	public:
			Animal &operator=(Animal &obj);
			virtual ~Animal ( void );
			virtual void	makeSound( void ) = 0;
			std::string		getType( void );
			virtual Brain	*getBrain( void ) = 0;
	protected:
			Animal( void );
			Animal(Animal &obj);
			std::string	_type;
};


#endif