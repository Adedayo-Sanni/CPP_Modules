/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:36:37 by asanni            #+#    #+#             */
/*   Updated: 2025/10/29 19:49:49 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        std::cout << GREEN << "=== Test: Array<int> ===" << RESET << std::endl;
        Array<int> arr1(5);

        for (unsigned int i = 0; i < arr1.size(); ++i)
            arr1[i] = i * 2;

        for (unsigned int i = 0; i < arr1.size(); ++i)
            std::cout << arr1[i] << " ";
        std::cout << std::endl;

        std::cout << GREEN << "=== Test: Array<std::string> ===" << RESET << std::endl;
        Array<std::string> strArr(4);
        strArr[0] = "Hello";
        strArr[1] = "World";
        strArr[2] = "C++";
        strArr[3] = "!!";

        for (unsigned int i = 0; i < strArr.size(); ++i)
            std::cout << strArr[i] << " ";
        std::cout << std::endl;

        std::cout << GREEN << "=== Test: Try Access Invalid Index ===" << RESET << std::endl;
        std::cout << arr1[7] << std::endl; 
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
