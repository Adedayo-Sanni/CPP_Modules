/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:08:12 by asanni            #+#    #+#             */
/*   Updated: 2025/04/05 18:35:25 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
		std::cout << "ClapTrap " << name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(){
	this->name = "default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
: name(obj.name), hitPoints(obj.hitPoints), energyPoints(obj.energyPoints), attackDamage(obj.attackDamage) {
	std::cout << "Copy constructor called" << std::endl;
}


ClapTrap& ClapTrap::operator=(ClapTrap const &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) {
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " is being destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " 
				  << attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " doesn't have enough energy to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (hitPoints > 0) {
		hitPoints -= amount;
		if (hitPoints < 0) {
			hitPoints = 0;
		}
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " is already out of health!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (energyPoints > 0) {
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " is repaired by " << amount 
				  << " points! Now has " << hitPoints << " hit points." << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " doesn't have enough energy to repair!" << std::endl;
	}
}
