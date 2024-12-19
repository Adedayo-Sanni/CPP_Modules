/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:38:09 by asanni            #+#    #+#             */
/*   Updated: 2024/12/18 21:08:11 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon (std::string type) : Type(type){}

const std::string& Weapon::getType() const{
	return this->Type;
}

void Weapon::setType(const std::string& type){
	this->Type = type;
}

