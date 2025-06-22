/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:33:00 by asanni            #+#    #+#             */
/*   Updated: 2025/01/09 17:58:52 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	randomChump("Troy");
	randomChump("Sharpay");
	Zombie* Gabriella = newZombie("Gabriella");
	Gabriella->announce();
	delete Gabriella;
	Zombie* nameless = new Zombie;
	nameless->announce();
	delete nameless;
	return 0;
}
