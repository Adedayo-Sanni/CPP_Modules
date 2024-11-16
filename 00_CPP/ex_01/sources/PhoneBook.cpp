/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:58:16 by asanni            #+#    #+#             */
/*   Updated: 2024/11/16 15:57:12 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {} 

std::string PhoneBook::getInfo(std::string prompt){
	std::string info;
	
	std::cout << prompt << std::endl;
	std::getline(std::cin, info);
	while (info.empty()) {
		std::cout << "Input cannot be empty. Type again." << std::endl;
		std::getline(std::cin, info);
	}
	return(info);
}

void PhoneBook::addContact(){
	contact[index].setFirstName(getInfo("Enter the name:"));
	contact[index].setLastName(getInfo("Enter the lastname:"));
	contact[index].setNickName(getInfo("Enter the nickname"));
	contact[index].setPhoneNumber(getInfo("Enter the phonenumber"));
	contact[index].setDarkestSecret(getInfo("Enter the darkestsecret"));

	index = (index + 1) % 8;
}

int returnIndex() {
	std::string input;
	int index;

	while (true) {
		std::cout << "Type the desired contact (1-8):" << std::endl;
		std::getline(std::cin, input);
		
		
		std::istringstream iss(input);
		if (iss >> index && index >= 1 && index <= 8) {
			return index - 1;
		}
		std::cout << "Invalid input. Please enter a number between 1 and 8." << std::endl;
	}
}

std::string formatColumn(const std::string& text, unsigned width) {
	if (text.length() > width)
		return text.substr(0, width - 1) + "."; 
	return (text);
}

void PhoneBook::searchContact() {
	
	for (int i = 0; i < index; i++){
		std::cout << std::setw(10) << (i + 1) << "|";
		std::cout << std::setw(10) << formatColumn(contact[i].getFirstName(), 10) << "|";
		std::cout << std::setw(10) << formatColumn(contact[i].getLastName(), 10) << "|";
		std::cout << std::setw(10) << formatColumn(contact[i].getNickName(), 10) << "|" << std::endl;
		
	}

	int index = returnIndex();
	std::cout << "Name:" << contact[index].getFirstName() << std::endl;
	std::cout << "Lastname:" << contact[index].getLastName() << std::endl;
	std::cout << "Nickname:" << contact[index].getNickName() << std::endl;
	std::cout << "Phonenumber:" << contact[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret:" << contact[index].getDarkestSecret() << "\n\n" << std::endl;
	
	
}

void PhoneBook::exitPhone(){
	return ;
}
