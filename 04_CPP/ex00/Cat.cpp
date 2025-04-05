/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:12:44 by asanni            #+#    #+#             */
/*   Updated: 2025/04/05 20:13:15 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << "Cat " << "has been created!" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &obj) : Animal(){
	std::cout << "Cat " << "has been copied!" << std::endl;
	this->type = obj.type;
}

Cat& Cat::operator=(const Cat &obj){
	std::cout << "Cat " << "assing operator called" << std::endl;
	this->type = obj.type;
	return(*this);
}

Cat::~Cat(){
	std::cout << "Cat " << "has been destructed" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Miau!!!" << std::endl;
}

// std::string Cat::getType() const{
// 	return this->type;
// }
