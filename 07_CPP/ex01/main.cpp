/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:40:19 by asanni            #+#    #+#             */
/*   Updated: 2025/10/25 12:56:15 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// Imprime um número inteiro (somente leitura)
void printInt(const int &n)
{
    std::cout << n << " ";
}

// Soma 10 a um número inteiro (modifica o valor)
void addTen(int &n)
{
    n += 10;
}

//  Imprime uma string
void printString(const std::string &s)
{
    std::cout << s << " ";
}

// 4️Coloca uma string em maiúsculas (modifica o valor)
void toUpper(std::string &s)
{
    for (std::string::iterator it = s.begin(); it != s.end(); ++it)
        *it = std::toupper(*it);
}

// =====================================================

int main(void)
{
  std::cout << MAGENTA << "___________int array________________" << RESET <<std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    const unsigned int len = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Array original: ";
    ::iter(numbers, len, printInt);
    std::cout << std::endl;

    // Aplica addTen em cada elemento → modifica o array
    ::iter(numbers, len, addTen);

    std::cout << "Após addTen: ";
    ::iter(numbers, len, printInt);
    std::cout << std::endl << std::endl;

    std::cout << MAGENTA << "___________const int array________________" << RESET <<std::endl;
  
    const int constNumbers[] = {10, 20, 30};
    const unsigned int len2 = sizeof(constNumbers) / sizeof(constNumbers[0]);

    std::cout << "Array const: ";
    ::iter(constNumbers, len2, printInt); // só leitura
    std::cout << std::endl << std::endl;

    std::cout << MAGENTA << "___________string array________________" << RESET <<std::endl;
    std::string words[] = {"ola", "mundo", "c++"};
    const unsigned int len3 = sizeof(words) / sizeof(words[0]);

    std::cout << "Strings originais: ";
    ::iter(words, len3, printString);
    std::cout << std::endl;

    // Coloca tudo em maiúsculas
    ::iter(words, len3, toUpper);

    std::cout << "Strings em maiúsculas: ";
    ::iter(words, len3, printString);
    std::cout << std::endl;

    return 0;
}
