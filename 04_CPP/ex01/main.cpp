/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:11:04 by asanni            #+#    #+#             */
/*   Updated: 2025/04/13 19:37:44 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"


int main() {
	std::cout << "=== Creating original Cat ===" << std::endl;
	Cat originalCat;
	originalCat.setIdea("Eat fish", 0);
	originalCat.setIdea("Sleep at the couch", 1);

	std::cout << "\n=== Creating copy (deep copy) ===" << std::endl;
	Cat copiedCat = originalCat;

	std::cout << "\n=== Changing idea ===" << std::endl;
	originalCat.setIdea("Hunt small animals", 0);

	std::cout << "\n=== Verificando ideias ===" << std::endl;
	std::cout << GREEN << "Original[0]: " << originalCat.getIdea(0) << RESET << std::endl;
	std::cout << GREEN << "Original[1]: " << originalCat.getIdea(1) << RESET << std::endl;
	std::cout << GREEN << "Copy   [0]: " << copiedCat.getIdea(0) << RESET << std::endl;
	std::cout << GREEN << "Copy   [1]: " << copiedCat.getIdea(1) << RESET << std::endl;

	std::cout << "\n=== Destruindo os objetos ===" << std::endl;

	std::cout << "=== Creating original ===" << std::endl;
	Dog originalDog;
	originalDog.setIdea("bark at other dogs", 0);
	originalDog.setIdea("Sleep at the sun", 1);

	std::cout << "\n=== Creating copy (deep copy) ===" << std::endl;
	Dog copiedDog = originalDog; 

	std::cout << "\n=== Changing idea ===" << std::endl;
	originalDog.setIdea("Run after own tail", 0);

	std::cout << "\n=== Verificando ideias ===" << std::endl;
	std::cout << MAGENTA << "Original[0]: " << originalDog.getIdea(0) << RESET << std::endl;
	std::cout << MAGENTA << "Original[1]: " << originalDog.getIdea(1) << RESET << std::endl;
	std::cout << MAGENTA << "Copy   [0]: " << copiedDog.getIdea(0) << RESET << std::endl;
	std::cout << MAGENTA << "Copy   [1]: " << copiedDog.getIdea(1) << RESET << std::endl;

	std::cout << "\n=== Destruindo os objetos ===" << std::endl;
	return 0;
	return 0;
}
