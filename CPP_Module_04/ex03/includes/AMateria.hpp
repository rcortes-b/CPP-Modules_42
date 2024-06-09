#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <stdbool.h>

class ICharacter;

class AMateria {
	public:
			AMateria &operator=( AMateria &obj );
			std::string const &getType( void ) const;
			virtual AMateria	*clone( void ) const = 0;
			virtual void		use(ICharacter &target) = 0;
			virtual ~AMateria( void );
	protected:
				AMateria( void );
				AMateria( std::string const &type);
				AMateria( AMateria const &obj );
				std::string _type;
};

#endif 