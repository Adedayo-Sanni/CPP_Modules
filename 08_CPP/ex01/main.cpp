/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:45:33 by asanni            #+#    #+#             */
/*   Updated: 2025/10/29 20:47:59 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int main()
{
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;

		// Teste com grande volume
		Span big(10000);
		std::vector<int> values;
		for (int i = 0; i < 10000; ++i)
			values.push_back(rand());
		big.addNumber(values.begin(), values.end());
		std::cout << "Big shortest: " << big.shortestSpan() << std::endl;
		std::cout << "Big longest: " << big.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Erro: " << e.what() << std::endl;
	}
}

 //main subject

 
/*int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}*/