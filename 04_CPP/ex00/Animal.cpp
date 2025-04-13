/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:19:03 by asanni            #+#    #+#             */
/*   Updated: 2025/04/13 19:48:09 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Animal " << "has been created!" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &obj){
	std::cout << "Animal " << "has been copied!" << std::endl;
	this->type = obj.type;
}

Animal& Animal::operator=(Animal const &obj){
	std::cout << "Animal " << "assing operator called" << std::endl;
	this->type = obj.type;
	return(*this);
}

Animal::~Animal(){
	std::cout << "Animal " << "has been destructed" << std::endl;
}

void Animal::makeSound() const{
	std::cout <<YELLOW << "Generic animal sound" << RESET << std::endl;
}

std::string Animal::getType() const{
	return this->type;
}
