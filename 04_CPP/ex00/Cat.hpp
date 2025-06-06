/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:53:41 by asanni            #+#    #+#             */
/*   Updated: 2025/04/12 17:39:33 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"

class Cat : public Animal{
	public:
	Cat();
	Cat(const Cat &obj);
	Cat& operator=(Cat const &obj);
	~Cat();

	void makeSound() const;
};

#endif
