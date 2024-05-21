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
#include "FragTrap.hpp"

void	ep_msg(std::string name, int option)
{
	if (option == 1) //to beRepaired
	{
		std::cout << "ClapTrap " << name;
		std::cout << " has no energy, so he cannot be repaired !" << std::endl;
	}
	else //to attack
	{
		std::cout << "ClapTrap " << name;
		std::cout << " has no energy, so he cannot attack !" << std::endl;
	}
}

int	main(void)
{
	ScavTrap Norme ("Norminette");
	FragTrap Mouli ("Moulinette");

	Mouli.attack("pep");
	Norme.takeDamage(20);
	Norme.takeDamage(20);
	Mouli.takeDamage(20);
	Norme.takeDamage(200);
	Mouli.takeDamage(2);
	Mouli.takeDamage(2);
	Norme.beRepaired(43);
}
