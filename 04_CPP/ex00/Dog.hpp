/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:54:54 by asanni            #+#    #+#             */
/*   Updated: 2025/04/05 20:15:52 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"

class Dog : public Animal{
	public:
	Dog();
	Dog(const Dog &obj);
	Dog& operator=(Dog const &obj);
	~Dog();

	void makeSound() const;
};

#endif
