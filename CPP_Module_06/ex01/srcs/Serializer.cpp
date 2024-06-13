#include "../includes/Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer Default Constructor" << std::endl;
}

Serializer::Serializer(Serializer const &obj)
{
	std::cout << "Serializer Copy Constructor" << std::endl;
	(void)obj;
}

Serializer const &Serializer::operator=(Serializer const &obj)
{
	std::cout << "Serializer Copy Assignment" << std::endl;
	(void)obj;
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer Default Destructor" << std::endl;
}

uintptr_t	Serializer::serialize(t_Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

t_Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<t_Data*>(raw));
}