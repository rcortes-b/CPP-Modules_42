#include "../includes/Character.hpp"

Character::Character(void) : _slots()
{
	std::cout << "Character Default Constructor" << std::endl;
	this->setName("DefaultName");
}

Character::Character(std::string const &name) : _slots()
{
	std::cout << "Character Param Constructor" << std::endl;
	this->setName(name);
}

Character::Character(Character const &obj) : ICharacter(obj), _slots()
{
	this->setName(obj.getName());
	for (int i = 0; i < 4; i++)
	{
		if (obj._slots[i])
			this->_slots[i] = obj._slots[i];
	}
	std::cout << "Character Copy Constructor" << std::endl;
}

Character const &Character::operator=(Character const &obj)
{
	std::cout << "Character Assignment Operator" << std::endl;
	this->setName(obj.getName());
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i])
			delete this->_slots[i];
	}
	std::cout << "Character Defautl Destructor" << std::endl;
}

std::string const &Character::getName(void) const
{
	return (this->_name);
}

void	Character::setName(std::string const &name)
{
	this->_name = name;
}

bool	Character::is_equiped(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i] == materia)
			return (true);
	}
	return (false);
}

void	Character::equip(AMateria *materia)
{
	if (!materia)
	{
		std::cerr << "Invalid materia !" << std::endl;
		return ;
	}
	else if (is_equiped(materia))
	{
		std::cout << "This materia is already equiped !" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_slots[i])
		{
			this->_slots[i] = materia;
			std::cout << "Materia " << materia->getType() << " has been equiped !" << std::endl;
			return ;
		}
	}
	if (materia)
	{
		std::cout << "The inventory of " << this->getName() << " is full !" << std::endl;
		delete materia;
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cerr << "Cannot unequit materia due to invalid index !" << std::endl;
	else if (this->_slots[idx])
	{
		std::cout << "Materia " << this->_slots[idx]->getType();
		std::cout << " has been unequipped !" << std::endl;
		this->_slots[idx] = NULL;
	}
	else
		std::cout << "Unable to unequip materia, this slot is already empty !" << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
		if (idx < 0 || idx > 3)
			std::cerr << "Cannot unequit materia due to invalid index !" << std::endl;
		else if (!this->_slots[idx])
			std::cout << "Unable to use materia because the slot is empty !" << std::endl;
		else
			this->_slots[idx]->use(target);
}