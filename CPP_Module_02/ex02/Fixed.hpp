/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:00:40 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/16 11:00:40 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdbool.h>

class Fixed {
	public:
			Fixed();
			Fixed(const Fixed &obj);
			Fixed(const int fpValue); //new
			Fixed(const float fpValue); //new
			~Fixed();
			float	toFloat (void ) const;
			int		toInt ( void ) const;
			void	setRawBits( int const raw );
			int		getRawBits( void ) const;
			friend std::ostream&  operator<<(std::ostream &os, const Fixed &obj);
			Fixed& operator=(const Fixed& obj);
			//Comparison operators
			bool	operator>(const Fixed& obj);
			bool	operator<(const Fixed& obj);
			bool	operator>=(const Fixed& obj);
			bool	operator<=(const Fixed& obj);
			bool	operator==(const Fixed& obj);
			bool	operator!=(const Fixed& obj);
			//Artihmetic operators
			Fixed operator+(const Fixed& obj);
			Fixed operator-(const Fixed& obj);
			Fixed operator*(const Fixed& obj);
			Fixed operator/(const Fixed& obj);
			//Increment / Decrement operators
			Fixed& operator++( void );
			Fixed operator++( int );
			Fixed& operator--( void );
			Fixed operator--( int );
			//Overloaded member functions
			static Fixed& min(Fixed &a, Fixed &b);
			static const Fixed& min(const Fixed &a, const Fixed &b);
			static Fixed& max(Fixed &a, Fixed &b);
			static const Fixed& max(const Fixed &a, const Fixed &b);
			

	private:
			int					_fixedValue;
			static const int	_bits = 8;
};

#endif
