/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:12:44 by asanni            #+#    #+#             */
/*   Updated: 2025/04/12 16:51:24 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	std::cout << "Cat " << "has been created!" << std::endl;
	this->type = "Cat";
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(){
	std::cout << "Cat " << "has been copied!" << std::endl;
	this->type = obj.type;
}

WrongCat& WrongCat::operator=(const WrongCat &obj){
	std::cout << "Cat " << "assing operator called" << std::endl;
	this->type = obj.type;
	return(*this);
}

WrongCat::~WrongCat(){
	std::cout << "Cat " << "has been destructed" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "Miau!!!" << std::endl;
}

