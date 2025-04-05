/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:31:13 by asanni            #+#    #+#             */
/*   Updated: 2025/04/05 16:10:25 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj): ClapTrap(obj) {
	std::cout << "ScavTrap "<< "Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) {
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return *this;
}


ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << name << " destructor called"<< std::endl;
}

void ScavTrap::attack(const std::string& target) {
if (energyPoints > 0 && hitPoints > 0) {
	energyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " 
			  << attackDamage << " points of damage!" << std::endl;
} else {
	std::cout << "ScavTrap " << name << " doesn't have enough energy to attack!" << std::endl;
}
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
