/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:18:58 by asanni            #+#    #+#             */
/*   Updated: 2025/04/05 20:14:50 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
	protected:
	std::string type;

	public:
	Animal();
	Animal(const Animal &obj);
	Animal& operator=(Animal const &obj);
	~Animal();
	
	virtual void makeSound() const;
	std::string getType() const;
};

#endif


