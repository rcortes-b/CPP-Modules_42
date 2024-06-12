#include "../includes/ShrubberyCreationForm.hpp"

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Default name", 0, 145, 137)
{
	std::cout << "ShrubberyCreationForm Default Constructor" << std::endl;
	this->_target = "DefaultTarget";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("Default name", 0, 145, 137)
{
	std::cout << "ShrubberyCreationForm Parameter Constructor" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj) : AForm(obj)
{
	std::cout << "ShrubberyCreationForm Copy Constructor" << std::endl;
	this->_target = obj._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Default Destructor" << std::endl;
}

ShrubberyCreationForm const &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj)
{
	std::cout << "ShrubberyCreationForm Copy Assignment" << std::endl;
	this->_target = obj._target;
	return (*this);
}

std::ostream  &operator<<(std::ostream &os, ShrubberyCreationForm &obj)
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

void	ShrubberyCreationForm::do_execute(void) const
{
	std::string	out = this->_target + "_shrubbery";
	std::ofstream outFile(out.c_str());

	outFile <<
	"         v" << std::endl <<
	"        >X<" << std::endl <<
	"         A" << std::endl <<
	"        d$b" << std::endl <<
	"      .d\\$$b." << std::endl <<
	"    .d$i$$\\$$b." << std::endl <<
	"       d$$@b" << std::endl <<
	"      d\\$$$ib" << std::endl <<
	"    .d$$$\\$$$b" << std::endl <<
	"  .d$$@$$$$\\$$ib." << std::endl <<
	"      d$$i$$b" << std::endl <<
	"     d\\$$$$@$b" << std::endl <<
	"  .d$@$$\\$$$$$@b." << std::endl <<
	".d$$$$i$$$\\$$$$$$b." << std::endl <<
	"        ###" << std::endl <<
	"        ###" << std::endl <<
	"        ###" << std::endl << std::endl;

	outFile.close();
}

AForm	*ShrubberyCreationForm::makeForm(AForm *form, std::string const &name, std::string const &target)
{
	if (!form && !name.compare("PresidentialPardon"))
		return (new ShrubberyCreationForm(target));
	return (form);
}
