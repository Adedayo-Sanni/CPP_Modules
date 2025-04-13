/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:12:44 by asanni            #+#    #+#             */
/*   Updated: 2025/04/13 19:14:17 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : AAnimal(){
	std::cout << "Cat " << "has been created!" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal() {
	std::cout << "Cat copy constructor called!" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain); 
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called!" << std::endl;
	if (this != &other) {
		this->type = other.type;

		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat(){
	delete this->brain;
	std::cout << "Cat " << "has been destructed" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Miau!!!" << std::endl;
}

std::string Cat::getIdea(int i) const {
	return brain->getIdea(i);
}

void Cat::setIdea(std::string idea, int i) {
	brain->setIdea(idea, i);
}
