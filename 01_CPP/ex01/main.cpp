/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:33:00 by asanni            #+#    #+#             */
/*   Updated: 2024/12/14 15:24:10 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int N = 5;
	Zombie* horde = zombieHorde(N, "Chad");

	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
