/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:53:41 by asanni            #+#    #+#             */
/*   Updated: 2025/04/13 19:18:10 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
#define Cat_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{
	private:
	Brain* brain;

	public:
	Cat();
	Cat(const Cat &obj);
	Cat& operator=(Cat const &obj);
	~Cat();

	void makeSound() const;
	std::string getIdea(int i) const;
	void setIdea(std::string idea, int i);

};

#endif
