/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:33:19 by asanni            #+#    #+#             */
/*   Updated: 2025/04/05 15:28:18 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap myScav("Scav3");

	myScav.attack("Target 2");
	myScav.guardGate();
	myScav.attack("Target etc");
	myScav.attack("Target1");
	myScav.guardGate();
	return 0;
}
