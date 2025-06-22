/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:12:11 by asanni            #+#    #+#             */
/*   Updated: 2025/06/22 16:17:17 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::string name = "Socorro";
	ClapTrap A(name);
	ClapTrap B("Filó");
	
	A.attack("Filó");
	B.takeDamage(1);
	B.attack("Socorro");
	B.beRepaired(1);
}
