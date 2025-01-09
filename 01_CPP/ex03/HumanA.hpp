/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:52:35 by asanni            #+#    #+#             */
/*   Updated: 2025/01/09 19:50:05 by asanni           ###   ########.fr       */
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
	void attack();
};

#endif
