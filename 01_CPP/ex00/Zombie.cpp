/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:16:48 by asanni            #+#    #+#             */
/*   Updated: 2024/11/25 18:45:06 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::setName(std::string name){
	Name = name;
}

std::string Zombie::getName(){
	return(Name);
}

void Zombie:: announce(void){
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}



