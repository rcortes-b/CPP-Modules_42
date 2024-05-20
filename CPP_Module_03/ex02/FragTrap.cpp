/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:46:22 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/20 16:46:23 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	std::cout << "Default FragTrap construcor called !" << std::endl;
}

FragTrap::FragTrap(std::string &name) : ClapTrap(name)
{
	std::cout << "Default FragTrap param constructor called !" << std::endl;
	this->_name = name;
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
}

FragTrap::FragTrap(FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "FragTrap copy constructor called !" << std::endl;
	this->_name = obj._name;
	this->_hp = obj._hp;
	this->_ep = obj._ep;
	this->_ad = obj._ad;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{

	std::cout << "FragTrap copy operator called !" << std::endl;
	if (this != &obj)
	{
		_name = obj._name;
		_hp = obj._hp;
		_ep = obj._ep;
		_ad = obj._ad;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor has been called !" << std::endl;	
}

void	FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _ad << " points of damage !" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap says high me five !" << std::endl;
}
