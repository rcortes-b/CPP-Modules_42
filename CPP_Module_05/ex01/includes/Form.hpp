#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
			const std::string	_name;
			bool				_is_signed;
			const int			_sign_grade;
			const int			_exec_grade;
	public:
			//Orthodox Canonical Form
			Form( void );
			Form( Form const &obj );
			Form( std::string name, bool is_signed, int sign_grade, int exec_grade );
			Form const &operator=(Form const &obj );
			~Form( void );

			//Getters
			std::string	getName( void ) const;
			bool		getIsSigned( void ) const;
			int			getSignGrade( void ) const;
			int			getExecGrade( void ) const;

			//Custom Function
			void		beSigned(Bureaucrat &bur);

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

std::ostream  &operator<<(std::ostream &os, Form &obj);

#endif