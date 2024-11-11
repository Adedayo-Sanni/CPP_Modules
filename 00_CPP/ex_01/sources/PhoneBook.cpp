/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:58:16 by asanni            #+#    #+#             */
/*   Updated: 2024/11/11 19:43:42 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

void PhoneBook::addContact(){
	PhoneBook::index = 0;
	contact->setFirstName(getInfo("Enter the name:"));
	contact->setLastName(getInfo("Enter the lastname:"));
	contact->setNickName(getInfo("Enter the nickname"));
	contact->setPhoneNumber(getInfo("Enter the phonenumber"));
	contact->setDarkestSecret(getInfo("Enter the darkestsecret"));

	index = (index + 1) % 8;
}

int returnIndex()
{
	std::string prompt;
	int index;
	while (true){
		std::cout << "Type the desired contact" << std::endl;
		std::cin >> index;
		
		if (std::cin.fail() || index < 1 || index > 8){
			std::cout << "Invalid input. Please enter a number between 1 and 8." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		}
		else
			return (index - 1);
	}
}
std::string formatColumn(const std::string& text, unsigned width) {
	if (text.length() > width)
		return text.substr(0, width - 1) + "."; 
	return (text);
}

void PhoneBook::searchContact() {
	int index = returnIndex();
	
	std::cout << std::setw(10) << (index + 1) << "|";
	std::cout << std::setw(10) << formatColumn(contact[index].getFirstName(), 10) << "|";
	std::cout << std::setw(10) << formatColumn(contact[index].getLastName(), 10) << "|";
	std::cout << std::setw(10) << formatColumn(contact[index].getNickName(), 10) << "|" << std::endl;
	
}

void PhoneBook::exitPhone(){
	return ;
}

// setw example
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw

int meain () {
  std::cout << std::setw(10);
  std::cout << "oi";
  std::cout << std::setw(10);
  std::cout << "tchau" << std::endl;
  return 0;
}
