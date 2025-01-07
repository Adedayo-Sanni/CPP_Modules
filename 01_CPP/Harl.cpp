/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:07:33 by asanni            #+#    #+#             */
/*   Updated: 2025/01/07 19:12:52 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl"

	Harl::void debug(void){
		std::cout << "I love having extra bacon for my double-cheese burger.
		I really do!" << std::endl;
	}
	
	Harl::void info(void){
		std::cout << "I cannot believe adding extra bacon costs more money.
		You didnt putenough bacon in my burger! If you did, I wouldnt be asking
		for more!" << std::endl;
	}
	
	Harl::void warning(void){
		std::cout << "I think I deserve to have some extra bacon for free.
		Ive been coming for years whereas you started working here since last
		month." << std::endl;
	}
	
	Harl::void error(void){
		std::cout << "I want to speak to the manager now." << std::endl;
	}
