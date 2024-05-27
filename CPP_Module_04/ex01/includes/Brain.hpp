#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	public:
			Brain( void );
			Brain(Brain &obj);
			Brain &operator=(Brain &obj);
			~Brain( void );
			std::string	getIdea( int n );
			void		setIdea( std::string idea, int n );
	private:
			std::string	_ideas[100];
};

#endif