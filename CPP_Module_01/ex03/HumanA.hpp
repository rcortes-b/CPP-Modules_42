#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
public:
		HumanA(std::string name, Weapon &wpon);
		void	attack();
		~HumanA();
private:
		Weapon 		&_wpon;
		std::string	_name;
};

#endif