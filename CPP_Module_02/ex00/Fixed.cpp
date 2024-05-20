/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:00:35 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/16 11:00:36 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor has been called !" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor has been called !" << std::endl;
	this->_fixedValue = obj.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called !" << std::endl;
	if (this != &obj)
		this->_fixedValue = obj.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor has been called !" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits function has been called !" << std::endl;
	return (this->_fixedValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits function has been called !" << std::endl;
	this->_fixedValue = raw;
}
