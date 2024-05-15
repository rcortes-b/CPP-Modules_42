/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:03:44 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/15 18:03:44 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl	complainer;
	complainer.complain("DEBUG");
	complainer.complain("INFO");
	complainer.complain("WARNING");
	complainer.complain("ERROR");
}
