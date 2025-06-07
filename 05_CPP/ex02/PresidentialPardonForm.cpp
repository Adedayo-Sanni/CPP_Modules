/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:14:09 by asanni            #+#    #+#             */
/*   Updated: 2025/06/07 18:17:35 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("default", 25, 5), target(target){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other) : AForm(other), target(other.target){}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &other){
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (this->getIsSigned() == false)
		throw GradeTooLowException();//mudar o retorno
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout << this->getName() << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}
