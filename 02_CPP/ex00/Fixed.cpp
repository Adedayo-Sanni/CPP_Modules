/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:11:31 by asanni            #+#    #+#             */
/*   Updated: 2025/03/15 18:53:51 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->num = 0;
}

Fixed::Fixed(Fixed const &object){
	std::cout << "Copy constructor called" << std::endl;
	if(&object != this){
		this->num = object.getRawBits();
	}
}

Fixed& Fixed::operator=(Fixed const &object){
	std::cout << "Copy assignment operator called" << std::endl;
	if(&object != this){
		this->num = object.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits()const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->num;
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	this->num = raw;
}
