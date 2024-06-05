#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	public:
			Cat( void );
			Cat(Cat &obj);
			Cat &operator=(Cat &obj);
			~Cat ( void );
			void		makeSound( void );
			std::string	getType( void );
			void		setType( std::string type );
			Brain	*getBrain( void );
	private:
			Brain	*_brain;
};


#endif