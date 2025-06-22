/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:03:58 by asanni            #+#    #+#             */
/*   Updated: 2025/06/22 17:16:10 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal(){
	this->type= "Animal"
}

Animal::Animal(const Animal &other){
	*this = other;
}

Animal& Animal::operator=(const Animal &other){
	if (this != &other){
		this->type = other.type;
	}
	return *this;
}

Animal~Animal(){
	std::cout "Animal " << type << " has been destroyed" << std::endl;
}

void Animal::makeSound(){
	std::cout << "Standard animal soud" << std::endl;
}
