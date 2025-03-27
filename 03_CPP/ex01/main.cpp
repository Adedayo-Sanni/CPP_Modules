/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:33:19 by asanni            #+#    #+#             */
/*   Updated: 2025/03/27 20:13:31 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap myScav = ScavTrap("Scav3");



	myScav.attack("Target etc");
	ScavTrap scavTrap1("Scaver1");
	scavTrap1.attack("Target1");
	scavTrap1.guardGate();
	ScavTrap scavTrap2("Scaver2");
	scavTrap2.attack("Target2");
	scavTrap2.guardGate();
	return 0;
}
