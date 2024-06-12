#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <stdlib.h>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
			std::string	_target;
	public:
		//Orthodox Canonical Form
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string const &target );
		RobotomyRequestForm( RobotomyRequestForm const &obj);
		RobotomyRequestForm const &operator=( RobotomyRequestForm const &obj);
		~RobotomyRequestForm( void );

		//Execute Function
		virtual void	do_execute( void ) const;
		static AForm	*makeForm(AForm *form, std::string const &name, std::string const &target);
};

std::ostream  &operator<<(std::ostream &os, RobotomyRequestForm &obj);

#endif