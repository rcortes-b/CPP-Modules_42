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
		ShrubberyCreationForm( std::string const &target );
		ShrubberyCreationForm( ShrubberyCreationForm const &obj);
		ShrubberyCreationForm const &operator=( ShrubberyCreationForm const &obj);
		~ShrubberyCreationForm( void );

		//Execute Function
		virtual void	do_execute( void ) const;
		static AForm	*makeForm(AForm *form, std::string const &name, std::string const &target);
};

std::ostream  &operator<<(std::ostream &os, ShrubberyCreationForm &obj);

#endif