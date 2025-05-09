/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:18:58 by asanni            #+#    #+#             */
/*   Updated: 2025/04/13 19:27:54 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#include <iostream>

class Animal{
	protected:
	std::string type;

	public:
	Animal();
	Animal(const Animal &obj);
	Animal& operator=(Animal const &obj);
	virtual ~Animal();
	
	virtual void makeSound() const;
	std::string getType() const;
};

#endif


