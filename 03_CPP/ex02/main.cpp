/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:47:02 by asanni            #+#    #+#             */
/*   Updated: 2025/03/27 19:55:07 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
	FragTrap fragtrap1("Scaver1");
	fragtrap1.attack("Target1");
	fragtrap1.highFivesGuys();
	FragTrap fragtrap2("Scaver2");
	fragtrap2.attack("Target2");
	fragtrap2.highFivesGuys();
	return 0;
}
