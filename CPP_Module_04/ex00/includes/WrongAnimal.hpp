#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	public:
			WrongAnimal( void );
			WrongAnimal(WrongAnimal &obj);
			WrongAnimal &operator=(WrongAnimal &obj);
			~WrongAnimal ( void );
			void		makeSound( void );
			std::string	getType( void );
	protected:
			std::string	_type;
};

#endif