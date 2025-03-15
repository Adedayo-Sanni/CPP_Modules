/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:03:11 by asanni            #+#    #+#             */
/*   Updated: 2025/03/15 20:15:39 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:15:51 by asanni            #+#    #+#             */
/*   Updated: 2025/03/15 15:29:26 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
# define Fixed_HPP

#include <iostream>
#include <cmath>


class Fixed{
	private:
		int fixedPoint;
		static const int fractionalBits = 8;

	public:
		Fixed(); 
		Fixed(Fixed const &object);
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed& operator=(Fixed const &object);
		~Fixed();
		int getRawBits() const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};
std::ostream & operator<<(std::ostream &os, const Fixed &obj);

#endif
