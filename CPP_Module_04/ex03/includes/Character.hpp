#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
	public:
			Character( void );
			Character( Character const &obj );
			Character &operator=( Character const &obj );
			~Character( void );
			std::string const	&getName( void ) const;
	private:
			AMateria	*_slots[4];
};

#endif