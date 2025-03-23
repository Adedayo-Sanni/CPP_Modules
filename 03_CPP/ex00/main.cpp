/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:20:10 by asanni            #+#    #+#             */
/*   Updated: 2025/03/23 16:22:31 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap clapTrap("Clapper");

	clapTrap.attack("Enemy1");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);
	clapTrap.attack(" Enemy2");

	return 0;
}
