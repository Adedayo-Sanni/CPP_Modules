/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:22:58 by asanni            #+#    #+#             */
/*   Updated: 2024/12/18 20:35:23 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Zombie
{
	private:
		std::string Name;
	
	public:
		Zombie(void);
		Zombie(std::string zombieName);
		void announce(void);
		~Zombie(void);
		void setName(std::string zombieName);
};
Zombie* zombieHorde(int N, std::string name);
void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
