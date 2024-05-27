#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {
	public:
			Animal( void );
			Animal(Animal &obj);
			Animal &operator=(Animal &obj);
			virtual ~Animal ( void );
			virtual void	makeSound( void );
			std::string		getType( void );
			virtual Brain	*getBrain( void ) = 0;
	protected:
			std::string	_type;
};


#endif