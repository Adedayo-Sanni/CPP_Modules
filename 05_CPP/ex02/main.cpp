/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:02:57 by asanni            #+#    #+#             */
/*   Updated: 2025/06/08 18:48:11 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main() {
	try {
		Bureaucrat junior("Bob", 70);
		Bureaucrat senior("Alice", 45); 

		// Aqui o argumento é o "alvo" do formulário
		RobotomyRequestForm robotomyForm("Bumblee");
		
		std::cout << BLUE << "\n--- Bob tries to sign Pardon Form ---\n" << RESET;
		junior.signForm(robotomyForm);
		junior.executeForm(robotomyForm);

		std::cout << BLUE << "\n--- Alice tries to sign Pardon Form ---\n" << RESET;
		senior.signForm(robotomyForm);
		senior.executeForm(robotomyForm);

	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception caught in main: " << e.what() << RESET << std::endl;
	}
	
	try {
		Bureaucrat manager("Frank", 15);
		Bureaucrat generalmanager("Amanda", 1); 

		// Aqui o argumento é o "alvo" do formulário
		PresidentialPardonForm pardonForm("Optimus prime");
		
		std::cout << BLUE << "\n--- Frank tries to sign Pardon Form ---\n" << RESET;
		manager.signForm(pardonForm); 
		manager.executeForm(pardonForm);

		std::cout << BLUE << "\n--- Amanda tries to sign Pardon Form ---\n" << RESET;
		generalmanager.signForm(pardonForm);
		generalmanager.executeForm(pardonForm);

	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception caught in main: " << e.what() << RESET << std::endl;
	}
	return 0;
}
