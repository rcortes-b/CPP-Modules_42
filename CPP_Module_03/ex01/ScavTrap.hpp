/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:18:16 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/16 15:18:17 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
			ScavTrap(std::string &name);
			ScavTrap(ScavTrap &obj);
			ScavTrap &operator=(const ScavTrap &obj);
			~ScavTrap();
			void	attack(const std::string &target);
			void	guardGate( void );
	private:
};



#endif