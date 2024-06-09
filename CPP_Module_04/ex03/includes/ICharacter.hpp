#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include "AMateria.hpp"

class ICharacter {
	public:

			virtual std::string const &getName( void ) const = 0;
			virtual ~ICharacter( void ) {};
			virtual void equip(AMateria* materia) = 0;
			virtual void unequip(int idx) = 0;
			virtual void use(int idx, ICharacter& target) = 0;
	protected:
			ICharacter( void );
			ICharacter( ICharacter const &obj );
			ICharacter const &operator=( ICharacter const &obj );
};

#endif