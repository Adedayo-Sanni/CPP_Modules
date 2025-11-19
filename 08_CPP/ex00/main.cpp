/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:13:14 by asanni            #+#    #+#             */
/*   Updated: 2025/11/01 18:05:22 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "Easyfind.hpp" 

int main()
{
	try
	{
		std::cout << GREEN << "=== Testing easyfind with std::vector ===" << RESET << std::endl;
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);

		std::cout << "Searching for 30 in vector..." << std::endl;
		std::vector<int>::iterator itVec = easyfind(vec, 30);
		std::cout << "Value found: " << *itVec << std::endl;

		std::cout << "Searching for 99 in vector..." << std::endl;
		itVec = easyfind(vec, 99); 
		std::cout << "Value found: " << *itVec << std::endl; 
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << GREEN << "=== Testing easyfind with std::list ===" << RESET << std::endl;
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(15);
		lst.push_back(25);
		lst.push_back(35);

		std::cout << "Searching for 15 in list..." << std::endl;
		std::list<int>::iterator itList = easyfind(lst, 15);
		std::cout << "Value found: " << *itList << std::endl;

		std::cout << "Searching for 100 in list..." << std::endl;
		itList = easyfind(lst, 100); // This should throw
		std::cout << "Value found: " << *itList << std::endl; // won't run
	}
	catch (const std::exception& e)
	{
		std::cerr << "List test error: " << e.what() << std::endl;
	}

	return 0;
}

