#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Default name", 0, 25, 5)
{
	std::cout << "PresidentialPardonForm Default Constructor" << std::endl;
	this->_target = "DefaultTarget";
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("Default name", 0, 25, 5)
{
	std::cout << "PresidentialPardonForm Parameter Constructor" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj) : AForm(obj)
{
	std::cout << "PresidentialPardonForm Copy Constructor" << std::endl;
	this->_target = obj._target;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm Default Destructor" << std::endl;
}

PresidentialPardonForm const &PresidentialPardonForm::operator=(PresidentialPardonForm const &obj)
{
	std::cout << "PresidentialPardonForm Copy Assignment" << std::endl;
	this->_target = obj._target;
	return (*this);
}

std::ostream  &operator<<(std::ostream &os, PresidentialPardonForm &obj)
{
	os << "-------------------------------" << std::endl;
	os << "AForm name: " << obj.getName() << std::endl;
	os << "Is the AForm signed? ";
	if (obj.getIsSigned() == true)
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;
	std::cout << "Grade Required to Sign: " << obj.getSignGrade() << std::endl;
	std::cout << "Grade Required to Execute: " << obj.getExecGrade() << std::endl;
	os << "-------------------------------";
	return (os);	
}

void	PresidentialPardonForm::do_execute(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

AForm	*PresidentialPardonForm::makeForm(AForm *form, std::string const &name, std::string const &target)
{
	if (!form && !name.compare("PresidentialPardon"))
		return (new PresidentialPardonForm(target));
	return (form);
}