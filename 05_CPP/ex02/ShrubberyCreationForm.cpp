/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:07:20 by asanni            #+#    #+#             */
/*   Updated: 2025/06/07 16:01:56 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("default", 145, 137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other) : AForm(other), target(other.target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other){
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (this->getIsSigned() == false)
		throw GradeTooLowException();//mudar o retorno
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::ofstream file((target + "_shrubbery").c_str());
	if(!file.is_open()){
		std::cout<< "Error: Could not create form " << target << "_shrubbery" << std::endl;
		return;
		file << "       _-_        \n";
		file << "    /~~   ~~\\     \n";
		file << " /~~         ~~\\ \n";
		file << "{               } \n";
		file << " \\  _-     -_  / \n";
		file << "   ~  \\\\ //  ~   \n";
		file << "_- -   | | _- _  \n";
		file << "  _ -  | |   -_  \n";
		file << "       | |       \n";
		file << "      /   \\      \n";
		file.close();
		return false;
}
}
