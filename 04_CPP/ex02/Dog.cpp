/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:13:42 by asanni            #+#    #+#             */
/*   Updated: 2025/04/13 19:13:51 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal(){
	std::cout << "Dog " << "has been created!" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal() {
	std::cout << "Dog copy constructor called!" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain); 
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called!" << std::endl;
	if (this != &other) {
		this->type = other.type;

		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog " << "has been destructed" << std::endl;
}

void Dog::makeSound() const{
	std::cout << "AUAUAU!!!" << std::endl;
}

std::string Dog::getIdea(int i) const {
	return brain->getIdea(i);
}

void Dog::setIdea(std::string idea, int i) {
	brain->setIdea(idea, i);
}
