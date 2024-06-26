#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
			std::string	_target;
	public:
		//Orthodox Canonical Form
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string &target );
		PresidentialPardonForm( PresidentialPardonForm const &obj);
		PresidentialPardonForm const &operator=( PresidentialPardonForm const &obj);
		~PresidentialPardonForm( void );

		//Execute Function
		virtual void	do_execute( void ) const;
};

std::ostream  &operator<<(std::ostream &os, PresidentialPardonForm &obj);

#endif