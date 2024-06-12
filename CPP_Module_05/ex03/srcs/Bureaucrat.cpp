#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("DefaultName")
{
	std::cout << "Bureaucrat Default Constructor" << std::endl;
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat Custom Constructor" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) : _name(obj._name)
{
	std::cout << "Bureaucrat Copy Constructor" << std::endl;
	*this = obj;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Default Destructor" << std::endl;
}

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &obj)
{
	std::cout << "Bureaucrat Assignment Operator" << std::endl;
	this->_grade = obj._grade;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

std::string	Bureaucrat::getName(void)
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

/*Si no recibe la referencia, cada vez que se llame
a la funcion se crea y se destruye la instancia de Form*/
void	Bureaucrat::signForm(AForm &paper)
{
	if (paper.getIsSigned() == true)
		std::cout << this->getName() << " signed " << paper.getName() << std::endl;
	else
	{
		std::cout << this->getName() << " couldn't sign " << paper.getName();
		std::cout << " because was so high" << std::endl;
	}
}


void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}

void	Bureaucrat::increment_grade(void)
{
	if (this->getGrade() - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = this->getGrade() - 1;
}

void	Bureaucrat::decrement_grade(void)
{
	if (this->getGrade() + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = this->getGrade() + 1;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat Error: Grade is too high !");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat Error: Grade is too low !");
}