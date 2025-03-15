/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:03:31 by asanni            #+#    #+#             */
/*   Updated: 2025/03/15 20:24:17 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(Fixed const &object){
	std::cout << "Copy constructor called" << std::endl;
	*this = object;
}

Fixed::Fixed(const int nbr){
	std::cout << "Int constructor called" << std::endl;
	//this->fixedPoint = nbr * 256;
	this->fixedPoint = nbr << fractionalBits;
}

Fixed::Fixed(const float nbr){
	std::cout << "Float constructor called" << std::endl;
	//this->fixedPoint = roundf(nbr * 256);
	this->fixedPoint = roundf(nbr * 256);
}

Fixed& Fixed::operator=(Fixed const &object){
	std::cout << "Copy assignment operator called" << std::endl;
	if(&object != this){
		this->fixedPoint = object.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPoint;
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}

float Fixed::toFloat( void ) const{
	return((float)this->fixedPoint / 256);
}

int Fixed::toInt( void ) const{
	return(roundf(this->fixedPoint >> fractionalBits));
}

std::ostream & operator<<(std::ostream &os, const Fixed &obj ){
	os << obj.toFloat();
	return os;
}
