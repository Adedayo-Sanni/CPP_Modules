/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:42:10 by asanni            #+#    #+#             */
/*   Updated: 2025/05/13 17:47:05 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 50);
		Bureaucrat alice("Alice", 1); // alta patente

		Form taxForm("Tax Form", 25, 10);
		Form vacationForm("Vacation Request", 75, 50);

		std::cout << YELLOW << "\n--- Initial Forms ---\n" << RESET;
		std::cout << taxForm << std::endl;
		std::cout << vacationForm << std::endl;

		std::cout << BLUE << "\n--- Bob tries to sign Tax Form ---\n" << RESET;
		bob.signForm(taxForm); // Deve falhar (grade 50 < 25)

		std::cout << BLUE << "\n--- Alice tries to sign Tax Form ---\n" << RESET;
		alice.signForm(taxForm); // Deve funcionar

		std::cout << BLUE << "\n--- Bob tries to sign Vacation Request ---\n" << RESET;
		bob.signForm(vacationForm); // Deve funcionar

		std::cout << GREEN << "\n--- Final Forms ---\n" << RESET;
		std::cout << taxForm << std::endl;
		std::cout << vacationForm << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception caught in main: " << e.what() << RESET << std::endl;
	}
	return 0;
}
