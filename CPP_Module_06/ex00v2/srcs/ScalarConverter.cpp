#include "../includes/ScalarConverter.hpp"

std::string		ScalarConverter::_input = "";
unsigned int	ScalarConverter::_err_type = ERR_DEFAULT;
unsigned int	ScalarConverter::_type = e_DEFAULT;
char			ScalarConverter::_toChar = '\0';
int				ScalarConverter::_toInt = 0;
float			ScalarConverter::_toFloat = 0.0f;
double			ScalarConverter::_toDouble = 0.0;

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &obj)
{
	(void)obj;
}

ScalarConverter const &ScalarConverter::operator=(ScalarConverter const &obj)
{
	(void)obj;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

void	ScalarConverter::convert(std::string input)
{
	try {
		check_input(input);
		handle_error();
	} 
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	_input = input;
	switch (_type) {
		case 1:
				doChar();
				break ;
		case 2:
				doInt();
				break ;
		case 3:
				doFloat();
				break ;
		case 4:
				doDouble();
				break ;
		}
}


void	ScalarConverter::check_input(std::string &input)
{
	if (!input.compare("nan") || !input.compare("nanf"))
		_err_type = NAN;
	else if (!input.compare("-inf") || !input.compare("-inff"))
		_err_type = MINUS_INF;
	else if (!input.compare("+inf") || !input.compare("+inff"))
		_err_type = PLUS_INF;
	else
	{
		_type = check_char(input);
		_type = check_int(input);
		_type = check_float(input);
		_type = check_double(input);
	}
	if (!_err_type && !_type)
		throw ScalarConverter::DefaultException();
}

unsigned int	ScalarConverter::check_char(std::string &input)
{
	if (input.size() != 1)
		return (_type);
	else if ((input[0] < 32 || input[0] > 126)
			|| (input[0] >= '0' && input[0] <= '9'))
		return (e_INT);
		//return (_strType = "int", INT);
	else
		return (e_CHAR);
		//return (_strType = "char", CHAR);
}

unsigned int	ScalarConverter::check_int(std::string &input)
{
	if (_type != 0)
		return (_type);
	for (int i = 0; input[i]; i++)
	{
		if (i == 0 && input[i] == '-')
			continue ;
		else if (input[i] < 48 || input[i] > 57)
			return (_type);
	}
	return (e_INT);
	//return (_strType = "int", INT);
}

unsigned int	ScalarConverter::check_float(std::string &input)
{
	size_t	dot_counter = 0;

	if (_type != 0)
		return (_type);
	for (size_t i = 0; input[i]; i++)
	{
		if (i == 0 && input[i] == '-')
			continue ;
		else if (i > 0 && input[i] == '.')
			dot_counter++;
		else if (input.size() == i + 1 && input[i] == 'f' && dot_counter == 1)
			return (e_FLOAT);
		//	return (_strType = "float", FLOAT);
		else if (input[i] < 48 || input[i] > 57)
			return (_type);
	}
	return (_type);
}

unsigned int	ScalarConverter::check_double(std::string &input)
{
	size_t	dot_counter = 0;

	if (_type != 0)
		return (_type);
	for (int i = 0; input[i]; i++)
	{
		if (i == 0 && input[i] == '-')
			continue ;
		else if (i > 0 && input[i] == '.')
			dot_counter++;
		else if (input[i] < 48 || input[i] > 57)
			return (_type);
	}
	if (dot_counter == 1)
		return (e_DOUBLE);
		//return (_strType = "double", DOUBLE);
	return (_type);
}

void	ScalarConverter::doChar(void)
{
	_toChar = _input[0];
	_toInt = static_cast<int>(_toChar);
	_toFloat = static_cast<float>(_toChar);
	_toDouble = static_cast<double>(_toChar);
	std::cout << "char: " << _toChar << std::endl;
	printValues();
}

void	ScalarConverter::doInt(void)
{
	size_t	i = 0;
	int		neg = 1;

	if (_input[0] == '-')
	{
		neg = -1;
		i++;
	}
	for (; i < _input.size(); i++)
		_toInt = _toInt * 10 + (_input[i] - '0');
	_toInt *= neg;
	_toFloat = static_cast<float>(_toInt);
	_toDouble = static_cast<double>(_toInt);
	std::cout << "char: ";
	if (_toInt >= 32 && _toInt <= 126)
		std::cout << (char)_toInt << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	printValues();
}

void	ScalarConverter::doFloat(void)
{
	_toFloat = atof(_input.c_str());
	_toInt = static_cast<int>(_toFloat);
	_toDouble = static_cast<double>(_toFloat);
	std::cout << "char: ";
	if (_toInt >= 32 && _toInt <= 126)
		std::cout << (char)_toInt << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	printValues();
}

void	ScalarConverter::doDouble(void)
{
	_toDouble = atof(_input.c_str());
	_toInt = static_cast<int>(_toDouble);
	_toFloat = static_cast<float>(_toDouble);
	std::cout << "char: ";
	if (_toInt >= 32 && _toInt <= 126)
		std::cout << (char)_toInt << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	printValues();
}

void	ScalarConverter::printValues(void)
{
	std::cout << "int: " << _toInt << std::endl;
	std::cout << "float: " << _toFloat;
	if ((_toInt - _toFloat) == 0)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	std::cout << "double: " << _toDouble;
	if (!(_toInt - _toDouble))
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void	ScalarConverter::handle_error(void)
{
	if (!_err_type)
		return ;
	else if (_err_type == NAN)
		throw ScalarConverter::NaNException();
	else if (_err_type == MINUS_INF)
		throw ScalarConverter::MinusInfException();
	else
		throw ScalarConverter::PlusInfException();
}

const char*	ScalarConverter::DefaultException::what(void) const throw()
{
	return ("Input is invalid.");
}

const char*	ScalarConverter::NaNException::what(void) const throw()
{
	std::cerr << "char: impossible" << std::endl;
	std::cerr << "int: impossible" << std::endl;
	std::cerr << "float: nanf" << std::endl;
	std::cerr << "double: nan";
	return ("");
}

const char*	ScalarConverter::MinusInfException::what(void) const throw()
{
	std::cerr << "char: impossible" << std::endl;
	std::cerr << "int: impossible" << std::endl;
	std::cerr << "float: -inff" << std::endl;
	std::cerr << "double: -inf";
	return ("");
}

const char*	ScalarConverter::PlusInfException::what(void) const throw()
{
	std::cerr << "char: impossible" << std::endl;
	std::cerr << "int: impossible" << std::endl;
	std::cerr << "float: +inff" << std::endl;
	std::cerr << "double: +inf";
	return ("");
}
