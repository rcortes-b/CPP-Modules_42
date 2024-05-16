/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:01:58 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/15 18:01:58 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <stdbool.h>

class Zombie
{
	public :
			Zombie();
			static Zombie* zombieHorde( int N, std::string name );
			void	announce(void);
			void	name_setter(std::string name);
			~Zombie();

	private :
			std::string	_name;

};

#endif
