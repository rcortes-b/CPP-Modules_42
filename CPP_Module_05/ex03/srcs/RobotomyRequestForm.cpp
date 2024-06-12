#include "../includes/RobotomyRequestForm.hpp"

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Default name", 0, 72, 45)
{
	std::cout << "RobotomyRequestForm Default Constructor" << std::endl;
	this->_target = "DefaultTarget";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("Default name", 0, 72, 45)
{
	std::cout << "RobotomyRequestForm Parameter Constructor" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj) : AForm(obj)
{
	std::cout << "RobotomyRequestForm Copy Constructor" << std::endl;
	this->_target = obj._target;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm Default Destructor" << std::endl;
}

RobotomyRequestForm const &RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
	std::cout << "RobotomyRequestForm Copy Assignment" << std::endl;
	this->_target = obj._target;
	return (*this);
}

std::ostream  &operator<<(std::ostream &os, RobotomyRequestForm &obj)
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

void	RobotomyRequestForm::do_execute(void) const
{
	int	odds = 0;

	srand((unsigned) time(NULL));
	odds = rand() % 2;
	if (odds)
	{
		std::cout << "BsssssSSSSSS! " << this->_target;
		std::cout << " has been robotomized successfully." << std::endl;
	}
	else
		std::cout << "Robotomy has failed." << std::endl;
}

AForm	*RobotomyRequestForm::makeForm(AForm *form, std::string const &name, std::string const &target)
{
	if (!form && !name.compare("RobotomyRequest"))
		return (new RobotomyRequestForm(target));
	return (form);
}
