/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:02:37 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/15 18:02:37 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
public:
		HumanB(std::string name);
		void	attack();
		void	setWeapon(Weapon &wpon);
		~HumanB();
private:
		Weapon 		*_wpon;
		std::string	_name;
};

#endif
