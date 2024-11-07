/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:58:16 by asanni            #+#    #+#             */
/*   Updated: 2024/11/07 20:48:04 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

void PhoneBook::addContact(){
	std::string firstname;
	std::cout << "Enter the name" << std::endl;
	std::getline(std::cin, firstname); 
	this->contact->setFirstName(firstname);

	std::string lastname;
	std::cout << "Enter the lastname" << std::endl;
	std::getline(std::cin, lastname); 
	
	std::string nickname;
	std::cout << "Enter the nickname" << std::endl;
	std::getline(std::cin, nickname); 

	std::string phonenumber;
	std::cout << "Enter the phonenumber" << std::endl;
	std::getline(std::cin, phonenumber);
	
	std::string darkestsecret;
	std::cout << "Enter the darkestsecret" << std::endl;
	std::getline(std::cin, darkestsecret); 

	std::cout << contact->getFirstName() << std::endl;
	
	//depois criar o contato
}
void PhoneBook::searchContact(){
	//Display the saved contacts as a list of 4 columns:
	//index, first name, last name and nickname.

	//pedir o index do conato que a pessoa quer ver
	//se estiver errado ou ainda não existir-> msg de erro
}
void PhoneBook::exitPhone(){
	return ;
}
