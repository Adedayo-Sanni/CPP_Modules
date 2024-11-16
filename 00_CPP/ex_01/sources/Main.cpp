/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:22:46 by asanni            #+#    #+#             */
/*   Updated: 2024/11/16 15:56:33 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"

#include <iostream>
#include <string>

// int main(void)
// {
// 	std::string input;
// 	PhoneBook phonebook;

// 	std::cout << "Welcome to your Phonebook!" << std::endl;
// 	while (true)
// 	{
// 		std::cout << "Select your Action: ADD, SEARCH, EXIT" << std::endl;
// 		std::getline(std::cin, input);

// 		if (!input.compare("ADD")){
// 			system("clear");
// 			// std::cout << "\033[2J\033[H";
// 			phonebook.addContact();
// 		}
// 		else if (!input.compare("SEARCH")){
// 			// std::cout << "\033[2J\033[H";
// 			phonebook.searchContact();
// 		}
// 		else if (!input.compare("EXIT"))
// 			break;
// 		else if (!input.empty())
// 			std::cout << "\nInvalid option. Please try again.\n" << std::endl;
// 	}

// 	return 0;
// }
// arrumar o erro do ctrl D - fzr so sair sem loop infinito


int main(void)
{
	std::string input;
	PhoneBook phonebook;

	std::cout << "Welcome to your Phonebook!" << std::endl;
	while (true)
	{
		std::cout << "Select your Action: ADD, SEARCH, EXIT" << std::endl;
		
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof()) {
				std::cout << "EOF reached. Exiting program..." << std::endl;
				break;
			} else {
				std::cout << "Input error. Exiting." << std::endl;
				break;
			}
		}
		if (!input.compare("ADD")){
			std::cout << "\033[2J\033[H"; 
			phonebook.addContact();
		}
		else if (!input.compare("SEARCH")){
			std::cout << "\033[2J\033[H";
			phonebook.searchContact();
		}
		else if (!input.compare("EXIT")){
			std::cout << "\033[2J\033[H";
			break; 
		}
		else if (!input.empty())
			std::cout << "\nInvalid option. Please try again.\n" << std::endl;
	}
	return 0;
}
