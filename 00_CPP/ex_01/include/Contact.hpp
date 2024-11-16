/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:21:36 by asanni            #+#    #+#             */
/*   Updated: 2024/11/16 15:57:51 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string Nickname;
		std::string PhoneNumber;
		std::string DarkestSecret;

	public:
		void setFirstName(const std::string& firstName);
		void setLastName(const std::string& lastName);
		void setNickName(const std::string& nickeName);
		void setPhoneNumber(const std::string& phoneNumber);
		void setDarkestSecret(const std::string& darkestSecret);

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
};

#endif
