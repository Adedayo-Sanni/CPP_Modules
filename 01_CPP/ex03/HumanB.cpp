/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:17:54 by asanni            #+#    #+#             */
/*   Updated: 2024/12/18 21:22:10 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): Name(name) {}

HumanB::~HumanB(){
	std::cout << Name << " is being destroyed!" << std::endl;
}

void HumanB::Attack(){
	
}
