#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:

			//Variables
			const std::string	_name;
			bool				_is_signed;
			const int			_sign_grade;
			const int			_exec_grade;
	public:
			//Orthodox Canonical AForm
			AForm( void );
			AForm( AForm const &obj );
			AForm( std::string name, bool is_signed, int sign_grade, int exec_grade );
			AForm const &operator=(AForm const &obj );
			virtual ~AForm( void );

			//Getters
			std::string	getName( void ) const;
			bool		getIsSigned( void );
			int			getSignGrade( void );
			int			getExecGrade( void );

			//Custom Function
			void			beSigned(Bureaucrat &bur);
			void			execute( Bureaucrat const &executor ) const;
			virtual void	do_execute( void ) const = 0;
			static AForm	*makeForm( std::string const &name, std::string const &target);

			//Exception classes
			class GradeTooHighException : public std::exception {
				public:
					virtual const char* what() const throw();
			};
			class GradeTooLowException : public std::exception {
				public:
					virtual const char* what() const throw();
			};
			class FormIsNotSigned : public std::exception {
				public:
					virtual const char* what() const throw();
			};
};

std::ostream  &operator<<(std::ostream &os, AForm &obj);

#endif