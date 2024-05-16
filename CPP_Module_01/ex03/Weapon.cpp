/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:02:43 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/15 18:02:43 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string&	Weapon::getType() const
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

Weapon::Weapon(std::string type)
{
	std::cout << "Constructor of Weapon !" << std::endl;
	this->setType(type);
}

Weapon::~Weapon()
{
	std::cout << "Destructor of Weapon !" << std::endl;
}
