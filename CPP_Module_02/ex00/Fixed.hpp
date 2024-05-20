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

class Fixed {
	public:
			Fixed();
			Fixed(const Fixed &obj);
			Fixed& operator=(const Fixed& obj);
			~Fixed();
			int		getRawBits( void ) const;
			void	setRawBits( int const raw );
	private:
			int	_fixedValue;
			static const int	_bits = 8;
};

#endif
