/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:44:42 by asanni            #+#    #+#             */
/*   Updated: 2024/12/17 20:26:59 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostcqe	q	eode  eam>
wetwetwetwetwetwret
class Weapon
{
	private:
		st	qeq	eq	qw::string type;
	
	public:
		const std::string& getType() const;
		void setType(const std::string& type);
};

#endif

Implement a Weapon class that has:
• A private attribute type, which is a string.
• A getType() member function that returns a const reference to type.
• A setType() member function that sets type using the new one passed as parameter.
