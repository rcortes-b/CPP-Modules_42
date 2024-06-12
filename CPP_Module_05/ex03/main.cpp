#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/Intern.hpp"

int	main()
{
	Bureaucrat	thiery = Bureaucrat("Thiery", 3);
	AForm	*f = new  PresidentialPardonForm();
	std::cout << thiery << std::endl;
	thiery.signForm(*f);
	(*f).beSigned(thiery);
	thiery.signForm(*f);
	std::cout << f << std::endl;
	try
	{
		for (int cur = 0; cur < 3; cur++)
		{
			thiery.increment_grade();
			std::cout << "\t" << thiery << std::endl;
		}
	}
	/*Este catch solo maneja excepciones del tipo GradeTooHighException **Solo se activa uno de los dos catch***/
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "\t" << e.what() << std::endl;
	}
	/*Este catch maneja todas las excepciones definidas y sus derivados **Solo se activa uno de los dos catch***/
	catch (std::exception &e)
	{
		std::cout << "\t" << "Problem catched..." << std::endl;
	}

	Bureaucrat	thiery_copy = thiery;
	std::cout << thiery_copy << std::endl;

	Bureaucrat	sophie = Bureaucrat("Sophie", 150);
	std::cout << sophie << std::endl;
	try
	{
		sophie.decrement_grade();
	}
	catch (std::exception &e)
	{
		std::cout << "\t" << e.what() << std::endl;
	}
	/*Si inicializo lou a 151 salta todo el 'try' y va directo a 'catch'*/
	/*Si inicializo lou a 150 hace todo el 'try' y no pasa por 'catch'*/
	try
	{
		Bureaucrat	lou = Bureaucrat("Lou", 151);
		std::cout << "HOLA PASA POR AQUI?" << std::endl;
		std::cout << lou << std::endl;
	}
	catch (std::exception &elnombrequesea)
	{
		/*El error msg sale de aqui, del .what*/
		std::cout << elnombrequesea.what() << std::endl;
		std::cout << "HOLA PASA POR AQUI? v2" << std::endl;
	}

	Intern	a;
	AForm	*b = a.makeForm("RobotomyRequest", "Bob");
	delete b;
	return 0;
}
