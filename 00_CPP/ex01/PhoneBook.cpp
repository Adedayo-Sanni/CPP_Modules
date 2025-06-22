/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:58:16 by asanni            #+#    #+#             */
/*   Updated: 2024/11/23 18:10:06 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}
int contacts;

std::string PhoneBook::getInfo(std::string prompt) {
    std::string info;

	std::cout << prompt << std::endl;
	while (true) {
		std::getline(std::cin, info);
		if (std::cin.eof()) { 
			std::cout << "\nEOF detected. Exiting program." << std::endl;
			exit(0);
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cout << "Input error. Please try again." << std::endl;
		} else if (info.empty()) {
			std::cout << "Input cannot be empty. Type again." << std::endl;
		} else {
			break;
		}
	}
	return info;
}


void PhoneBook::addContact(){
	contact[index].setFirstName(getInfo("Enter the name:"));
	contact[index].setLastName(getInfo("Enter the lastname:"));
	contact[index].setNickName(getInfo("Enter the nickname"));
	contact[index].setPhoneNumber(getInfo("Enter the phonenumber"));
	contact[index].setDarkestSecret(getInfo("Enter the darkestsecret"));
	
	if (contacts < 8){
		contacts++;
	}
	index = (index + 1) % 8;
}

int returnIndex() {
	std::string input;
	int index;

	while (true) {
		std::cout << "Type the desired contact (1-8):" << std::endl;
		std::getline(std::cin, input);

		if (std::cin.eof()) {
			std::cout << "\nEOF detected. Exiting program." << std::endl;
			exit(0);
		}

		if (std::cin.fail()) {
			std::cin.clear();
			std::cout << "Input error. Please try again." << std::endl;
			continue;
		}

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
	std::cout << std::setw(10) << formatColumn("index", 10) << "|";
	std::cout << std::setw(10) << formatColumn("Name", 10) << "|";
	std::cout << std::setw(10) << formatColumn("Surname", 10) << "|";
	std::cout << std::setw(10) << formatColumn("Nickname", 10) << "|" << std::endl;
	for (int i = 0; i < contacts; i++){
		std::cout << std::setw(10) << (i + 1) << "|";
		std::cout << std::setw(10) << formatColumn(contact[i].getFirstName(), 10) << "|";
		std::cout << std::setw(10) << formatColumn(contact[i].getLastName(), 10) << "|";
		std::cout << std::setw(10) << formatColumn(contact[i].getNickName(), 10) << "|" << std::endl;
		
	}

	int index = returnIndex();
	if (contact[index].getFirstName().empty()){
		std::cout << "Contact does not exist yet" << std::endl;
	} else {
		std::cout << "Name: " << contact[index].getFirstName() << std::endl;
		std::cout << "Lastname: " << contact[index].getLastName() << std::endl;
		std::cout << "Nickname: " << contact[index].getNickName() << std::endl;
		std::cout << "Phonenumber: " << contact[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contact[index].getDarkestSecret() << "\n\n" << std::endl;
	}
}

void PhoneBook::exitPhone(){
	return ;
}
