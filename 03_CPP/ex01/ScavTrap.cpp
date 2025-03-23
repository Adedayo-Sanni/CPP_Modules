/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:31:13 by asanni            #+#    #+#             */
/*   Updated: 2025/03/23 17:58:13 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap(const std::string& name): ClapTrap(name) {
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap " << name << " has been created!" << std::endl;
}

~ScavTrap(){
	std::cout << "ScavTrap destructor called"<< std::endl;
}

void ScavTrap::attack(const std::string& target) override{
if (EnergyPoints > 0 && HitPoints > 0) {
	EnergyPoints--; // Attacking consumes 1 energy point
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " 
			  << AttackDamage << " points of damage!" << std::endl;
} else {
	std::cout << "ScavTrap " << name << " doesn't have enough energy to attack!" << std::endl;
}
}
void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
