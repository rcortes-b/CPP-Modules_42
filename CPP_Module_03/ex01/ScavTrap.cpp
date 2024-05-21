/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:45:55 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/20 16:45:56 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	std::cout << "Default ScavTrap constructor called !" << std::endl;
	this->_name = "";
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Default ScavTrap param constructor called !" << std::endl;
	this->_name = name;
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap(ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap copy constructor called !" << std::endl;
	this->_name = obj._name;
	this->_hp = obj._hp;
	this->_ep = obj._ep;
	this->_ad = obj._ad;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{

	std::cout << "ScavTrap copy operator called !" << std::endl;
	if (this != &obj)
	{
		_name = obj._name;
		_hp = obj._hp;
		_ep = obj._ep;
		_ad = obj._ad;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor has been called !" << std::endl;	
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _ad << " points of damage !" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode !" << std::endl;
}
