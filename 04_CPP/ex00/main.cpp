/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:11:04 by asanni            #+#    #+#             */
/*   Updated: 2025/04/13 19:47:32 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main() {
	std::cout << "\n=== Correct Polymorphism Test ===\n" << std::endl;

	const Animal* meta = new Animal();
	const Animal* lobinho = new Dog();
	const Animal* ravena = new Cat();

	std::cout << "\nTypes:" << std::endl;
	std::cout << MAGENTA <<"Lobinho is a " << lobinho->getType() << RESET << std::endl;
	std::cout << GREEN <<"Ravena is a " << ravena->getType() << RESET << std::endl;

	std::cout << "\nSounds:" << std::endl;
	lobinho->makeSound();
	ravena->makeSound();
	meta->makeSound(); 

	delete meta;
	delete lobinho;
	delete ravena;

	std::cout << "\n=== Wrong Polymorphism Test ===\n" << std::endl;

	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "\nTypes:" << std::endl;
	std::cout << "wrongCat is a " << wrongCat->getType() << std::endl;

	std::cout << "\nSounds:" << std::endl;
	wrong->makeSound();
	wrongCat->makeSound();

	delete wrong;
	delete wrongCat;

	return 0;
}
