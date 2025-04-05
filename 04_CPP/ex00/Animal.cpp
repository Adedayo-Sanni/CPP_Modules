/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:19:03 by asanni            #+#    #+#             */
/*   Updated: 2025/04/05 19:59:27 by asanni           ###   ########.fr       */
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
	std::cout << "Generic animal sound" << std::endl;
}

std::string Animal::getType() const{
	return this->type;
}
