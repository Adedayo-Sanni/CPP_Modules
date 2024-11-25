/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:22:58 by asanni            #+#    #+#             */
/*   Updated: 2024/11/25 18:43:07 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string Name;
	
	public:
		void setName(std::string name);
		std::string getName();
		void announce(void);
		void randomChump( std::string name );
		Zombie* newZombie( std::string name );
};

#endif
