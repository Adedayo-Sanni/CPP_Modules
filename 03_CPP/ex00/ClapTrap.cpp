/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:08:12 by asanni            #+#    #+#             */
/*   Updated: 2025/03/27 17:15:41 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
		std::cout << "ClapTrap " << name << " has been created!" << std::endl;
	}

ClapTrap::ClapTrap(const ClapTrap& obj)
	: name(obj.name), HitPoints(obj.HitPoints), EnergyPoints(obj.EnergyPoints), AttackDamage(obj.AttackDamage) {}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " is being destroyed!" << std::endl;
	}

void ClapTrap::attack(const std::string& target){
	if (EnergyPoints > 0 && HitPoints > 0) {
		EnergyPoints--; // Attacking consumes 1 energy point
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " 
				  << AttackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " doesn't have enough energy to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (HitPoints > 0) {
		HitPoints -= amount;
		if (HitPoints < 0) {
			HitPoints = 0;
		}
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " is already out of health!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (EnergyPoints > 0) {
		EnergyPoints--;
		HitPoints += amount;
		std::cout << "ClapTrap " << name << " is repaired by " << amount 
				  << " points! Now has " << HitPoints << " hit points." << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " doesn't have enough energy to repair!" << std::endl;
	}
}
