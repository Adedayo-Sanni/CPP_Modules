/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:02:42 by asanni            #+#    #+#             */
/*   Updated: 2025/06/08 18:17:07 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target){}

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
		throw FormNotSignedException();//mudar o retorno
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();

	static bool rand_exist = false;

    // seed the random generator
    if (!rand_exist) {
        std::srand(std::time(0));
        rand_exist = true;
    }
		
	//std::srand(std::time(0));
	if (std::rand() %2 == 0)
	{
		std::cout << "Makes some drilling noises\n.\n.\n.\n.\n.\n" << this->target << " has been robotomized\n" <<std::endl;
	}
	else
		std::cout << "Makes some drilling noises\n.\n.\n.\n.\n.\n" << this->target << " robotomization failed\n" <<std::endl;
}
