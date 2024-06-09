#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _materia_slots()
{
	std::cout << "MateriaSource Default Constructor" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &obj) : IMateriaSource(obj) , _materia_slots()
{
	std::cout << "MateriaSource Copy Constructor" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (obj._materia_slots[i])
			this->_materia_slots[i] = obj._materia_slots[i];
	}
}

MateriaSource const &MateriaSource::operator=(MateriaSource const &obj)
{
	std::cout << "MateriaSource Assignment Operator" << std::endl;
	(void)obj;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia_slots[i])
			delete this->_materia_slots[i];
	}
	std::cout << "MateriaSource Default Destructor" << std::endl;
}

bool	MateriaSource::do_exists(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia_slots[i] == materia)
			return (true);
	}
	return (false);
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
	{
		std::cerr << "This materia cannot be learned because it doesn't exists !" << std::endl;
		return ;
	}
	else if (do_exists(materia))
	{
		std::cout << "Materia " << materia->getType();
		std::cout << " cannot be learned because it's already learned !" << std::endl;
		return;
	}
	else 
	{
		for (int i = 0; i < 4; i++)
		{
			if (!this->_materia_slots[i])
			{
				this->_materia_slots[i] = materia;
				return ;
			}
		}
	}
	if (materia)
	{
		std::cout << "This materia cannot be learned because ";
		std::cout << "this MateriaSource already know 4 materias !" << std::endl;
		delete materia;
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia_slots[i] && this->_materia_slots[i]->getType() == type)
			return (this->_materia_slots[i]->clone());
	}
	std::cout << "Materia cannot be creted because the type is unknown !" << std::endl;
	return (0);
}