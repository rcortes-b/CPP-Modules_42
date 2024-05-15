/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:03:33 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/15 18:03:34 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Constructor for Harl is built!" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Destructor for Harl is built!" << std::endl;
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*ptrToComplain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	options[4] = {
							"DEBUG",
							"INFO",
							"WARNING",
							"ERROR"
							};
	for (int i = 0; i < NUM_OF_OPTIONS; i++)
	{
		if (options[i].compare(level) == 0)
			(this->*ptrToComplain[i])();
	}
}
