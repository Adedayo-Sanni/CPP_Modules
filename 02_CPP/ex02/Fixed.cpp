/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:03:31 by asanni            #+#    #+#             */
/*   Updated: 2025/03/16 16:31:47 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	// std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(Fixed const &object){
	// std::cout << "Copy constructor called" << std::endl;
	*this = object;
}

Fixed::Fixed(const int nbr){
	// std::cout << "Int constructor called" << std::endl;
	//this->fixedPoint = nbr * 256;
	this->fixedPoint = nbr << fractionalBits;
}

Fixed::Fixed(const float nbr){
	// std::cout << "Float constructor called" << std::endl;
	//this->fixedPoint = roundf(nbr * 256);
	this->fixedPoint = roundf(nbr * 256);
}

Fixed& Fixed::operator=(Fixed const &object){
	// std::cout << "Copy assignment operator called" << std::endl;
	if(&object != this){
		this->fixedPoint = object.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPoint;
}

void Fixed::setRawBits( int const raw ){
	// std::cout << "setRawBits member function called" << std::endl;
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

bool Fixed::operator>(const Fixed& obj) const {
	return fixedPoint > obj.fixedPoint;
}

bool Fixed::operator<(const Fixed& obj) const {
	return fixedPoint < obj.fixedPoint;
}

bool Fixed::operator>=(const Fixed& obj) const {
	return *this > obj || *this == obj;
}

bool Fixed::operator<=(const Fixed& obj) const {
	return *this < obj || *this == obj;
}

bool Fixed::operator==(const Fixed& obj) const {
	return fixedPoint == obj.fixedPoint;
}

bool Fixed::operator!=(const Fixed& obj) const {
	return !(*this == obj);
}

Fixed Fixed::operator-(const Fixed& obj) const{
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator+(const Fixed& obj) const{
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator*(const Fixed& obj) const{
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed& obj) const{
	if(obj.fixedPoint == 0)
	{
		std::cout << "Division by zero" << std::endl;
		return(0);
	}
	return Fixed(this->toFloat() / obj.toFloat());
}

Fixed& Fixed::operator++(){//pre increment
	fixedPoint +=epsilon;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed ogValue = *this;
	fixedPoint += epsilon;
	return ogValue;
}

Fixed& Fixed::operator--(){ //pre decrement
	fixedPoint -=epsilon;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed ogValue = *this;
	fixedPoint -= epsilon;
	return ogValue; 
}


Fixed& Fixed::min(Fixed& a, Fixed& b){
	if (a.fixedPoint < b.fixedPoint) {
		return a;
	} else {
		return b;
	}
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	if (a.fixedPoint < b.fixedPoint) {
		return a;
	} else {
		return b;
	}
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	if (a.fixedPoint > b.fixedPoint) {
		return a;
	} else {
		return b;
	}
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	if (a.fixedPoint > b.fixedPoint) {
		return a;
	} else {
		return b;
	}
}



