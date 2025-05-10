/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:40:59 by asanni            #+#    #+#             */
/*   Updated: 2025/05/10 11:58:15 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	std::cout << GREEN << "===== Teste: Criação válida =====" << RESET << std::endl;
	try {
		Bureaucrat b1("Alice", 42);
		std::cout << b1 << std::endl;

		std::cout << GREEN << "Incrementando nota..." << RESET << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;

		std::cout << GREEN << "Decrementando nota..." << RESET << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << GREEN << "===== Teste: Nota muito alta (grade < 1) =====" << RESET << std::endl;
	try {
		Bureaucrat b2("Bob", 0); // Deve lançar exceção
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << GREEN << "===== Teste: Nota muito baixa (grade > 150) =====" << RESET << std::endl;
	try {
		Bureaucrat b3("Charlie", 200); // Deve lançar exceção
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << GREEN << "===== Teste: Incrementar além do limite (grade 1) =====" << RESET << std::endl;
	try {
		Bureaucrat b4("Diana", 1);
		std::cout << b4 << std::endl;
		b4.incrementGrade(); // Deve lançar exceção
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << GREEN << "===== Teste: Decrementar além do limite (grade 150) =====" << RESET << std::endl;
	try {
		Bureaucrat b5("Eve", 150);
		std::cout << b5 << std::endl;
		b5.decrementGrade(); // Deve lançar exceção
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	return 0;
}
