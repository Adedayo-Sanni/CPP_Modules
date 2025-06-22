/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:22:58 by asanni            #+#    #+#             */
/*   Updated: 2025/01/09 17:48:32 by asanni           ###   ########.fr       */
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
		Zombie();
		~Zombie();
		Zombie(std::string zombieName);
		void announce(void);
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
