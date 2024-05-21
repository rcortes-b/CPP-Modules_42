/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:52:26 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/21 10:52:28 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
	ClapTrap Mouli ("Moulinette");
	ClapTrap Norme ("Norminette");

	Mouli.attack("pep");
	Norme.takeDamage(20);
	Norme.takeDamage(20);
	Mouli.takeDamage(20);
	Norme.takeDamage(200);
	Mouli.takeDamage(2);
	Mouli.takeDamage(2);
	Norme.beRepaired(43);
}
