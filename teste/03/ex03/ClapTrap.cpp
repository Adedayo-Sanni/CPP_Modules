/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:28:47 by asanni            #+#    #+#             */
/*   Updated: 2025/06/22 16:33:35 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(std::string name) {
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}
	
// ClapTrap::ClapTrap(const ClapTrap &other){
// 	hitPoints = other.hitPoints;
// 	energyPoints = other.energyPoints;
// 	attackDamage = other.attackDamage;
// }

ClapTrap::ClapTrap(const ClapTrap &other){
	*this = other;
}

ClapTrap::~ClapTrap(){
	std::cout<< "ClapTrap " <<name + " has been destructed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other){
	if(this != &other)
	{
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

void ClapTrap::setName(std::string &name){
	this->name = name;
}

std::string ClapTrap::getname(){
	return name;
}

void ClapTrap::attack(const std::string& target){
	if(energyPoints > 0)
	{
		energyPoints--;
		std::cout<< "ClapTrap: " << name << " attacks " << target << " causing " << attackDamage << " points of demage" << std::endl;
	}
	else
		std::cout<< "ClapTrap: " << name << " does not have enough energy!" << std::endl;
	
}

void ClapTrap::takeDamage(unsigned int amount){
	attackDamage = amount;
	std::cout<< "ClapTrap: " << name << " receives " << amount <<" points of damage"<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (energyPoints > 0)
	{
		energyPoints--;
		std::cout<< "ClapTrap: " <<  name  << " is repairing itself with" << amount << " points"<<std::endl;
	}
}
