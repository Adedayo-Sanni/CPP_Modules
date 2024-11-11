/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:22:46 by asanni            #+#    #+#             */
/*   Updated: 2024/11/11 19:44:45 by asanni           ###   ########.fr       */
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

	std::cout << "Welcome to your Phonebook!" << std::endl;
	while (true)
	{
		std::cout << "Select your Action: ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, input);

		if (!input.compare("ADD")){
			system("clear"); 
			phonebook.addContact();
		}
		else if (!input.compare("SEARCH")){
			phonebook.searchContact();
		}
		else if (!input.compare("EXIT")){
			break;
		}
		else
			std::cout << "\nInvalid option. Please try again.\n" << std::endl;
	}

	return 0;
}
