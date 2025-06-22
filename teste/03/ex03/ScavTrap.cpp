/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:47:25 by asanni            #+#    #+#             */
/*   Updated: 2025/06/22 16:22:08 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){}

ScavTrap::ScavTrap(std::string name){
	this->name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other){
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other){
	if (this != &other){
		hitPoints = 100;
		energyPoints = 50;
		attackDamage = 20;
	}
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout<< "ScavTrap: " << name + " has been destructed" << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap: " << name << " is in Gatekeeper mode."<< std::endl;
}

