/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:55:14 by asanni            #+#    #+#             */
/*   Updated: 2024/11/16 16:11:30 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <sstream>

class PhoneBook
{
	private:
		Contact contact[8];
		int index;

	public:
		PhoneBook();
		std::string getInfo(std::string prompt);
		void addContact();
		void searchContact();
		void exitPhone();
};

#endif
