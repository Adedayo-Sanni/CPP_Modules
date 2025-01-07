/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:17:54 by asanni            #+#    #+#             */
/*   Updated: 2025/01/06 18:43:37 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): Name(name), Arma(NULL){}

HumanB::~HumanB(){
	std::cout << Name << " is being destroyed!" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	Arma = &weapon;
}

void HumanB::attack(){
	if (Arma) {
	std::cout << Name << " attacks with their " << Arma->getType() << std::endl;
	} else {
	std::cout << Name << " has no weapon to attack with" << std::endl;
	}
};
