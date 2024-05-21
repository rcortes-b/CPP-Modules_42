/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:02:50 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/20 17:02:51 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
			DiamondTrap( void );
			DiamondTrap(std::string name);
			DiamondTrap(DiamondTrap &obj);
			DiamondTrap &operator=(const DiamondTrap &obj);
			~DiamondTrap( void );
			using ScavTrap::attack;
			void	whoAmI( void );
			void 	setName(std::string name);
	private:
			std::string	_name;
};

#endif