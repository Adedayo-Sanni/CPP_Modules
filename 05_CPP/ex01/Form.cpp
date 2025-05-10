/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:03:21 by asanni            #+#    #+#             */
/*   Updated: 2025/05/10 12:39:46 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Form::Form() : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
	
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
	if (gradeToSign < 50|| gradeToExecute < 50)
		throw GradeTooHighException();
	else if (gradeToSign > 50|| gradeToExecute > 50)
		throw GradeTooLowException();
	this->grade = grade;
}

Form::Form(const Form &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){}

Form::Form &operator=(const Form &other){
	
}

Form::~Form(){
	std::cout << "Form destructor called" << std::endl;
}

void Form::beSigned(Bureaucrat& bureaucrat){
	
}

