/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:03:21 by asanni            #+#    #+#             */
/*   Updated: 2025/05/10 17:05:59 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default form"), gradeToSign(50), gradeToExecute(100){}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
	if (gradeToSign < 1|| gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150|| gradeToExecute > 150)
		throw GradeTooLowException();
	this->isSigned= false;
}

Form::Form(const Form &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){}

Form& Form::operator=(const Form &other){
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form(){
	std::cout << "Form destructor called" << std::endl;
}

//Getters
const std::string &Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExecute() const {
	return gradeToExecute;
}


//Methods
void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeToSign) {
		throw Form::GradeTooLowException();
	}
	this->isSigned = true;
}

//Exception
const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

std::ostream & operator<<(std::ostream &os, const Form &obj ){
	os << "========================"
	<<"\nForm name: " <<obj.getName()
	<< "\nIs Form signed?: " << (obj.getIsSigned() ? "Yes" : "No") 
	<< "\nGrade to sign: " << obj.getGradeToSign()
	<<"\nGrade to execute: " << obj.getGradeToExecute()
	<< "\n========================";
	return os;
}
