#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include "ScalarConverter.hpp"

enum	e_types
{
	CHAR = 1,
	INT,
	FLOAT,
	DOUBLE
};

enum	err_types
{
	NAN = 1,
	MINUS_INF,
	PLUS_INF
};

class Converter : public ScalarConverter {
	private:
			//Utilities
			std::string		_input;
			std::string		_strType;
			unsigned int	_type;
			unsigned int	_err_type;

			//Variable types
			char	_cType;
			int		_iType;
			float	_fType;
			double	_dType;

	public:
			//Ortodoxal Cannonical Form
			Converter( void );
			Converter( std::string &input );
			Converter( Converter const &obj );
			Converter const &operator=( Converter const &obj );
			~Converter( void );

			//Setters && Getters
			std::string		getInput( void );
			std::string		& getStrType( void );
			unsigned int	getType( void );
			unsigned int	getErrType( void );

			//Checker Function
			void			check_input( std::string &input);
			unsigned int	check_char( std::string &input );
			unsigned int	check_int( std::string &input );
			unsigned int	check_float( std::string &input );
			unsigned int	check_double( std::string &input );

			//Convert Functions
			virtual void	convertType( std::string &type );
			void			doChar( void );
			void			doInt( void );
			void			doFloat( void );
			void			doDouble( void );
			void			printValues( void );

			//Error Handler
			void	handle_error( void );

			//Exceptions
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