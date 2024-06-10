#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
			std::string	_target;
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string &target );
		PresidentialPardonForm( PresidentialPardonForm const &obj);
		~PresidentialPardonForm( void );
};

#endif