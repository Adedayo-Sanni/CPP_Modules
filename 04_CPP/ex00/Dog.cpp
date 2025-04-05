/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:13:42 by asanni            #+#    #+#             */
/*   Updated: 2025/04/05 20:05:14 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << "Dog " << "has been created!" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &obj) : Animal(){
	std::cout << "Dog " << "has been copied!" << std::endl;
	this->type = obj.type;
}

Dog& Dog::operator=(Dog const &obj) {
	std::cout << "Dog " << "assing operator called" << std::endl;
	this->type = obj.type;
	return(*this);
}

Dog::~Dog(){
	std::cout << "Dog " << "has been destructed" << std::endl;
}

void Dog::makeSound() const{
	std::cout << "AUAUAU!!!" << std::endl;
}
