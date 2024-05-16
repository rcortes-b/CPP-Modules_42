/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:01:20 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/15 18:01:22 by rcortes-         ###   ########.fr       */
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
			void	name_setter_s(std::string name);
			void	announce(void);
			static  Zombie*	newZombie( std::string name );
			void	randomChump( std::string name );
			~Zombie();

	private :
			std::string	_name;

};

#endif
