/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:27:15 by asanni            #+#    #+#             */
/*   Updated: 2025/06/22 16:35:14 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other){
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap &other){
	if(this != &other)
	{
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap(){
	std::cout<< "Fragtrap " << name << " is being destroyed" <<std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap: " + name << " is requesting a High five" << std::endl;
}
