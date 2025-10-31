/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:07:52 by asanni            #+#    #+#             */
/*   Updated: 2025/10/31 17:13:00 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << GREEN << "---- Subject tests ----" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Head: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::cout << RESET << "\n---- Additional tests ----" << std::endl;

	MutantStack<std::string> strStack;
	strStack.push("primeiro");
	strStack.push("segundo");
	strStack.push("terceiro");

	std::cout << "Iterating MutantStack<string>:" << std::endl;
	for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "\nReverse Iterator:" << std::endl;
	for (MutantStack<std::string>::reverse_iterator rit = strStack.rbegin(); rit != strStack.rend(); ++rit)
		std::cout << *rit << std::endl;

	std::cout << "\nCompare w/ std::list<int>:" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
		std::cout << *lit << std::endl;

	return 0;
}