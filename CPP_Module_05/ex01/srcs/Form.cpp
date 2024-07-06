#include "../includes/Form.hpp"

Form::Form(void) : _name("DefaultName"), _sign_grade (50), _exec_grade(50)
{
	std::cout << "Form Default Constructor" << std::endl;
	this->_is_signed = false;
}

Form::Form(std::string name, bool is_signed, int sign_grade, int exec_grade) \
: _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form Custom Constructor" << std::endl;
	this->_is_signed = is_signed;
}

Form::Form(Form const &obj) : _name(obj._name), _sign_grade(obj._sign_grade), _exec_grade(obj._exec_grade)
{
	std::cout << "Form Copy Constructor" << std::endl;
	*this = obj;
}

Form::~Form(void)
{
	std::cout << "Form Default Destructor" << std::endl;
}

Form const &Form::operator=(Form const &obj)
{
	std::cout << "Form Assignment Operator" << std::endl;
	this->_is_signed = obj._is_signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Form &obj)
{
	os << "-------------------------------" << std::endl;
	os << "Form name: " << obj.getName() << std::endl;
	os << "Is the form signed? ";
	if (obj.getIsSigned() == true)
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;
	std::cout << "Grade Required to Sign: " << obj.getSignGrade() << std::endl;
	std::cout << "Grade Required to Execute: " << obj.getExecGrade() << std::endl;
	os << "-------------------------------";
	return (os);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_is_signed);
}

int	Form::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade(void) const
{
	return (this->_exec_grade);
}

void	Form::beSigned(Bureaucrat &bur)
{
	if (this->getSignGrade() < 1)
		throw Form::GradeTooHighException();
	else if (this->getSignGrade() > 150)
		throw Form::GradeTooLowException();
	if (bur.getGrade() <= this->getSignGrade())
		this->_is_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Form Error: Grade is too high !");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Form Error: Grade is too low !");
}