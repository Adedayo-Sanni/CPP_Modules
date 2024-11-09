/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:58:16 by asanni            #+#    #+#             */
/*   Updated: 2024/11/09 20:32:26 by asanni           ###   ########.fr       */
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

void PhoneBook::searchContact(){
	//Display the saved contacts as a list of 4 columns:
	//index, first name, last name and nickname.
	std::cout << contact[index].getFirstName() << std::endl;
	std::cout << contact[index].getLastName() << std::endl;
	std::cout << contact[index].getNickName() << std::endl;
	std::cout << contact[index].getPhoneNumber() << std::endl;
	std::cout << contact[index].getDarkestSecret() << std::endl;
	

	//pedir o index do contato que a pessoa quer ver
	//se estiver errado ou ainda não existir-> msg de erro
}
void PhoneBook::exitPhone(){
	return ;
}
