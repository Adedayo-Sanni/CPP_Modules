/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:39:36 by asanni            #+#    #+#             */
/*   Updated: 2025/03/16 16:18:45 by asanni           ###   ########.fr       */
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

		static const int epsilon = 1;
		Fixed();
		Fixed(Fixed const &object);
		Fixed(const int nbr);
		Fixed(const float nbr);
		~Fixed();
		Fixed& operator=(Fixed const &object);
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		Fixed operator-(const Fixed& obj) const;
		Fixed operator+(const Fixed& obj) const;
		Fixed operator*(const Fixed& obj) const;
		Fixed operator/(const Fixed& obj) const;
		Fixed &operator++(); //pre increment
		Fixed operator++(int);
		Fixed &operator--(); //pre decrement
		Fixed operator--(int);
		
		int getRawBits() const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};
std::ostream & operator<<(std::ostream &os, const Fixed &obj);

#endif
