#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	public:
			Dog( void );
			Dog(Dog &obj);
			Dog &operator=(Dog &obj);
			~Dog ( void );
			void		makeSound( void );
			std::string	getType( void );
			void		setType( std::string type );
			Brain	*getBrain( void );
	private:
			Brain	*_brain;
};


#endif