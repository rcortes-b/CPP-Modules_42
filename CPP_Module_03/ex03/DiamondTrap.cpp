/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:02:45 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/20 17:02:46 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name")
{
	std::cout << "Default DiamondTrap constructor called !" << std::endl;
	this->_name = "DefaultDiamondTrap";
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_ad = FragTrap::_ad;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	std::cout << "Default DiamondTrap param constructor called !" << std::endl;

	this->_name = name;
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_ad = FragTrap::_ad;
}

DiamondTrap::DiamondTrap(DiamondTrap &obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj)
{
	std::cout << "DiamondTrap copy constructor called !" << std::endl;
	this->_name = obj._name;
	this->_hp = obj._hp;
	this->_ep = obj._ep;
	this->_ad = obj._ad;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{

	std::cout << "DiamondTrap copy operator called !" << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_hp = obj._hp;
		this->_ep = obj._ep;
		this->_ad = obj._ad;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor has been called !" << std::endl;	
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name's " << this->_name << " and ClapTrap name's ";
	std::cout << ClapTrap::_name << " !" << std::endl;
}