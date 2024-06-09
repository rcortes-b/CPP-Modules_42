#ifndef CURE_HPP
# define CURE_HPP

#include "ICharacter.hpp"

class Cure : public AMateria {
	public:
			Cure( void );
			Cure( Cure const &obj );
			Cure &operator=( Cure &obj );
			~Cure( void );
			virtual AMateria	*clone( void ) const;
			void				use( ICharacter &target );
	private:
};

#endif