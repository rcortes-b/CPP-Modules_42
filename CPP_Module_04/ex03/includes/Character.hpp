#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
	public:
			Character( void );
			Character( std::string const &name );
			Character( Character const &obj );
			Character const &operator=( Character const &obj );
			~Character( void );
			std::string const	&getName( void ) const;
			void				setName( std::string const &name);
			virtual void	equip(AMateria* materia);
			virtual void	unequip(int idx);
			virtual void	use(int idx, ICharacter &target);
			bool			is_equiped( AMateria *materia );		
	private:
			AMateria	*_slots[4];
			std::string	_name;
};

#endif