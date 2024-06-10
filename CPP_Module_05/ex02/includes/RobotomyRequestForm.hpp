#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
			std::string	_target;
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string &target );
		RobotomyRequestForm( RobotomyRequestForm const &obj);
		~RobotomyRequestForm( void );
};

#endif