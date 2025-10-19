/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:01:32 by asanni            #+#    #+#             */
/*   Updated: 2025/10/19 19:17:13 by asanni           ###   ########.fr       */
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
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <cmath>


// literals are values that the compiler recognizes directly 
//ex: 'a' 97, 4.2f 4.2

/********************************************/

//pseudo literals are especial floating point values that represent "non numerical" 
//or "outside of regular number intervals"
//ex:
//inf / inff = infinity / float infinity (can be + or -)
//nan / nanf = not a number / not a number flot


class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	ScalarConverter &operator=(const ScalarConverter &);
	~ScalarConverter();

	static bool isCharLiteral(const std::string &literal);
  static bool isIntLiteral(const std::string &literal);
  static bool isFloatLiteral(const std::string &literal);
  static bool isDoubleLiteral(const std::string &literal);
  static bool isPseudoLiteral(const std::string &literal);
	
	public:
	//method
	static void convert(const std::string &literal);
};

#endif
