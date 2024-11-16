/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:55:44 by asanni            #+#    #+#             */
/*   Updated: 2024/11/16 16:57:55 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(const std::string& firstName){
	FirstName = firstName;
}
void Contact::setLastName(const std::string& lastName){
	LastName = lastName;
}
void Contact::setNickName(const std::string& nickName){
	Nickname = nickName;
}
void Contact::setPhoneNumber(const std::string& phoneNumber){
	PhoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(const std::string& darkestSecret){
	DarkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const{
	return (FirstName);
}
std::string Contact::getLastName() const{
	return (LastName);
}
std::string Contact::getNickName() const{
	return (Nickname);
}
std::string Contact::getPhoneNumber() const{
	return (PhoneNumber);
}
std::string Contact::getDarkestSecret() const{
	return (DarkestSecret);
}
