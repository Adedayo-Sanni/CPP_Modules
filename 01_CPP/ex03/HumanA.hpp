/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:52:35 by asanni            #+#    #+#             */
/*   Updated: 2024/12/18 21:14:53 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
	std::string Name;
	Weapon& Arma;
	
	public:
	HumanA(std::string name, Weapon &arma);
	~HumanA();
	void Attack();
};

#endif


// They also have a member function attack() that displays
// <name> attacks with their <weapon type>
// HumanA takes the Weapon in its constructor and will always be armed.
