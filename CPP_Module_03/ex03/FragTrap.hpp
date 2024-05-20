/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:46:27 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/20 16:46:27 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
			FragTrap( void );
			FragTrap(std::string &name);
			FragTrap(FragTrap &obj);
			FragTrap &operator=(const FragTrap &obj);
			~FragTrap( void );
			void	attack(const std::string &target);
			void	highFivesGuys( void );
	private:
};




#endif
