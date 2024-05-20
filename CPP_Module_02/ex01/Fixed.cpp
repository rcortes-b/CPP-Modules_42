/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:04:33 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/16 11:04:34 by rcortes-         ###   ########.fr       */
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

Fixed::Fixed(const int fpValue)
{
	std::cout << "Int constructor called !" << std::endl;
	this->_fixedValue = fpValue << _bits;
}

Fixed::Fixed(const float fpValue)
{
	std::cout << "Float constructor called !" << std::endl;
	this->_fixedValue = roundf(fpValue * (1 << _bits));
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator = called !" << std::endl;
	if (this != &obj)
		_fixedValue = obj.getRawBits();
	return (*this);
}

std::ostream&  operator<<(std::ostream &os, const Fixed &obj)
{
	std::cout << "Copy assignment operator << called !" << std::endl;
	os << obj.toFloat();
	return (os);
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

float	Fixed::toFloat (void ) const
{
	return ((float)this->getRawBits() / (float)(1 << this->_bits));
}

int	Fixed::toInt (void ) const
{
	return (this->getRawBits() / (1 << this->_bits));
}
