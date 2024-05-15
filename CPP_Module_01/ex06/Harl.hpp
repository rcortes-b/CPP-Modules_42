/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:04:00 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/15 18:04:01 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#define NUM_OF_OPTIONS 4

class Harl {
	public:
			Harl( void );
			void complain( std::string level );
			void filterComplain(int opt);
			~Harl( void );
	private:
			void debug( void );
			void info( void );
			void warning( void );
			void error( void );
};
#endif
