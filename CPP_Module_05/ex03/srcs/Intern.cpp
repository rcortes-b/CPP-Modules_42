#include "../includes/Intern.hpp"

/*
			//Custom Function
			AForm	*makeForm( std::string name, std::string target );

			//Exception
			class FormDoesNotExists : public std::exception {
				public:
						virtual const char* what() const throw();*/

Intern::Intern(void)
{
	std::cout << "Intern Default Constructor" << std::endl;
}

Intern::Intern(Intern const &obj)
{
	std::cout << "Intern Copy Constructor" << std::endl;
	(void)obj;
}

Intern const &Intern::operator=(Intern const &obj)
{
	std::cout << "Intern Copy Assignation" << std::endl;
	(void)obj;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern Default Destructor" << std::endl;
}

const char	*Intern::FormDoesNotExist::what(void) const throw()
{
	return ("Form does not exist !");
}

AForm	*Intern::makeForm(std::string const &name, std::string const &target)
{
	AForm	*form;

	form = AForm::makeForm(name, target);
	if (!form)
		throw Intern::FormDoesNotExist();
	std::cout << "Intern has created " << form->getName() << std::endl;
	return (form);
}