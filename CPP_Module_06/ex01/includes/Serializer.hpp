#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct s_Data
{
	int		garbage;
	char	c;
}	t_Data;

class Serializer {
	private:
			//Orthodox Canonical Form
			Serializer( void );
			Serializer( Serializer const &obj );
			Serializer const &operator=( Serializer const &obj );
			~Serializer( void );
	public:

			//Serializer Functions
			static uintptr_t	serialize(t_Data* ptr);
			static t_Data*		deserialize(uintptr_t raw);
};

#endif