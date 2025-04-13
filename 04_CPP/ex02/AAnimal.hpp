/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:18:58 by asanni            #+#    #+#             */
/*   Updated: 2025/04/13 19:27:43 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#include <iostream>

class AAnimal{
	protected:
	std::string type;

	public:
	AAnimal();
	AAnimal(const AAnimal &obj);
	AAnimal& operator=(AAnimal const &obj);
	virtual ~AAnimal();
	
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif


