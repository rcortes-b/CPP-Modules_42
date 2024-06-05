#include "../includes/Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor !" << std::endl;
}

Brain::Brain(Brain &obj)
{
	std::cout << "Brain default copy constructor !" << std::endl;
	*this = obj;
}

Brain &Brain::operator=(Brain &obj)
{
	std::cout << "Brain default copy operator !" << std::endl;
	//if (*this != obj)
		*this = obj;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain default destructor !" << std::endl;
}

std::string	Brain::getIdea(int n)
{
	return (this->_ideas[n]);
}

void	Brain::setIdea(std::string idea, int n)
{
	this->_ideas[n] = idea;
}