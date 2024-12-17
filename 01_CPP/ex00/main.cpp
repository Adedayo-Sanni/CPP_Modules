/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:33:00 by asanni            #+#    #+#             */
/*   Updated: 2024/11/27 18:01:56 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	randomChump("Troy");
	randomChump("Sharpay");
	Zombie* gabriella = newZombie("Gabriella");
	gabriella->announce();
	delete gabriella;
	Zombie* Chad = newZombie("Chad");
	Chad->announce();
	delete Chad;
	return 0;
}
