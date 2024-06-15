#include "../includes/Converter.hpp"

Converter::Converter(void) : ScalarConverter()
{
	std::cout << "Converter Default Constructor" << std::endl;
	this->_input = "DefaultInput";
	this->_strType = "";
	this->_type = 0;
	this->_err_type = 0;
	this->_cType = 0;
	this->_iType = 0;
	this->_fType = 0.0f;
	this->_dType = 0.0;
}

Converter::Converter(std::string &input) : ScalarConverter()
{
	std::cout << "Converter Custom Constructor" << std::endl;
	this->_input = input;
	this->_strType = "";
	this->_type = 0;
	this->_err_type = 0;
	this->_cType = 0;
	this->_iType = 0;
	this->_fType = 0.0f;
	this->_dType = 0.0;
}

Converter::Converter( Converter const &obj ) : ScalarConverter(obj)
{
	std::cout << "Converter Copy Constructor" << std::endl;
	this->_input = obj._input;
	this->_strType = obj._strType;
	this->_type = obj._type;
	this->_err_type = obj._err_type;
	this->_cType = obj._cType;
	this->_iType = obj._iType;
	this->_fType = obj._fType;
	this->_dType = obj._dType;
}

Converter const &Converter::operator=(Converter const &obj)
{
	std::cout << "Converter Copy Assignment" << std::endl;
	this->_input = obj._input;
	this->_strType = obj._strType;
	this->_type = obj._type;
	this->_err_type = obj._err_type;
	this->_cType = obj._cType;
	this->_iType = obj._iType;
	this->_fType = obj._fType;
	this->_dType = obj._dType;
	return (*this);
}

Converter::~Converter(void)
{
	std::cout << "Converter Default Destructor" << std::endl;
}

std::string	Converter::getInput(void)
{
	return (this->_input);
}

std::string	&Converter::getStrType(void)
{
	return (this->_strType);
}

unsigned int	Converter::getType( void )
{
	return (this->_type);
}

unsigned int	Converter::getErrType( void )
{
	return (this->_err_type);
}

void	Converter::check_input(std::string &input)
{
	if (!input.compare("nan") || !input.compare("nanf"))
		this->_err_type = NAN;
	else if (!input.compare("-inf") || !input.compare("-inff"))
		this->_err_type = MINUS_INF;
	else if (!input.compare("+inf") || !input.compare("+inff"))
		this->_err_type = PLUS_INF;
	else
	{
		this->_type = this->check_char(input);
		this->_type = this->check_int(input);
		this->_type = this->check_float(input);
		this->_type = this->check_double(input);
	}
	if (!this->_err_type && !this->_type)
		throw Converter::DefaultException();
}

unsigned int	Converter::check_char(std::string &input)
{
	if (input.size() != 1)
		return (this->_type);
	else if ((input[0] < 32 || input[0] > 126)
			|| (input[0] >= '0' && input[0] <= '9'))
		return (this->_strType = "int", INT);
	else
		return (this->_strType = "char", CHAR);
}

unsigned int	Converter::check_int(std::string &input)
{
	if (this->_type != 0)
		return (this->_type);
	for (int i = 0; input[i]; i++)
	{
		if (i == 0 && input[i] == '-')
			continue ;
		else if (input[i] < 48 || input[i] > 57)
			return (this->_type);
	}
	return (this->_strType = "int", INT);
}

unsigned int	Converter::check_float(std::string &input)
{
	size_t	dot_counter = 0;

	if (this->_type != 0)
		return (this->_type);
	for (size_t i = 0; input[i]; i++)
	{
		if (i == 0 && input[i] == '-')
			continue ;
		else if (i > 0 && input[i] == '.')
			dot_counter++;
		else if (input.size() == i + 1 && input[i] == 'f' && dot_counter == 1)
			return (this->_strType = "float", FLOAT);
		else if (input[i] < 48 || input[i] > 57)
			return (this->_type);
	}
	return (this->_type);
}

