/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:02:46 by asanni            #+#    #+#             */
/*   Updated: 2025/01/09 19:48:27 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		HumanA john;
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	
	{
		Weapon gun = Weapon("Machine Gun");
		HumanB jim("Jim");
		jim.setWeapon(gun);
		jim.attack();
		gun.setType("some other type of gun");
		jim.attack();
	}
	return 0;
}
