/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:22:46 by asanni            #+#    #+#             */
/*   Updated: 2024/11/05 19:55:57 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"

int main(void)
{
	std::string input;
	while (42)
	{
		std::cout << "Welcome to your Phonebook!" << std::endl;
		std::cout << "Select your Action: ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, input);
	}
}
