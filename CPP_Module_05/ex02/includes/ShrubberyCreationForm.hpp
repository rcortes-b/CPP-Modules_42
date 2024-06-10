#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
			std::string	_target;
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string &target );
		ShrubberyCreationForm( ShrubberyCreationForm const &obj);
		~ShrubberyCreationForm( void );
};

#endif