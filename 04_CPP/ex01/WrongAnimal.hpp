/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:18:58 by asanni            #+#    #+#             */
/*   Updated: 2025/04/12 12:27:34 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
	protected:
	std::string type;

	public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &obj);
	WrongAnimal& operator=(WrongAnimal const &obj);
	~WrongAnimal();
	
	void makeSound() const;
	std::string getType() const;
};

#endif


