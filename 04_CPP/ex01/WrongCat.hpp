/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:53:41 by asanni            #+#    #+#             */
/*   Updated: 2025/04/12 16:54:56 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
	WrongCat();
	WrongCat(const WrongCat &obj);
	WrongCat& operator=(WrongCat const &obj);
	~WrongCat();

	void makeSound() const;
};

#endif
