#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdbool.h>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		std::string	const _name;
		int			_grade;
	public:
			//Orthodox Canonical Form
			Bureaucrat( void );
			Bureaucrat( std::string name , int grade );
			Bureaucrat( Bureaucrat const &obj );
			Bureaucrat const &operator=( Bureaucrat const &obj);
			~Bureaucrat( void );

			//Getters
			std::string	getName( void );
			int			getGrade( void );

			//Increment && Decrement
			void	increment_grade( void );
			void	decrement_grade( void );
			
			//Custom Function
			void	signForm( Form &paper );

			//Exception classes
			class GradeTooHighException : public std::exception {
				public:
					virtual const char* what() const throw();
			};
			class GradeTooLowException : public std::exception {
				public:
					virtual const char* what() const throw();
			};
};

std::ostream  &operator<<(std::ostream &os, Bureaucrat &obj);

#endif