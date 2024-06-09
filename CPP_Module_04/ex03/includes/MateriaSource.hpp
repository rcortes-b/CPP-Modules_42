#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	public:
			MateriaSource( void );
			MateriaSource( MateriaSource const &obj );
			MateriaSource const &operator=( MateriaSource const &obj );
			~MateriaSource( void );
			virtual void		learnMateria( AMateria* materia );
			virtual AMateria*	createMateria(std::string const &type);
			bool				do_exists(AMateria *materia);
	private:
			AMateria	*_materia_slots[4];
};

#endif