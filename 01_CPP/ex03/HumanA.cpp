/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:45:57 by asanni            #+#    #+#             */
/*   Updated: 2025/01/06 18:38:52 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& arma): Name(name), Arma(arma) {}

HumanA::~HumanA(){
	std::cout << Name << " is being destroyed!" << std::endl;
}

void HumanA::attack(){
	std::cout<< Name << " attacks with their " << Arma.getType() <<std::endl;
}
