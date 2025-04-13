/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:19:03 by asanni            #+#    #+#             */
/*   Updated: 2025/04/13 19:23:34 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(){
	std::cout << "Animal " << "has been created!" << std::endl;
	this->type = "Animal";
}

AAnimal::AAnimal(const AAnimal &obj){
	std::cout << "Animal " << "has been copied!" << std::endl;
	this->type = obj.type;
}

AAnimal& AAnimal::operator=(AAnimal const &obj){
	std::cout << "Animal " << "assing operator called" << std::endl;
	this->type = obj.type;
	return(*this);
}

AAnimal::~AAnimal(){
	std::cout << "Animal " << "has been destructed" << std::endl;
}

void AAnimal::makeSound() const{
	std::cout << "Generic animal sound" << std::endl;
}

std::string AAnimal::getType() const{
	return this->type;
}
