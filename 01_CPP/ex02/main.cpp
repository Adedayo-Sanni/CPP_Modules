/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:51:03 by asanni            #+#    #+#             */
/*   Updated: 2024/12/17 17:40:24 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

void f_grande(int *x)
{
	(*x) = *x + 1;
}

void f(int banana)
{
	banana++;
}

void f_ref(int &ref_x)
{
	ref_x++;
}

int main (){
	int *                                x = 42;
	f(x);
	f_ref(x);
	print(x);//2

	
	std::string phrase = "HI THIS IS BRAIN";
	std::string* strPTR = &phrase;
	std::string& strREF = phrase;

	std::cout << &phrase << std::endl; // endereço de mem de phrase
	std::cout << strPTR << std::endl; // o que está dentro de strptr
	std::cout << &strREF << std::endl; //
	std::cout << "*****" << std::endl;
	std::cout << phrase << std::endl; // o valor que está em phrase
	std::cout << *strPTR << std::endl; // o valor para o qual strptr aponta
	std::cout << strREF << std::endl; //
}
