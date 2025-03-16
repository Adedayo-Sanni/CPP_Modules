/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:06:33 by asanni            #+#    #+#             */
/*   Updated: 2025/03/16 16:59:50 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(3.14f); 
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed h = Fixed::min(b, c);
    std::cout << "min(b, c): " << h << " | Esperado: 3.14" << std::endl;

    Fixed i = Fixed::max(b, c);
    std::cout << "max(b, c): " << i << " | Esperado: 42" << std::endl;
	return 0;
	}
