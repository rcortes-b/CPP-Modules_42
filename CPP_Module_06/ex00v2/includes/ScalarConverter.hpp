#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>

enum e_type {
	e_DEFAULT,
	e_CHAR,
	e_INT,
	e_FLOAT,
	e_DOUBLE
};

enum	err_types
{
	ERR_DEFAULT,
	NAN,
	MINUS_INF,
	PLUS_INF
};

class ScalarConverter {
	private:
			//Variables
			static std::string		_input;
			static unsigned int		_err_type;
			static unsigned int		_type;
			static char				_toChar;
			static int				_toInt;
			static float			_toFloat;
			static double			_toDouble;
			//Checker
			static void			check_input( std::string &input);
			static unsigned int	check_char( std::string &input );
			static unsigned int	check_int( std::string &input );
			static unsigned int	check_float( std::string &input );
			static unsigned int	check_double( std::string &input );

			static void			doChar( void );
			static void			doInt( void );
			static void			doFloat( void );
			static void			doDouble( void );
			static void			printValues( void );

			//Handle Error
			static void			handle_error( void );
			//Ortodoxal Cannonical Form
			ScalarConverter( void );
			ScalarConverter ( ScalarConverter const &obj );
			ScalarConverter const &operator=( ScalarConverter const &obj );
			~ScalarConverter( void );

	public:
			//Convert Function
			static void	convert( std::string input );

			class	DefaultException: public std::exception {
				public:
						virtual const char* what( void ) const throw();
			};
			
			class NaNException : public std::exception {
				public:
						virtual const char* what( void ) const throw();
			};

			class MinusInfException : public std::exception {
				public:
						virtual const char* what( void ) const throw();
			};

			class PlusInfException : public std::exception {
				public:
						virtual const char* what( void ) const throw();
			};
};

#endif