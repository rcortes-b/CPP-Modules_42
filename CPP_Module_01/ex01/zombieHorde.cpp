/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:02:04 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/15 18:02:05 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	Zombie	*zmb;

	zmb = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zmb[i].name_setter(name);
		zmb[i].announce();
	}
	return (zmb);
}
