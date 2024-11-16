/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:55:14 by asanni            #+#    #+#             */
/*   Updated: 2024/11/16 15:58:04 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

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
//pragma é uma intrição pro compilador 
