#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

AForm::AForm(void) : _name("DefaultName"), _sign_grade (50), _exec_grade(50)
{
	std::cout << "AForm Default Constructor" << std::endl;
	this->_is_signed = false;
}

AForm::AForm(std::string name, bool is_signed, int sign_grade, int exec_grade) \
: _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "AForm Custom Constructor" << std::endl;
	this->_is_signed = is_signed;
}

AForm::AForm(AForm const &obj) : _name(obj._name), _sign_grade(obj._sign_grade), _exec_grade(obj._exec_grade)
{
	std::cout << "AForm Copy Constructor" << std::endl;
	*this = obj;
}

AForm::~AForm(void)
{
	std::cout << "AForm Default Destructor" << std::endl;
}

AForm const &AForm::operator=(AForm const &obj)
{
	std::cout << "AForm Assignment Operator" << std::endl;
	this->_is_signed = obj._is_signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, AForm &obj)
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

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void)
{
	return (this->_is_signed);
}

int	AForm::getSignGrade(void)
{
	return (this->_sign_grade);
}

int	AForm::getExecGrade(void)
{
	return (this->_exec_grade);
}

void	AForm::beSigned(Bureaucrat &bur)
{
	if (this->getSignGrade() < 1)
		throw AForm::GradeTooHighException();
	else if (this->getSignGrade() > 150)
		throw AForm::GradeTooLowException();
	if (bur.getGrade() >= this->getSignGrade())
		this->_is_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (this->_is_signed == 0)
		throw AForm::FormIsNotSigned();
	else if (this->_sign_grade < executor.getGrade())
		throw AForm::GradeTooLowException();
	this->do_execute();
}

AForm	*AForm::makeForm(std::string const &name, std::string const &target)
{
	AForm	*form = NULL;

	form = PresidentialPardonForm::makeForm(form, name, target);
	form = RobotomyRequestForm::makeForm(form, name, target);
	form = ShrubberyCreationForm::makeForm(form, name, target);
	return (form);
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm Error: Grade is too high !");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm Error: Grade is too low !");
}

const char	*AForm::FormIsNotSigned::what(void) const throw()
{
	return ("AForm Error: The form is not signed !");
}