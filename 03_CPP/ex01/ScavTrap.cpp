/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:31:13 by asanni            #+#    #+#             */
/*   Updated: 2025/03/27 20:21:54 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"



ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) {
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap " << name << " has been created!" << std::endl;
}

ScavTrap(const ScavTrap& obj){
	
}

ScavTrap& operator=(const ScavTrap& obj){
	
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << "name "<< "  destructor called"<< std::endl;
}

void ScavTrap::attack(const std::string& target) {
if (EnergyPoints > 0 && HitPoints > 0) {
	EnergyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " 
			  << AttackDamage << " points of damage!" << std::endl;
} else {
	std::cout << "ScavTrap " << name << " doesn't have enough energy to attack!" << std::endl;
}
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
