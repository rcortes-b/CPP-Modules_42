#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
public:
		HumanB(std::string name);
		void	attack();
		void	setWeapon(Weapon &wpon);
		~HumanB();
private:
		Weapon 		*_wpon;
		std::string	_name;
};

#endif