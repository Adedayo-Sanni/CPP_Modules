/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:40:59 by asanni            #+#    #+#             */
/*   Updated: 2025/04/19 16:41:25 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("Alice", 1);
		std::cout << a << std::endl;

		a.incrementGrade();

	} catch (std::exception& e) {
		std::cout << "Exceção capturada: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Bob", 151);
	} catch (std::exception& e) {
		std::cout << "Exceção capturada: " << e.what() << std::endl;
	}

	return 0;
}
