/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:54:54 by asanni            #+#    #+#             */
/*   Updated: 2025/04/13 19:18:15 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
#define Dog_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{
	private:
	Brain* brain;

	public:
	Dog();
	Dog(const Dog &obj);
	Dog& operator=(Dog const &obj);
	~Dog();

	void makeSound() const;
	std::string getIdea(int i) const;
	void setIdea(std::string idea, int i);
};

#endif
