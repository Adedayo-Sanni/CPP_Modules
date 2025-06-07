/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:02:42 by asanni            #+#    #+#             */
/*   Updated: 2025/06/07 18:09:26 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("default", 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other) : AForm(other), target(other.target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &other){
	if(this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (this->getIsSigned() == false)
		throw GradeTooLowException();//mudar o retorno
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout << "Makes some drilling noises\n.\n.\n." << this->getName() << "has been robotomized\n" <<std::endl;
}
