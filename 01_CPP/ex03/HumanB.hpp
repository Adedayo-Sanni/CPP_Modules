/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:19:47 by asanni            #+#    #+#             */
/*   Updated: 2025/01/09 20:06:48 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string Name;
		Weapon* Arma;
	
	public:
	HumanB(std::string name);
	~HumanB();
	void attack();
	void setWeapon(Weapon &weapon);
};

#endif
