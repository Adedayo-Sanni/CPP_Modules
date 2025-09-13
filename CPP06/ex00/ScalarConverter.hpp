/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:01:32 by asanni            #+#    #+#             */
/*   Updated: 2025/09/13 19:27:52 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#include <iostream>

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter& operator=(ScalarConverte &other);
	~ScalarConverter();
	
	public:
	//method
	static void convert(std::string cpp_literal);
};

#endif
