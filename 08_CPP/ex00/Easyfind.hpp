/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:13:17 by asanni            #+#    #+#             */
/*   Updated: 2025/11/01 18:03:44 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

# include <algorithm>
# include <iostream>
# include <stdexcept>

	template <typename T>
	typename T::iterator easyfind(T& container, int value)
	{
		typename T::iterator it = std::find(container.begin(), container.end(), value);
		if (it == container.end())
			throw std::runtime_error("Value not found");
		return it;
	}

	#endif
