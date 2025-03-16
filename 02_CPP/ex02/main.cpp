/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:06:33 by asanni            #+#    #+#             */
/*   Updated: 2025/03/16 16:12:32 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main() {
	Fixed a;
	Fixed b(42);
	Fixed c(3.14f);

	// Testing comparison operators
	std::cout << "b > c: " << (b > c) << " | Esperado: 1" << std::endl;
	std::cout << "b < c: " << (b < c) << " | Esperado: 0" << std::endl;
	std::cout << "b >= c: " << (b >= c) << " | Esperado: 1" << std::endl;
	std::cout << "b <= c: " << (b <= c) << " | Esperado: 0" << std::endl;
	std::cout << "b == c: " << (b == c) << " | Esperado: 0" << std::endl;
	std::cout << "b != c: " << (b != c) << " | Esperado: 1 \n" << std::endl;

	// Testing Arithmetic operators
	Fixed d = b + c;
	std::cout << "b + c: " << d << " | Esperado: 45.14" << std::endl;

	Fixed e = b - c;
	std::cout << "b - c: " << e << " | Esperado: 38.86" << std::endl;

	Fixed f = b * c;
	std::cout << "b * c: " << f << " | Esperado: 131.88" << std::endl;

	Fixed g = b / c;
	std::cout << "b / c: " << g << " | Esperado: 13.38\n" << std::endl;

	// Testing Increments and decrements
	std::cout << "++b: " << ++b << " | Esperado: 43" << std::endl;
	std::cout << "b++: " << b++ << " | Esperado: 43" << std::endl;
	std::cout << "b (after post-increment): " << b << " | Esperado: 44 \n" << std::endl;

	std::cout << "--b: " << --b << " | Esperado: 43" << std::endl;
	std::cout << "b--: " << b-- << " | Esperado: 43" << std::endl;
	std::cout << "b (after post-decrement): " << b << " | Esperado: 42\n" << std::endl;

	//Testing min and max functions
	Fixed h = Fixed::min(b, c);
	std::cout << "min(b, c): " << h << " | Esperado: 3.14" << std::endl;
	
	Fixed i = Fixed::max(b, c);
	std::cout << "max(b, c): " << i << " | Esperado: 42" << std::endl;

	return 0;
}