unsigned int	Converter::check_double(std::string &input)
{
	size_t	dot_counter = 0;

	if (this->_type != 0)
		return (this->_type);
	for (int i = 0; input[i]; i++)
	{
		if (i == 0 && input[i] == '-')
			continue ;
		else if (i > 0 && input[i] == '.')
			dot_counter++;
		else if (input[i] < 48 || input[i] > 57)
			return (this->_type);
	}
	if (dot_counter == 1)
		return (this->_strType = "double", DOUBLE);
	return (this->_type);
}

void	Converter::convertType(std::string &type)
{
	if (type.size() < 3)
		return ;
	switch (this->_type) {
		case 1:
				this->doChar();
				break ;
		case 2:
				this->doInt();
				break ;
		case 3:
				this->doFloat();
				break ;
		case 4:
				this->doDouble();
				break ;
		}
}

void	Converter::doChar(void)
{
	this->_cType = this->_input[0];
	this->_iType = static_cast<int>(this->_cType);
	this->_fType = static_cast<float>(this->_cType);
	this->_dType = static_cast<double>(this->_cType);
	std::cout << "char: " << this->_cType << std::endl;
	this->printValues();
}

void	Converter::doInt(void)
{
	size_t	i = 0;
	int		neg = 1;

	if (this->_input[0] == '-')
	{
		neg = -1;
		i++;
	}
	for (; i < this->_input.size(); i++)
		this->_iType = this->_iType * 10 + (this->_input[i] - '0');
	this->_iType *= neg;
	this->_fType = static_cast<float>(this->_iType);
	this->_dType = static_cast<double>(this->_iType);
	std::cout << "char: ";
	if (this->_iType >= 32 && this->_iType <= 126)
		std::cout << (char)this->_iType << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	this->printValues();
}

void	Converter::doFloat(void)
{
	this->_fType = atof(this->_input.c_str());
	this->_iType = static_cast<int>(this->_fType);
	this->_dType = static_cast<double>(this->_fType);
	std::cout << "char: ";
	if (this->_iType >= 32 && this->_iType <= 126)
		std::cout << (char)this->_iType << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	this->printValues();
}

void	Converter::doDouble(void)
{
	this->_dType = atof(this->_input.c_str());
	this->_iType = static_cast<int>(this->_dType);
	this->_fType = static_cast<float>(this->_dType);
	std::cout << "char: ";
	if (this->_iType >= 32 && this->_iType <= 126)
		std::cout << (char)this->_iType << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	this->printValues();
}

void	Converter::printValues(void)
{
	std::cout << "int: " << this->_iType << std::endl;
	std::cout << "float: " << this->_fType;
	if ((this->_iType - this->_fType) == 0)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	std::cout << "double: " << this->_dType;
	if (!(this->_iType - this->_dType))
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void	Converter::handle_error(void)
{
	if (!this->_err_type)
		return ;
	else if (this->_err_type == NAN)
		throw Converter::NaNException();
	else if (this->_err_type == MINUS_INF)
		throw Converter::MinusInfException();
	else
		throw Converter::PlusInfException();
}

const char*	Converter::DefaultException::what(void) const throw()
{
	return ("Input is invalid.");
}

const char*	Converter::NaNException::what(void) const throw()
{
	std::cerr << "char: impossible" << std::endl;
	std::cerr << "int: impossible" << std::endl;
	std::cerr << "float: nanf" << std::endl;
	std::cerr << "double: nan";
	return ("");
}

const char*	Converter::MinusInfException::what(void) const throw()
{
	std::cerr << "char: impossible" << std::endl;
	std::cerr << "int: impossible" << std::endl;
	std::cerr << "float: -inff" << std::endl;
	std::cerr << "double: -inf";
	return ("");
}

const char*	Converter::PlusInfException::what(void) const throw()
{
	std::cerr << "char: impossible" << std::endl;
	std::cerr << "int: impossible" << std::endl;
	std::cerr << "float: +inff" << std::endl;
	std::cerr << "double: +inf";
	return ("");
}

