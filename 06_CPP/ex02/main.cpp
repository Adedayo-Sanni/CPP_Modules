/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:51:08 by asanni            #+#    #+#             */
/*   Updated: 2025/10/25 17:19:07 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base* generate(void) {
    std::srand(std::time(NULL));
    int random = std::rand() % 3;

    switch (random) {
        case 0:
            std::cout << "Generated type: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated type: B" << std::endl;
            return new B();
        default:
            std::cout << "Generated type: C" << std::endl;
            return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Identified (pointer): A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified (pointer): B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified (pointer): C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Identified (reference): A" << std::endl;
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Identified (reference): B" << std::endl;
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Identified (reference): C" << std::endl;
		return;
	} catch (...) {}

	std::cout << "Unknown type" << std::endl;
}

int main() {
	Base* base = generate();

	identify(base);
	identify(*base);

	delete base;
	return 0;
}
