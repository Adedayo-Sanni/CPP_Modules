/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:19:03 by asanni            #+#    #+#             */
/*   Updated: 2025/04/12 16:51:10 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "Animal " << "has been created!" << std::endl;
	this->type = "Animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj){
	std::cout << "Animal " << "has been copied!" << std::endl;
	this->type = obj.type;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &obj){
	std::cout << "Animal " << "assing operator called" << std::endl;
	this->type = obj.type;
	return(*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "Animal " << "has been destructed" << std::endl;
}

void WrongAnimal::makeSound() const{
	std::cout << "Generic animal sound" << std::endl;
}

std::string WrongAnimal::getType() const{
	return this->type;
}
