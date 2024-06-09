#include "../includes/IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{
	std::cout << "IMateriaSource Default Constructor" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &obj)
{
	std::cout << "IMateriaSource Copy Constructor" << std::endl;
	*this = obj;
}

IMateriaSource const &IMateriaSource::operator=(IMateriaSource const &obj)
{
	(void)obj;
	std::cout << "IMateriaSource Assignment Operator" << std::endl;
	return (*this);
}
