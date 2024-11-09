/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:55:14 by asanni            #+#    #+#             */
/*   Updated: 2024/11/09 20:29:55 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
	Contact contact[8];
	int index;

	std::string getInfo(std::string prompt){
	std::string info;
	
	std::cout << prompt << std::endl;
	std::getline(std::cin, info);
	while (info.empty()) {
		std::cout << "Input cannot be empty. Type again." << std::endl;
		std::getline(std::cin, info);
	}
	return(info);
}

	public:
	void addContact();
	void searchContact();
	void exitPhone();
};

#endif
