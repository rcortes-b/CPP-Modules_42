#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#define DEFAULT_LIMIT 12000
class Span {
	private:
			std::vector<unsigned int>	_container;
			unsigned int				_N;
	public:
			//Ortodox Cannonical Form
			Span( void );
			Span( unsigned int N );
			Span( Span const &obj );
			Span	&operator=( Span const &obj );
			~Span( void );

			//Member Functions
			void				addNumber( unsigned int number );
			unsigned int		shortestSpan( void );
			unsigned int		longestSpan( void );
			void				fillNumbers( void );

			//Function to access the container
			std::vector<unsigned int>	getContainer( void ) const;
			//Exceptions
			class MaxNumbersStored : public std::exception {
				const char	*what( void ) const throw();
			};

			class ShortestException : public std::exception {
				const char	*what( void ) const throw();
			};

			class LongestException : public std::exception {
				const char	*what( void ) const throw();
			};
};

#endif