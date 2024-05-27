#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
			Dog( void );
			Dog(Dog &obj);
			Dog &operator=(Dog &obj);
			~Dog ( void );
			void		makeSound( void );
			std::string	getType( void );
};


#endif