/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:04:03 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/15 18:04:04 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc == 1 || argc != 2)
	{
		std::cout << "Wrong number of arguments !" << std::endl;
		return (1);
	}
	Harl bot;
	bot.complain(argv[1]);
	return (0);
}
