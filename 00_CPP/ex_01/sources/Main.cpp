/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:22:46 by asanni            #+#    #+#             */
/*   Updated: 2024/11/07 20:20:34 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"

#include <iostream>
#include <string>

int main(void)
{
	std::string input;
	PhoneBook phonebook;

	while (true)
	{
		std::cout << "Welcome to your Phonebook!" << std::endl;
		std::cout << "Select your Action: ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, input);

		if (!input.compare("ADD"))
			phonebook.addContact();
		else if (!input.compare("SEARCH"))
			phonebook.searchContact();
		else if (!input.compare("EXIT"))
			break;
		else
			std::cout << "\n\nInvalid option. Please try again.\n\n" << std::endl;
	}

	return 0;
}

