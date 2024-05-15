/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:03:56 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/15 18:03:57 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl has been built!" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl has been destroyed!" << std::endl;
}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!\n" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more\n" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	options[4] = {
							"DEBUG",
							"INFO",
							"WARNING",
							"ERROR"
							};
	for (int i = 0; i < NUM_OF_OPTIONS; i++)
	{
		if (options[i].compare(level) == 0)
		{
			this->filterComplain(i);
			return ;
		}
	}
	this->filterComplain(4);
}

void	Harl::filterComplain(int opt)
{
	void		(Harl::*ptrToComplain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	switch (opt){
		case 0:
			(this->*ptrToComplain[opt++])();
		case 1:
			(this->*ptrToComplain[opt++])();
		case 2:
			(this->*ptrToComplain[opt++])();
		case 3:
			(this->*ptrToComplain[opt++])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		
	}
}