/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:16:48 by asanni            #+#    #+#             */
/*   Updated: 2025/01/09 17:58:10 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : Name("") {}

Zombie::Zombie(std::string zombieName) : Name(zombieName) {}

void Zombie::announce(void){
	std::cout << Name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void){
		std::cout << Name << " is being destroyed!" << "\n"<< std::endl;
}

void Zombie::setName(std::string zombieName) {
	Name = zombieName;
}
