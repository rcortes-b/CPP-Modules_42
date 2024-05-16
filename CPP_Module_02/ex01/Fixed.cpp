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

/*
			Fixed(const int fpValue); //new
			Fixed(const float fpValue); //new
			float	toFloat (void ) const; //new
			int		toInt ( void ) const; //new
*/
			

Fixed::Fixed(void)
{
	std::cout << "Default constructor has been called !" << std::endl;
	this->_fixedValue = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor has been called !" << std::endl;
	this->_fixedValue = obj._fixedValue;
}

Fixed::Fixed(const int fpValue) : _fixedValue (fpValue << _bits)
{
	std::cout << "Int constructor called !" << std::endl;
}

Fixed::Fixed(const float fpValue) : _fixedValue(static_cast<int>(std::roundf(fpValue * (1 << _bits))))
{
	std::cout << "Float constructor called !" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator = called !" << std::endl;
	if (this != &obj)
		_fixedValue = obj._fixedValue;
	return (*this);
}

std::ostream&  operator<<(std::ostream &os, const Fixed &obj)
{
	std::cout << "Copy assignment operator << called !" << std::endl;
	return (os << obj._fixedValue);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor has been called !" << std::endl;
}

/*int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits function has been called !" << std::endl;
	return (this->_fixedValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits function has been called !" << std::endl;
	this->_fixedValue = raw;
}*/

float	Fixed::toFloat (void ) const
{
	return ((float)this->_fixedValue);
}

int	Fixed::toInt (void ) const
{
	return ((int)this->_fixedValue);
}