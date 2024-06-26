#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
			std::string	_target;
	public:
		//Orthodox Canonical Form
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string &target );
		ShrubberyCreationForm( ShrubberyCreationForm const &obj);
		ShrubberyCreationForm const &operator=( ShrubberyCreationForm const &obj);
		~ShrubberyCreationForm( void );

		//Execute Function
		virtual void	do_execute( void ) const;
};

std::ostream  &operator<<(std::ostream &os, ShrubberyCreationForm &obj);

#endif