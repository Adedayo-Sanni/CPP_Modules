/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:20:58 by asanni            #+#    #+#             */
/*   Updated: 2025/04/05 18:38:58 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " has been created! Let's get this party started!" << std::endl;
}

FragTrap::FragTrap() : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " has been created! Let's get this party started!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj) {
	std::cout << "FragTrap " << name << " has been copied and ready to go!" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) {
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " has been destroyed! Boom!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << name << " is asking for a HIGH FIVE! Wooooo!" << std::endl;
}
