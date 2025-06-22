/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:20:07 by asanni            #+#    #+#             */
/*   Updated: 2025/06/22 16:34:20 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main (void){
	ClapTrap A("Umma");
	ScavTrap B("Glinda");
	FragTrap C("Onor");

	A.attack("Glinda");
	B.guardGate();
	C.highFivesGuys();
	
	std::cout << "\n\n\n" << std::endl;
}
