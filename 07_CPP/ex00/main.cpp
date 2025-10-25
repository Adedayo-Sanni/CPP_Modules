/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:42:21 by asanni            #+#    #+#             */
/*   Updated: 2025/10/25 11:56:24 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Whatever.hpp"

int main(void)
{
	std::cout << MAGENTA << "___________ints_________________" << RESET <<std::endl;
	int a = 2;
	int b = 3;
	std::cout << "original:" <<"a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << GREEN << "swap: a = " << a << ", b = " << b << RESET << std::endl;
	std::cout << BLUE << "min(a, b) = " << ::min(a, b) << RESET << std::endl;
	std::cout << YELLOW << "max(a, b) = " << ::max(a, b) << RESET <<std::endl;


	std::cout << MAGENTA << "___________strings_____________" << RESET <<std::endl;
	
	std::string c = "test1";
	std::string d = "test2";
	
	std::cout << "original:" <<"c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << GREEN << "swap: c = " << c << ", d = " << d << RESET << std::endl;
	std::cout << BLUE << "min(c, d) = " << ::min(c, d) << RESET << std::endl;
	std::cout << YELLOW << "max(c, d) = " << ::max(c, d) << RESET << std::endl;


	std::cout << MAGENTA << "___________float________________" << RESET <<std::endl;

	float x = 4.2f, y = 4.8f;
	std::cout << "original:" <<"x = " << x << ", y = " << y << std::endl;
	::swap(x, y);
	std::cout << GREEN << "swap: x = " << x << ", y = " << y << RESET << std::endl;
	std::cout << BLUE << "min(x, y) = " << ::min(x, y) << RESET << std::endl;
	std::cout << YELLOW << "max(x, y) = " << ::max(x, y) << RESET << std::endl;

	return 0;
}