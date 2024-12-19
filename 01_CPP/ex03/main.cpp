/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:02:46 by asanni            #+#    #+#             */
/*   Updated: 2024/12/18 21:11:57 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

int main(void)
{
	Weapon Arma("pistola");
	std::cout << Arma.getType() << std::endl;
	HumanA guerreiro ("Chad", Arma);
	guerreiro.Attack();
}
