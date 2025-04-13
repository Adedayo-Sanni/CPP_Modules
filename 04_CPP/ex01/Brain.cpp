/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:33:34 by asanni            #+#    #+#             */
/*   Updated: 2025/04/13 16:31:00 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain has been created!" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain has been copied!" << std::endl;
	for (int i = 0; i < 100; ++i) {
		ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assing operator called" << std::endl;
	
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain has been destructed" << std::endl;
}

std::string Brain::getIdea(int i){
	if (i >= 0 && i < 100)
		return ideas[i];
	return "";
}

void Brain::setIdea(std::string thought, int i) {
	if (i >= 0 && i < 100)
		ideas[i] = thought;
}
