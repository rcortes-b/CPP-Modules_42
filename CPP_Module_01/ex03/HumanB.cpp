/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:02:32 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/15 18:02:33 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << this->_wpon->getType() << std::endl;
}


HumanB::HumanB(std::string name)
{
	std::cout << "Constructor of HumanB !" << std::endl;
	this->_name = name;
}

HumanB::~HumanB()
{
	std::cout << "Destructor of HumanB !" << std::endl;
}

/* La razon por la que HumanB tiene un pointer a weapon es porque si fuese referencia no hay como inicializarlo, ya que no
sabe cuando va a recibir el arma (si es que la recibe). Por lo tanto recibe pointer para poder recibir las modificaciones */

void	HumanB::setWeapon(Weapon &wpon)
{
	this->_wpon = &wpon;
}
