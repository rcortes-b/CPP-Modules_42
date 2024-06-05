#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria {
	public:
			AMateria( std::string const &type);

			std::string const &getType( void ) const;

			virtual AMateria	*clone( void ) const = 0;
			virtual void		use(ICharaacter &target);
	protected:
				std::string const	&type;
};

#endif