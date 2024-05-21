/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:18:44 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/16 15:18:45 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default ClapTrap constructor called !" << std::endl;
	this->_name = "";
	this->_hp = 10;
	this->_ep = 10;
	this->_ad = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Default ClapTrap param constructor called !" << std::endl;
	this->_name = name;
	this->_hp = 10;
	this->_ep = 10;
	this->_ad = 0;
}

ClapTrap::ClapTrap(ClapTrap &obj)
{
	std::cout << "ClapTrap copy constructor called !" << std::endl;
	this->_name = obj._name;
	this->_hp = obj._hp;
	this->_ep = obj._ep;
	this->_ad = obj._ad;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "ClapTrap copy operator called !" << std::endl;
	if (this != &obj)
	{
		_name = obj._name;
		_hp = obj._hp;
		_ep = obj._ep;
		_ad = obj._ad;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor has been called !" << std::endl;	
}

void	ClapTrap::attack(const std::string &target)
{
	if (_ep == 0)
	{
		ep_msg(_name, 0);
		return ;
	}
	else if (_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead, ";
		std::cout << "so he cannot attack !" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _ad << " points of damage!" << std::endl;
	_ep -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp == 0)
	{
		std::cout << _name << " is already dead !" << std::endl;
		return ;
	}
	std::cout << _name << " has received " << amount;
	std::cout << " hit points of damage !" << std::endl;
	if ((int)(_hp - amount) < 0)
		_hp = 0;
	else
		_hp -= amount;
	if (_hp == 0)
		std::cout << _name << " got clapped ! (died)" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp == 0)
	{
		std::cout << _name << " is dead and cannot "; 
		std::cout << "be repaired !" << std::endl;
		return ;
	}
	else if (_ep == 0)
	{
		ep_msg(_name, 1);
		return ;
	}
	std::cout << _name << " has repaired a total amount of ";
	std::cout << amount << " hit points !" << std::endl;
	_ep -= 1;
	_hp += amount;
}