#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class AForm;

class Intern {
	private:
	public:
			//Orthodox Canonical AForm
			Intern( void );
			Intern( Intern const &obj );
			Intern const &operator=( Intern const &obj );
			~Intern( void );
			//Custom Function
			AForm	*makeForm( std::string const &name, std::string const &target );

			//Exception
			class FormDoesNotExist : public std::exception {
				public:
						virtual const char* what() const throw();
			};
};

#endif
