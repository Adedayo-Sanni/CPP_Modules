/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:33:19 by asanni            #+#    #+#             */
/*   Updated: 2025/03/23 17:57:39 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap scavTrap1("Scaver");
	scavTrap1.attack("Target1");
	scavTrap1.guardGate();
	ScavTrap scavTrap2("Scavvy2");
	scavTrap2.attack("Target2");
	scavTrap2.guardGate();
	return 0;
}
