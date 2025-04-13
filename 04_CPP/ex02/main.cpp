/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:11:04 by asanni            #+#    #+#             */
/*   Updated: 2025/04/13 19:42:56 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main() {
	
	// Example to show it is not possible to instantiate a AAnimal
	// AAnimal tigrinho;
	// AAnimal tigrinho = new AAnimal

	std::cout << "=== Creating Cat ===" << std::endl;
	Cat Cat;
	Cat.setIdea("Eat fish", 0);
	Cat.setIdea("Sleep at the couch", 1);

	std::cout << "\n=== Verificando ideias ===" << std::endl;
	std::cout << GREEN << "Idea[0]: " << Cat.getIdea(0) << RESET << std::endl;
	std::cout << GREEN << "Idea[1]: " << Cat.getIdea(1) << RESET << std::endl;

	std::cout << "=== Creating Dog ===" << std::endl;
	Dog Dog;
	Dog.setIdea("bark at other dogs", 0);
	Dog.setIdea("Sleep at the sun", 1);

	std::cout << "\n=== Verificando ideias ===" << std::endl;
	std::cout << MAGENTA << "Idea[0]: " << Dog.getIdea(0) << RESET << std::endl;
	std::cout << MAGENTA << "Idea[1]: " << Dog.getIdea(1) << RESET << std::endl;
	
	return 0;
}
