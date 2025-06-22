/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:51:03 by asanni            #+#    #+#             */
/*   Updated: 2025/01/09 19:36:14 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int main (){

	std::string phrase = "HI THIS IS BRAIN";
	std::string* strPTR = &phrase;
	std::string& strREF = phrase;

	std::cout << &phrase << std::endl; // print phrase address
	std::cout << strPTR << std::endl; // print variable that contains the pointer (address of phrase)
	std::cout << &strREF << std::endl; // print the address of the variable that contains the ref
	std::cout << "*****" << std::endl;
	std::cout << phrase << std::endl; // print the phrase
	std::cout << *strPTR << std::endl; //print the content inside the pointer
	std::cout << strREF << std::endl; // print the reference (the phrase itself)
}
