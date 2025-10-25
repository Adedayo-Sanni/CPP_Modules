/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedayo <adedayo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:02:57 by asanni            #+#    #+#             */
/*   Updated: 2025/06/13 13:13:14 by adedayo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"

#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
    Intern intern;

    std::cout << BLUE << "\n--- Criando formulário: shrubbery creation ---\n" << RESET;
    AForm* shrubbery = intern.makeForm("shrubbery creation", "Jardim");
    if (shrubbery) {
        std::cout << GREEN << "Formulário criado: " << shrubbery->getName()
                  << " | Target: " << RESET << std::endl;
        delete shrubbery;
    }

    std::cout << BLUE << "\n--- Criando formulário: robotomy request ---\n" << RESET;
    AForm* robotomy = intern.makeForm("robotomy request", "Bender");
    if (robotomy) {
        std::cout << GREEN << "Formulário criado: " << robotomy->getName()
                  << " | Target: "  << RESET << std::endl;
        delete robotomy;
    }

    std::cout << BLUE << "\n--- Criando formulário: presidential pardon ---\n" << RESET;
    AForm* pardon = intern.makeForm("presidential pardon", "Adedayo");
    if (pardon) {
        std::cout << GREEN << "Formulário criado: " << pardon->getName()
                  << " | Target: " << RESET << std::endl;
        delete pardon;
    }

    std::cout << BLUE << "\n--- Tentando criar formulário inválido ---\n" << RESET;
    AForm* unknown = intern.makeForm("banana split", "ninguém");
    if (!unknown) {
        std::cout << YELLOW << "Formulário não foi criado." << RESET << std::endl;
    }

    return 0;
}
