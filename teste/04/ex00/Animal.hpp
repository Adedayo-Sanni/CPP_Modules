/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:50:59 by asanni            #+#    #+#             */
/*   Updated: 2025/06/22 17:09:23 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
	protected:
		std::string type;

	public:
		Animal(std::string name);
		Animal(const Animal &other);
		Animal& operator=(const Animal &other);
		~Animal();
		std::string makeSound();
	
};

#endif
