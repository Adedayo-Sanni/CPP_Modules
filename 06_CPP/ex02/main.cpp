/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:51:08 by asanni            #+#    #+#             */
/*   Updated: 2025/10/20 21:09:44 by asanni           ###   ########.fr       */
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
    Base* ptr = &p; // ✅ apenas pegando o endereço da referência, não um novo ponteiro
    if (dynamic_cast<A*>(ptr))
        std::cout << "Identified (reference): A" << std::endl;
    else if (dynamic_cast<B*>(ptr))
        std::cout << "Identified (reference): B" << std::endl;
    else if (dynamic_cast<C*>(ptr))
        std::cout << "Identified (reference): C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

int main() {
    Base* base = generate();

    identify(base);
    identify(*base);

    delete base;
    return 0;
}
