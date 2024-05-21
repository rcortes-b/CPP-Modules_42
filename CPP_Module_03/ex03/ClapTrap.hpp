/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:18:16 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/16 15:18:17 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	public:
			ClapTrap( void );
			ClapTrap(std::string name);
			ClapTrap(ClapTrap &obj);
			ClapTrap &operator=(const ClapTrap &obj);
			~ClapTrap( void );
			void	attack(const std::string &target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
	protected:
			std::string				_name;
			unsigned int			_hp;
			unsigned int			_ep;
			unsigned int			_ad;
};

void	ep_msg(std::string name, int option);

#endif

/*
• Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/
