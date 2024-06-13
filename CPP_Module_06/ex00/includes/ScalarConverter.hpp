#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	private:
	public:
			//Ortodoxal Cannonical Form
			ScalarConverter( void );
			ScalarConverter ( ScalarConverter const &obj );
			ScalarConverter const &operator=( ScalarConverter const &obj );
			~ScalarConverter( void );

			//Convert Function
			virtual void	convertType( std::string &type ) = 0;
};

#endif