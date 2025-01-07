/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:03:56 by asanni            #+#    #+#             */
/*   Updated: 2025/01/07 19:00:06 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

bool replace(const std::string& filename, const std::string& s1, const std::string& s2){
	if (filename.empty() || s1.empty() || s2.empty()){
		std::cerr << "The program does not work with empty strings" << std::endl;
		return false;
	}
	if (s1.compare(s2) == 0){
		std::cerr << "Why???" << std::endl;
		return false;
	}
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return false;
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open()) {
		std::cerr << "Error: Could not create " << filename << ".replace." << std::endl;
		inputFile.close();
		return false;
	}
	std::string line;
	while (std::getline(inputFile, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outputFile << line << '\n';
	}
	return true;
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cerr << "The program must receive 3 parameters: <filename> <string1> <string2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (!replace(filename, s1, s2))
		return 1;
	std::cout << "Program ended sucessfully" << std::endl;
	return 0;
}
