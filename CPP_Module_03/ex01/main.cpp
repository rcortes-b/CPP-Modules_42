/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:18:12 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/16 15:18:12 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	ep_msg(std::string name, int option)
{
	if (option == 1)
	{
		std::cout << "ClapTrap " << name;
		std::cout << " has no energy, so he cannot be repaired !" << std::endl;
	}
	else //attack
	{
		std::cout << "ClapTrap " << name;
		std::cout << " has no energy, so he cannot attack !" << std::endl;
	}
}

int	main(void)
{
	std::string name = "norminette";
	ScavTrap norme(name);
	name = "moulinette";
	ScavTrap mouli (name);
	norme.attack(name);
	mouli.takeDamage(20);
	mouli.takeDamage(20);
	mouli.takeDamage(20);
	mouli.takeDamage(200);
	mouli.takeDamage(2);
	mouli.takeDamage(2);
	norme.beRepaired(43);
}
