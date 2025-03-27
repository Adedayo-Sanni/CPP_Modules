/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:31:17 by asanni            #+#    #+#             */
/*   Updated: 2025/03/27 17:15:05 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

class ScavTrap : public ClapTrap {
public:
	ScavTrap(const std::string& name);
	~ScavTrap();
	void attack(const std::string& target) override;
	void guardGate();
};

#endif

