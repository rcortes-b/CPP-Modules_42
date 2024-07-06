#include "../includes/Span.hpp"

Span::Span(void)
{
	std::cout << "Default Constructor" << std::endl;
	this->_N = DEFAULT_LIMIT;

}

Span::Span(unsigned int N) : _N(N)
{
	std::cout << "Parameter Constructor" << std::endl;
}

Span::Span(Span const &obj)
{
	std::cout << "Copy Constructor" << std::endl;
	this->_N = obj._N;
	this->_container = obj._container;
}

Span	&Span::operator=(Span const &obj)
{
	std::cout << "Copy Assignment" << std::endl;
	this->_N = obj._N;
	this->_container = obj._container;
	return (*this);
}

Span::~Span(void)
{
	std::cout << "Default Destructor" << std::endl;
}

void	Span::addNumber(unsigned int number)
{
	if (this->_container.size() == this->_N)
		throw Span::MaxNumbersStored();
	this->_container.push_back(number);
}

unsigned int	Span::shortestSpan(void)
{
	if(this->_container.size() < 2)
		throw Span::ShortestException();

	int	res = -1;
	int	tmp = 0;
	std::sort(this->_container.begin(), this->_container.end());
	std::vector<unsigned int>::iterator it = this->_container.begin();
	it++;
	for (;	it != this->_container.end(); it++)
	{
		tmp = *it  - *(it - 1);
		if (res == -1 || res > tmp)
			res = tmp;
	}
	return (res);
}

unsigned int	Span::longestSpan(void)
{
	if(this->_container.size() < 2)
		throw Span::LongestException();
	std::sort(this->_container.begin(), this->_container.end());
	return (*(this->_container.end() - 1) - *this->_container.begin());
}

void	Span::fillNumbers(void)
{
	unsigned int	size = this->_container.size();

	for (; size < this->_N; size++)
		this->addNumber(size);
}

std::vector<unsigned int>	Span::getContainer( void ) const
{
	return (_container);
}

const char	*Span::MaxNumbersStored::what(void) const throw()
{
	return ("The container can't store more numbers");
}

const char	*Span::ShortestException::what(void) const throw()
{
	return ("No shortest Span can be found due to there isn't enough numbers");
}

const char	*Span::LongestException::what(void) const throw()
{
	return ("No longest Span can be found due to there isn't enough numbers");
}