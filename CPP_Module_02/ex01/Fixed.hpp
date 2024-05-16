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

class Fixed {
	public:
			Fixed();
			Fixed(const Fixed &obj);
			Fixed(const int fpValue); //new
			Fixed(const float fpValue); //new
			Fixed& operator=(const Fixed& obj);
			~Fixed();
			friend std::ostream&  operator<<(std::ostream &os, const Fixed &obj);
			int		getRawBits( void ) const;
			void	setRawBits( int const raw );
			float	toFloat (void ) const; //new
			int		toInt ( void ) const; //new
	private:
			int					_fixedValue;
			static const int	_bits = 8;
};

#endif
