/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:02:12 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/15 18:02:12 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string 	*stringPTR = &str;
	std::string		&stringREF = str;

	std::cout << "Memory Address of the string: " << &str << std::endl;
	std::cout << "Memory Address of the string pointer: " << &*stringPTR << std::endl;
	std::cout << "Memory Address of the string reference: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "The value of the string is: " << str << std::endl;
	std::cout << "The value of the string pointer is: " << *stringPTR << std::endl;
	std::cout << "The value of the string reference is: " << stringREF << std::endl;
	return (0);
}
