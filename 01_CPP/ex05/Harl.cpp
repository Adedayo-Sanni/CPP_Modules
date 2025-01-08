/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:07:33 by asanni            #+#    #+#             */
/*   Updated: 2025/01/08 20:20:14 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){};
Harl::~Harl(){};

void Harl::debug(void){
	std::cout << "I love having extra bacon for my double-cheese burger."
	"I really do!" << std::endl;
}
	
void Harl::info(void){
	std::cout << "I cannot believe adding extra bacon costs more money."
	"You didnt put enough bacon in my burger! If you did, I wouldnt be asking"
	"for more!" << std::endl;
}
	
void Harl::warning(void){
	std::cout << "I think I deserve to have some extra bacon for free."
	"Ive been coming for years whereas you started working here since last"
	"month." << std::endl;
}
	
void Harl::error(void){
	std::cout << "I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG","INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for (size_t i = 0; i < 4; ++i) {
		if (levels[i] == level) {
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "[UNKNOWN] Level not recognized." << std::endl;
}

