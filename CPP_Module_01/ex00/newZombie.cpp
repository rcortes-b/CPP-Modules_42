/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:01:29 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/15 18:01:31 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

 Zombie* Zombie::newZombie( std::string name )
 {
	Zombie	*zmb;

	zmb = new Zombie();
	zmb->name_setter_s(name);
	zmb->announce();
	return (zmb);
 }
