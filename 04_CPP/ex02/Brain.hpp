/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:03:44 by asanni            #+#    #+#             */
/*   Updated: 2025/04/13 16:20:24 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
	private:
	std::string ideas[100];

	public:
	Brain();
	Brain(const Brain &obj);
	Brain& operator=(Brain const &obj);
	virtual ~Brain();

	std::string getIdea( int i);
	void setIdea(std::string thought, int i);
};

#endif
